
/* -------- Structures definitions --------- */

struct fighter{
	int hp;
	int lvl;
	int mana;
	char* name;
	int str;
	int intel;
	struct fighter* next;
	int exp;
};

typedef struct{
	int hp;
	int lvl;
	int mana;
	char* name;
}enemy; //new data type for enemies

/* ---------------- End here --------------- */
