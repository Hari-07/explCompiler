typedef struct Param {
	char* name;
	int type;
	struct Param* next;
}Param;

typedef struct GSymbol {
	char* name;
	int type;
	int size;
	int address;
	int flabel;
	Param* paramlist;
	struct GSymbol* next;
}GSymbol;

typedef struct LSymbol {
	char* name;
	int type;
	int binding;
	struct LSymbol* next;
} LSymbol;

void addGlobalVariable(char* name, int type, int size, int flabel, Param* paramList);
void addLocalVariable (char* name, int type);
Param* createParameter(char *name, int type);
Param* addParameter(Param* next, Param* paramNode);

int checkNameEquivalence(Param* params, char* fname);
void addParamstoLSymbol(Param* param);

struct GSymbol* findGlobalVariable(char* name);
struct LSymbol* findLocalVariable(char* name);
int getVarAddress();
void test();

void terminateFunction();
/*
	Variable Types
	0: Integer
	1: String
*/
