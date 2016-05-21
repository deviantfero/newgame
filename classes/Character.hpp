#include "./Character.cpp"

void Character::setHp( int hp ) {
	this->hp = hp;
}

int Character::getHp() {
	return hp;
}

void Character::setRes( int res ) {
	this->res = res;
}

int Character::getRes() {
	return res;
}

void Character::setLvl( int res ) {
	this->lvl = lvl;
}

int Character::getLvl() {
	return lvl;
}

void Character::setMana( int mana ) {
	this->mana = mana;
}

int Character::getMana() {
	return mana;
}

void Character::setWis( int wis ) {
	this->wis = wis;
}

int Character::getWis() {
	return wis;
}

void Character::setStr( int str ) {
	this->str = str;
}

int Character::getStr() {
	return str;
}

void Character::setSpeed( int speed ) {
	this->speed = speed;
}

int Character::getSpeed() {
	return speed;
}

void Character::setName( std::string name ) {
	this->name = name;
}

std::string Character::getName() {
	return this->name;
}

void Character::printStatus() {
	std::cout << "-- " + this->name + " --" << std::endl;
//	std::cout << "Job: " + this->job << std::endl; this is for the hero subclass
	std::cout << "Lvl: " << this->lvl;
//	std::cout << " | EXP: " << this->aexp << " / " << this->exp << std::endl; this is for the hero subclass
//	std::cout << "HP: " << this->ahp << " / " << this->hp << std::endl;
//	std::cout << "MP: " << this->amana << " / " << this->mana << "\n" << std::endl;
	std::cout << std::setw(15) << std::left << "Strength: " << std::setw(15) << this->str << std::endl;
	std::cout << std::setw(15) << std::left << "Wisdom: " << std::setw(15) << this->wis << std::endl;
	std::cout << std::setw(15) << std::left << "Resistance: " << std::setw(15) << this->res << std::endl;
	std::cout << std::setw(15) << std::left << "Speed: " << std::setw(15) << this->speed << std::endl;
	std::cout << std::endl;
}
