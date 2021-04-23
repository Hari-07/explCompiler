typedef struct TypetableNode {
	char* name;
	int size;
	struct FieldlistNode *fields;
	struct TypetableNode *next;
}TypetableNode;

typedef struct FieldlistNode {
	char* name;
	int fieldIndex;
	struct TypetableNode* type;
	struct FieldlistNode* next;
}FieldlistNode;

void typeTableCreate();

void createTypeTableEntry(char* name);
void addFieldsToTypeTable(char* name, FieldlistNode* fields);
TypetableNode* findTypeTableEntry(char* name);

FieldlistNode* createFieldNode(TypetableNode* type, char*name);
FieldlistNode* addToFieldList(FieldlistNode* fieldNode, FieldlistNode* next);
FieldlistNode* fieldLookup(TypetableNode* type, char* fieldName);
