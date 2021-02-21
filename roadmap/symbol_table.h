typedef struct GSymbol {
	char* name;
	int type;
	int size;
	int address;
	struct GSymbol* next;
}GSymbol;

void addVariable(char* name, int type, int size);
struct GSymbol* findVariable(char* name);
int getVarAddress();


/*
	Variable Types
	0: Integer
	1: String
*/
