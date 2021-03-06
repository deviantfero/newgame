
/* -------- Structures definitions --------- */
#define ACTION_MAX 5

typedef enum{ NONE, FIRE, ICE, WATER, WIND, PHYSICAL }attribute;

typedef struct{
	attribute type;
	char name[10];
	int base_dmg; //this can be negative in case of a healing action
	int mana_need;
}action;

struct fighter{
	int hp;
	int max_hp;
	int lvl;
	int mana;
	int max_mana;
	char* name;
	int str;
	int intel;
	struct fighter* next;
	int exp;
	int max_exp;
	int target;
	action attack[ACTION_MAX];
};

typedef struct{
	int hp;
	int lvl;
	int mana;
	int target;
	char* name;
	attribute weakness;
}enemy; //new data type for enemies


/* ---------------- End here --------------- */
