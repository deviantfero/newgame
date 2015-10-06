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
	return cabeza;
}

int battle_menu(){
	int choice = 0;
	while( choice == 0 ){
		printf( "What will you do?\n1-Attack\n2-Flee\n" );
		scanf( "%d", &choice );
	}
	return choice;
}
