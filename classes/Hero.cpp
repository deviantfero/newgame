class Character {
	private:
		std::string name;
		int lvl;
		int hp;
		int mana; //magic points
		int str; //strength for physical attacks
		int wis; //magic attack - or wisdom
		int res; //resistance
		int speed; //defines who goes first in attack step
	public:
		Character( std::string name );
		Character();
		/*the actual hp and other atributes go here
		as those will be the ones that are modified
		by battles, while the otherones will be modified
		by level, as they are the "stats" of the character*/
		//setters and getter for strings
		void setName( std::string name );
		std::string getName();

		void setJob( std::string job );
		std::string getJob();

		//setters and getters for stats
		void setHp( int hp );
		int getHp();
		int getMana();
		void setMana( int mana );
		void setLvl( int lvl );
		int getLvl();
		void setStr( int str );
		int getStr();
		void setWis( int wis );
		int getWis();
		void setRes( int res );
		int getRes();
		void setSpeed( int speed );
		int getSpeed();
		void setExp( int exp );
		int getExp();

		//other methods
		void printStatus();
};

Character::Character( std::string name ) {
	this->name = name;
	this->job = "None";
	/*this is to be moved to the sub classes
	that inherit from this superclass */
	this->hp = 40;
	this->lvl = 5;
	this->exp = 100;
	this->mana = 10;
	this->str = 10;
	this->res = 10;
	this->wis = 10;
	this->speed = 10;
}

Character::Character() {
	this->name = "None";
	this->job = "None";
	/*this is to be moved to the sub classes
	that inherit from this superclass */
	this->hp = 40;
	this->lvl = 5;
	this->exp = 100;
	this->mana = 10;
	this->str = 10;
	this->res = 10;
	this->wis = 10;
	this->speed = 10;
}
