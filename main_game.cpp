#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <iomanip>
#include "./classes/Character.hpp"

int main( void ) {
	std::vector<Character> party;

	for( int i = 0; i < 4; i++ ) {
		std::string name;
		std::cout << "Input a name: ";
		getline( std::cin, name );
		Character new_character( name );
		party.push_back( new_character );
	}

	std::cout << "\n..Is this ok?..\n" << std::endl;
	for( int i = 0; i < party.size(); i++ ) {
		party[i].printStatus();
	}

}
