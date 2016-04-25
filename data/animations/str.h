#define MAX 70

char* getstr(){
	int i;
	char* str = malloc( MAX );
	for( i = 0; i < MAX; i++ ){
		str[i] = getchar();
		if( str[i] == '\n' )
			break;
	}
	str[i] = '\0';
	return str;
}

int get_file_length( FILE* readf ){
	int count = 1;
	while( !feof( readf ) ){
		if( fgetc( readf ) == '\n' )
			count++;
	}
	return count;
}

char* fget_line( FILE* readf ){
	int cont = 0;
	char* string = malloc( sizeof( MAX ) );
	while( !feof( readf ) ){
		string[cont] = fgetc( readf );
		if( cont >= MAX || string[cont] == '\n' ){
			string[cont] = '\0';
			break;
		}
		cont++;
	}
	return string;
}
