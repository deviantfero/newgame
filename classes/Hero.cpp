class Hero {
	private:
		std::string name;
		std::string job;
		int lvl;
		int exp;
		int hp;
		int mana; //magic points
		int str; //strength for physical attacks
		int wis; //magic attack - or wisdom
		int res; //resistance
		int speed; //defines who goes first in attack step
	public:
		Hero( std::string name );
		Hero();
		/*the actual hp and other atributes go here
		as those will be the ones that are modified
		by battles, while the otherones will be modified
		by level, as they are the "stats" of the character*/
		int ahp;
		int amana;
		int aexp;
		int astr;
		int awis;
		int ares;
		int aspeed;

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

Hero::Hero( std::string name ) {
	this->name = name;
	this->job = "None";
	this->hp = 40;
	this->lvl = 5;
	this->exp = 100;
	this->mana = 10;
	this->str = 10;
	this->res = 10;
	this->wis = 10;
	this->speed = 10;

	this->ahp = this->hp;
	this->amana = this->mana;
	this->aexp = 0;
	this->astr = this->str;
	this->ares = this->res;
	this->aspeed = this->speed;
	this->awis = this->wis;
}

Hero::Hero() {
	this->name = "None";
	this->job = "None";
	this->hp = 40;
	this->lvl = 5;
	this->exp = 100;
	this->mana = 10;
	this->str = 10;
	this->res = 10;
	this->wis = 10;
	this->speed = 10;
	this->ahp = this->hp;
	this->amana = this->mana;
	this->aexp = 0;
	this->astr = this->str;
	this->ares = this->res;
	this->aspeed = this->speed;
	this->awis = this->wis;
}
