/*********************************************
 * In this file all status related functions *
 *********************************************/


void status_screen( struct fighter* cabeza ){
	printf( "----%s-----\n", cabeza->name );
	printf( "Lvl:   %d\n", cabeza->lvl );
	printf( "HP:    %d\n", cabeza->hp );
	printf( "Mana:  %d\n", cabeza->mana );
	printf( "str:   %d\n", cabeza->str );
	printf( "intel: %d\n", cabeza->intel );
	printf( "exp:   %d\n", cabeza->exp );
	printf( "----------------\n" );
	if( cabeza->next )
		status_screen( cabeza->next );
}

void write_status( FILE* stats_file, struct fighter* cabeza ){
	fprintf( stats_file, "%s\n", cabeza->name );
	fprintf( stats_file, "Lvl: %d\n", cabeza->lvl );
	fprintf( stats_file, "HP: %d\n", cabeza->hp );
	fprintf( stats_file, "Mana: %d\n", cabeza->mana );
	fprintf( stats_file, "str: %d\n", cabeza->str );
	fprintf( stats_file, "intel: %d\n", cabeza->intel );
	fprintf( stats_file, "exp: %d\n", cabeza->exp );
	for( int i = 0; i < 4; i++ ){
		fprintf( stats_file, "%d,%s\n%d,%d\n", (cabeza->attack[i].type),
				(cabeza->attack[i].name), (cabeza->attack[i].base_dmg),
				(cabeza->attack[i].mana_need) );
	}
	if( cabeza->next )
		write_status( stats_file, cabeza->next );
	else
		rewind( stats_file );
}

struct fighter* load_files( FILE* stats_file ){
	struct fighter* cabeza = malloc( sizeof( struct fighter ) );
	cabeza->name = fget_line( stats_file );
	fscanf( stats_file, "Lvl: %d\n", &(cabeza->lvl) );
	fscanf( stats_file, "HP: %d\n", &(cabeza->hp) );
	fscanf( stats_file, "Mana: %d\n", &(cabeza->mana) );
	fscanf( stats_file, "str: %d\n", &(cabeza->str) );
	fscanf( stats_file, "intel: %d\n", &(cabeza->intel) );
	fscanf( stats_file, "exp: %d\n", &(cabeza->exp) );
	for( int i = 0; i < 4; i++ ){
		fscanf( stats_file, "%d,%s\n%d,%d", &(cabeza->attack[i].type),
				(cabeza->attack[i].name), &(cabeza->attack[i].base_dmg),
				&(cabeza->attack[i].mana_need) );
	}
	return cabeza;
}

action get_action( FILE* action_file ){
	action new_action;
	fscanf( action_file, "%d,%s\n%d,%d", &(new_action.type),
			(new_action.name), &(new_action.base_dmg),
			&(new_action.mana_need) );
	return new_action;
}

void print_action( struct fighter* cabeza ){
	printf( "\tAttack----------MP\n");
	for( int i = 0; i < 4; i++ )
		printf( "\t%d-%10s |  %d\n", i + 1, cabeza->attack[i].name, cabeza->attack[i].mana_need );
}


int battle_menu( struct fighter* cabeza ){
	int choice = 0;
	while( choice == 0 ){
		printf( "\n\t%s\tHP:  %d%4sMANA:  %d\n\n", cabeza->name,cabeza->hp,"",cabeza->mana );
		printf( "What will you do?\n\t1-Attack\n\t2-Status\n\t9-Flee\n");
		printf( ":" );
		scanf( "%d", &choice );
	}
	return choice;
}

int damage_step( int choice, enemy** challenger, struct fighter** cabeza ){
	srand( time( NULL ) );
	int dmg;
	int random = rand()%(*cabeza)->lvl; //random factor based on level
	dmg = ( (*cabeza)->attack[choice - 1].base_dmg * random ) + 1; 
	if( (*cabeza)->attack[choice - 1].type == (*challenger)->weakness ){
		dmg *= 2;
		printf( "\tDAMN SON! you on fire!\n" );
	}
	if( (*cabeza)->mana < (*cabeza)->attack[choice - 1].mana_need ){
		printf( "\tNot enough mana!\n" );
		return 1;
	}
	if( (*cabeza)->mana >  (*cabeza)->attack[choice - 1].mana_need )
		(*cabeza)->mana -= (*cabeza)->attack[choice - 1].mana_need;
	(*challenger)->hp -= dmg;
	printf( "\t%d - damage!\n", dmg );
	if( (*challenger)->hp > 0 ){
		//starts enemy dmg step
		printf( "%s - Attacks!\n", (*challenger)->name );
		dmg = rand()%(*challenger)->lvl; //random dmg based on enemy lvl
		(*cabeza)->hp -= dmg;
		printf( "\t%d - damage!\n", dmg );
	}//else it doesn't attack, it's ded!
	return 0;
}
