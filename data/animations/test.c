#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "./str.h"

int main( int argc, char** argv ){
	char* frame;
	FILE* animation = fopen( argv[1], "r" );
	if( animation == NULL )
		exit(0);
	system( "clear" );
	while( !feof( animation ) ){
		frame = fget_line( animation );
		usleep(100000);
		printf( "%s           \r", frame );
		fflush( stdout );
	}
}
