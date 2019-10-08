#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4 
typedef int t_Elmt;
typedef struct ring{
	t_Elmt data[MAX_SIZE];
	int head;
	int rear;
}s_ring;

void initRing(s_ring *rg){
	rg->head = 0;
	rg->rear = 0;
}

bool insertRing(s_ring *rg, t_Elmt e){
	if ((rg->rear + 1)%MAX_SIZE == rg->head){
		printf("end of ring \n");
		return false;
	}
	rg->data[rg->rear] = e;
	//printf("insert %d \n", rg->data[rg->rear]);
	rg->rear = (rg->rear+1)%MAX_SIZE;
	//printf("rear %d \n", rg->rear);
	return true;
}

bool deleteRing(s_ring*rg){
	if(rg->head == rg->rear){
		printf("empty ring \n");
		return false;
	}
	rg->head = (rg->head+1)%MAX_SIZE;
	return true;
}

int getLen(s_ring *rg){
	if (rg->rear >= rg->head)
		return (rg->rear - rg->head);
	else
		return (MAX_SIZE - rg->head + rg->rear);
}
void peekRing(s_ring *rg){
	int len = getLen(rg);
	printf("len is %d \n ", len);
	for(int i=0; i<len; i++)
		printf(" %d ", rg->data[rg->head+i%MAX_SIZE]);
	printf(" \n ");
}

int main(){
	s_ring rg;
	initRing(&rg);
	insertRing(&rg, 1);
	peekRing(&rg);
	insertRing(&rg, 2);
	peekRing(&rg);
	insertRing(&rg, 3);
	peekRing(&rg);
	deleteRing(&rg);
	peekRing(&rg);
	insertRing(&rg, 4);
	peekRing(&rg);
	return 1;
}
