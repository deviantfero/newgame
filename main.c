#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./structures.h" //contains structures
#include "./str.h" //contains file reading and string managing
#include "./menulibs.h" //contains all menu related things

struct fighter* create_character();
enemy* create_enemy();
void join_party( struct fighter** cabezcabeza );
void random_battle( struct fighter* cabeza );

/*---File used by the entire program for stats-----*/
FILE* stats_file;
FILE* stats_file_read;

int main( void ){
	stats_file_read = fopen( "./stats.x", "r" );
	if( !stats_file_read ){
		stats_file = fopen( "./stats.x", "w" );
		struct fighter* main_character = create_character();
		status_screen( main_character );
		write_status( stats_file, main_character );
		random_battle( main_character );
		fclose( stats_file );
	}else{
		struct fighter* main_character = load_files( stats_file_read );
		status_screen( main_character );
		random_battle( main_character );
		fclose( stats_file_read );
	}
}

struct fighter* create_character(){
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
}

enemy* create_enemy(){
	int cont;
	enemy* new_enemy = malloc( sizeof( enemy ) );
	FILE* name_file = fopen( "./names.x", "r" );
	int length = get_file_length( name_file ) - 1; //included in str.h
	rewind( name_file );
	srand( time( NULL ) );
	int line = rand()%length + 1;
	//printf( "%d", line ); //file Diagnosis line -- do not remove
	new_enemy->lvl = rand()%10 + 1;
	new_enemy->hp = rand()%( new_enemy->lvl * 2 ) + 1;
	new_enemy->mana = rand()%( new_enemy->lvl * 3 ) + 1;
	for( cont = 1; cont <= line; cont++ ){
		new_enemy->name = fget_line( name_file );
		if( cont == line )
			break;
		else
			free( new_enemy->name );
	}
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
	enemy* challenger1 = create_enemy();
	while( challenger1->hp > 0 ){
		choice = battle_menu();
	}
}