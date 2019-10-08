#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct List{
	int data[MAX_SIZE];
	int nLen;
}s_List;



bool unionList(s_List *l1, s_List *l2){
	//loop each element in l1 and compare it to l2
	int oLen = l2->nLen; 
	for (int i=0; i<l1->nLen; i++){
		int bb = 0;
		for (int j=0;j<oLen; j++){
			if (l1->data[i] ==l2->data[j]){
				bb = 1;
				break;
			}
		}
		if(l2->nLen == MAX_SIZE)
			return false;
		if (bb == 1)
			continue;
		l2->data[l2->nLen] = l1->data[i];
		l2->nLen++;
	}
	return true;
}

void PeekUnion(s_List *l2){
	for(int i = 0; i<l2->nLen; i++)
		printf(" %d ", l2->data[i]);
	printf("\n");
}

int main(){
	s_List l1;
	s_List l2;
	l1.data[0] = 1;
	l1.data[1] = 2;
	l1.data[2] = 3;
	l1.data[3] = 4;
	l1.data[4] = 1;
	l1.nLen = 5;
	l2.data[0] = 1;
	l2.data[1] = 2;
	l2.data[2] = 3;
	l2.data[3] = 4;
	l2.nLen = 4;
	unionList(&l1, &l2);
	PeekUnion(&l2);
}
