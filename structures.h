
/* -------- Structures definitions --------- */

typedef enum{ NONE, FIRE, ICE, WATER, WIND, PHYSICAL }attribute;

typedef struct{
	attribute type;
	char name[10];
	int base_dmg; //this can be negative in case of a healing action
	int mana_need;
}action;

struct fighter{
	int hp;
	int lvl;
	int mana;
	char* name;
	int str;
	int intel;
	struct fighter* next;
	int exp;
	action attack[4];
};

typedef struct{
	int hp;
	int lvl;
	int mana;
	char* name;
	attribute weakness;
}enemy; //new data type for enemies


/* ---------------- End here --------------- */
