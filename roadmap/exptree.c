#include<stdlib.h>

tnode* makeLeafNode(int n)
{
	tnode *temp;
	temp = (tnode*)malloc(sizeof(tnode));
	temp -> val 	= n;
	temp -> left	= NULL;
	temp -> right 	= NULL;
	return temp;
}

tnode* makeOperatorNode(char c, tnode* l, tnode* r) {
	tnode* temp;
	temp = (tnode*)malloc(sizeof(tnode));
	temp -> op = c;
	temp -> left = l;
	temp -> right = r;
	return temp;
}

void printTree(tnode* root){
	if(root) {
		printTree(root->left);
		
		if(root->op)
			printf("%c", root->op);
		else
			printf("%d", root->val);

		printTree(root->right);
	}
}

void printPreOrder(tnode* root){
	if(root) {
		
		if(root->op)
			printf("%c", root->op);
		else
			printf("%d", root->val);

		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}

void printPostOrder(tnode* root){
	if(root) {
		printPostOrder(root->left);
		printPostOrder(root->right);
		
		if(root->op)
			printf("%c", root->op);
		else
			printf("%d", root->val);

	}
}