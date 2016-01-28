/*********************************************
 * In this file all status related functions *
 *********************************************/


void status_screen( struct fighter* cabeza ){
	printf( "----%s-----\n", cabeza->name );
	printf( "Lvl:   %d\n", cabeza->lvl );
	printf( "HP:    %d/%d\n", cabeza->hp, cabeza->max_hp );
	printf( "Mana:  %d/%d\n", cabeza->mana, cabeza->max_mana );
	printf( "str:   %d\n", cabeza->str );
	printf( "intel: %d\n", cabeza->intel );
	printf( "exp:   %d/%d\n", cabeza->exp, cabeza->max_exp );
	printf( "----------------\n" );
	if( cabeza->next )
		status_screen( cabeza->next );
}

void write_status( FILE* stats_file, struct fighter* cabeza ){
	fprintf( stats_file, "%s\n", cabeza->name );
	fprintf( stats_file, "Lvl: %d\n", cabeza->lvl );
	fprintf( stats_file, "HP: %d\n", cabeza->max_hp );
	fprintf( stats_file, "Mana: %d\n", cabeza->max_mana );
	fprintf( stats_file, "str: %d\n", cabeza->str );
	fprintf( stats_file, "intel: %d\n", cabeza->intel );
	fprintf( stats_file, "exp: %d\n", cabeza->exp );
	fprintf( stats_file, "max_exp: %d\n", cabeza->max_exp );
	for( int i = 0; i < ACTION_MAX; i++ ){
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
	fscanf( stats_file, "HP: %d\n", &(cabeza->max_hp) );
	fscanf( stats_file, "Mana: %d\n", &(cabeza->max_mana) );
	fscanf( stats_file, "str: %d\n", &(cabeza->str) );
	fscanf( stats_file, "intel: %d\n", &(cabeza->intel) );
	fscanf( stats_file, "exp: %d\n", &(cabeza->exp) );
	fscanf( stats_file, "max_exp: %d\n", &(cabeza->max_exp) );
	for( int i = 0; i < ACTION_MAX; i++ ){
		fscanf( stats_file, "%d,%s\n%d,%d", &(cabeza->attack[i].type),
				(cabeza->attack[i].name), &(cabeza->attack[i].base_dmg),
				&(cabeza->attack[i].mana_need) );
	}
	cabeza->hp = cabeza->max_hp;
	cabeza->mana = cabeza->max_mana;
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
	for( int i = 0; i < ACTION_MAX; i++ )
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

int target_choice( struct fighter** cabeza, enemy** challenger ){
	static int i = 0;
	static struct fighter* prev_cab = NULL;
	int target;
	printf("\n");
	if( *cabeza != prev_cab ){
		printf( "\t%d.%-5s\n", i + 1, (*cabeza)->name );
		(*cabeza)->target = i + 1;
		i++;
	}
	if( (*cabeza)->next ){
		prev_cab = *cabeza;
		target_choice( &(*cabeza)->next, challenger );
	}
	else{
		printf( "\t%d.%-5s\n", i + 1, (*challenger)->name );
		(*challenger)->target = i + 1;
	}
	printf( "Who are you going to attack?: " );
	scanf( "%d", &target );
	i = 0;
	return target;
}

int damage_step( int choice, enemy** challenger, struct fighter** cabeza ){
	srand( time( NULL ) );
	int dmg, target;
	int random = rand()%(*cabeza)->attack[choice - 1].base_dmg; //random factor based on level
	dmg = ( (*cabeza)->str * random/2 ) + 2; 
	if( choice == 5 )
		dmg = -dmg;
	if( (*cabeza)->mana < (*cabeza)->attack[choice - 1].mana_need ){
		printf( "\tNot enough mana!\n" );
		return 1;
	}
	target = target_choice( cabeza, challenger );
	if( target == (*challenger)->target ){
		if( (*cabeza)->attack[choice - 1].type == (*challenger)->weakness ){
			dmg *= 2;
			printf( "\tDAMN SON! you on fire!\n" );
		}
		if( (*cabeza)->mana >  (*cabeza)->attack[choice - 1].mana_need )
			(*cabeza)->mana -= (*cabeza)->attack[choice - 1].mana_need;
		(*challenger)->hp -= dmg;
	}else if( !(*cabeza)->next && (*cabeza)->target == target ){
		if( (*cabeza)->mana >  (*cabeza)->attack[choice - 1].mana_need )
			(*cabeza)->mana -= (*cabeza)->attack[choice - 1].mana_need;
		(*cabeza)->hp -= dmg;
	}else{
		printf( "Still not implemented" );
	}
	printf( "\t%d - damage!\n", dmg );
	if( (*challenger)->hp > 0 ){
		//starts enemy dmg step
		printf( "%s - Attacks!\n", (*challenger)->name );
		dmg = rand()%(*cabeza)->lvl; //random dmg based on enemy lvl
		(*cabeza)->hp -= dmg * 2;
		printf( "\t%d - damage!\n", dmg );
	}//else it doesn't attack, it's ded!
	return 0;
}

void level_up( struct fighter* cabeza ) {
	if( cabeza->exp >= cabeza->max_exp ) {
		cabeza->exp = cabeza->exp - cabeza->max_exp; 
		cabeza->lvl += 1;
		cabeza->max_exp += cabeza->lvl * ( rand()%5 + 1 );
		cabeza->str += 2;
		cabeza->max_hp += 2;
		cabeza->max_mana += 2;
		cabeza->intel += 2;
	}
	if( cabeza->next )
		level_up( cabeza->next );
}
