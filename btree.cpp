#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

typedef struct bNode{
	bNode *lchild;
	bNode *rchild;
	char data;
}s_bNode;


void createBiTree(s_bNode **pTree){
	char e;
	std::cout << "input your data:";
	std::cin >>e;
	if(e=='#')
		*pTree = NULL;
	else{
		*pTree = (s_bNode*)malloc(sizeof(s_bNode));
		(*pTree)->data = e;
		createBiTree(&((*pTree)->lchild));
		createBiTree(&((*pTree)->rchild));
	}
}

void travelBiTree(s_bNode *pTree){
	if(pTree == NULL)
		return;
	printf("%c ", pTree->data);
	travelBiTree(pTree->lchild);
	travelBiTree(pTree->rchild);
}

int main(){
	s_bNode *pTree=NULL;
	createBiTree(&pTree);
	travelBiTree(pTree);
	return 1;
}
