#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <iomanip>
#include "./classes/Hero.hpp"

int main( void ) {
	std::vector<Hero> party;

	for( int i = 0; i < 4; i++ ) {
		std::string name;
		std::cout << "Input a name: ";
		getline( std::cin, name );
		Hero new_hero( name );
		party.push_back( new_hero );
	}

	std::cout << "\n..Is this ok?..\n" << std::endl;
	for( int i = 0; i < party.size(); i++ ) {
		party[i].printStatus();
	}

}
