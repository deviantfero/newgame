#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "./structures.h" //contains structures
#include "./str.h" //contains file reading and string managing
#include "./menulibs.h" //contains all menu related things

struct fighter* create_character();
enemy* create_enemy( int lvl );
void join_party( struct fighter** cabezcabeza );
void random_battle( struct fighter* cabeza );

/*---File used by the entire program for stats-----*/
FILE* stats_file;
FILE* stats_file_read;

int main( void ){
	stats_file_read = fopen( "./data/stats.x", "r" );
	if( !stats_file_read ){
		stats_file = fopen( "./data/stats.x", "w" );
		struct fighter* main_character = create_character();
		status_screen( main_character );
		write_status( stats_file, main_character );
		random_battle( main_character );
		write_status( stats_file, main_character );
		fclose( stats_file );
	}else{
		struct fighter* main_character = load_files( stats_file_read );
		fclose( stats_file_read );
		stats_file = fopen( "./data/stats.x", "w" );
		status_screen( main_character );
		random_battle( main_character );
		write_status( stats_file, main_character );
		fclose( stats_file_read );
	}
}

struct fighter* create_character(){
	struct fighter* new_character = malloc( sizeof( struct fighter ) );
	FILE* action_file = fopen( "./data/abilities.x", "r" );
	new_character->exp = 0;
	new_character->max_exp = 100;
	new_character->lvl = 5;
	new_character->max_hp = 5 * new_character->lvl;
	new_character->max_mana = 3 * new_character->lvl;
	new_character->hp = new_character->max_hp;
	new_character->mana = new_character->max_mana;
	printf( "Name your Character: " );
	new_character->name = getstr();
	new_character->str = new_character->lvl;
	new_character->intel = new_character->lvl;
	for( int i = 0; i < ACTION_MAX; i++ ){
		new_character->attack[i] = get_action( action_file );
	}
	new_character->next = NULL;
	fclose( action_file );
	return new_character;
}

enemy* create_enemy( int lvl ){
	int cont;
	enemy* new_enemy = malloc( sizeof( enemy ) );
	FILE* name_file = fopen( "./data/enemies.x", "r" );
	int length = get_file_length( name_file ) - 1; //included in str.h
	rewind( name_file );
	srand( time( NULL ) );
	int line = rand()%length + 1;
	//printf( "%d", line ); //file Diagnosis line -- do not remove
	new_enemy->lvl = rand()%lvl + lvl; //will be adaptable to hero's lvl
	new_enemy->hp = rand()%( new_enemy->lvl * 5 ) + 10;
	new_enemy->mana = rand()%( new_enemy->lvl * 3 ) + 10;
	for( cont = 1; cont <= line; cont++ ){
		new_enemy->name = fget_line( name_file );
		if( cont == line )
			break;
		else
			free( new_enemy->name );
	}
	new_enemy->weakness = rand()%6;
	return new_enemy;
}

void join_party( struct fighter** cabeza ){
	if( !(*cabeza)->next ){
		struct fighter* new_character = malloc( sizeof( struct fighter ) );
		new_character->exp = 0;
		new_character->lvl = 5;
		new_character->hp = 3 * new_character->lvl;
		new_character->mana = 2 * new_character->lvl;
		printf( "Name your Character: " );
		new_character->name = getstr();
		new_character->str = new_character->lvl;
		new_character->intel = new_character->lvl;
		new_character->next = NULL;
		(*cabeza)->next = new_character;
	}else
		join_party( &((*cabeza)->next) );
}

void random_battle( struct fighter* cabeza ){
	int choice;
	enemy* challenger1 = create_enemy( cabeza->lvl );
	while( cabeza->hp > 0 && challenger1->hp > 0 ){
		sleep( 1 );
		system( "clear" ); //for POSIX
		printf( "\tEnemy:  %s%5sHP: %d\n", challenger1->name, "", challenger1->hp );
		choice = battle_menu( cabeza );
		switch( choice ){
			case 1:
				print_action( cabeza );
				printf(":");
				scanf( "%d", &choice );
				damage_step( choice, &challenger1, &cabeza );
				break;
			case 9:
				printf( "\tYou ran like a pussy\n" );
				exit(0);
			case 2:
				status_screen( cabeza );
				getchar();
				break;
			default:
				printf( "\tWrong option! enter a new one\n" );
		}
	}
	if( cabeza->hp < 0 )
		printf( "You lost!\n" );
	else{
		printf( "You Won!\n" );
		cabeza->exp += challenger1->lvl * (rand()%50 + 1);
		while( cabeza->exp >= cabeza->max_exp )
			level_up( cabeza );
		status_screen( cabeza );
	}
}
