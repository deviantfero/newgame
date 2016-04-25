#include "./Hero.cpp"

void Hero::setHp( int hp ) {
	this->hp = hp;
}

int Hero::getHp() {
	return hp;
}

void Hero::setRes( int res ) {
	this->res = res;
}

int Hero::getRes() {
	return res;
}

void Hero::setLvl( int res ) {
	this->lvl = lvl;
}

int Hero::getLvl() {
	return lvl;
}

void Hero::setMana( int mana ) {
	this->mana = mana;
}

int Hero::getMana() {
	return mana;
}

void Hero::setWis( int wis ) {
	this->wis = wis;
}

int Hero::getWis() {
	return wis;
}

void Hero::setStr( int str ) {
	this->str = str;
}

int Hero::getStr() {
	return str;
}

void Hero::setSpeed( int speed ) {
	this->speed = speed;
}

int Hero::getSpeed() {
	return speed;
}

void Hero::setName( std::string name ) {
	this->name = name;
}

std::string Hero::getName() {
	return this->name;
}

void Hero::setJob( std::string job ) {
	this->job = job;
}

std::string Hero::getJob() {
	return this->job;
}

void Hero::setExp( int exp ) {
	this->exp = exp;
}

int Hero::getExp() {
	return this->exp;
}

void Hero::printStatus() {
	std::cout << "-- " + this->name + " --" << std::endl;
	std::cout << "Job: " + this->job << std::endl;
	std::cout << "Lvl: " << this->lvl;
	std::cout << " | EXP: " << this->aexp << " / " << this->exp << std::endl;
	std::cout << "HP: " << this->ahp << " / " << this->hp << std::endl;
	std::cout << "MP: " << this->amana << " / " << this->mana << "\n" << std::endl;
	std::cout << std::setw(15) << std::left << "Strength: " << std::setw(15) << this->str << std::endl;
	std::cout << std::setw(15) << std::left << "Wisdom: " << std::setw(15) << this->wis << std::endl;
	std::cout << std::setw(15) << std::left << "Resistance: " << std::setw(15) << this->res << std::endl;
	std::cout << std::setw(15) << std::left << "Speed: " << std::setw(15) << this->speed << std::endl;
	std::cout << std::endl;
}
