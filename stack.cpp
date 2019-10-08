#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef struct stack{
	int data[MAX_SIZE];
	int top;
}s_stack;
typedef int t_Elmt;

bool Push(s_stack *st, t_Elmt e){
	if (st->top == MAX_SIZE-1)
		return false;
	st->data[st->top+1] = e;
	st->top++;
	return 1;
}

bool Pop(s_stack *st, t_Elmt *e){
	if(st->top == -1)
		return false;
	*e = st->data[st->top];
	st->top--;
	return true;
}


void PrintSt(s_stack*st){
	for (int i = 0; i<=st->top; i++)
		printf("%d ",st->data[i]);
	printf("\n");
}
int main(){
	s_stack st;
	st.data[0] = 1;
	st.data[1] = 2;
	st.top =1;
	Push(&st, 100);
	PrintSt(&st);
	int e = 0;
	Pop(&st, &e);
	printf("%d ", e);
	Pop(&st, &e);
	printf("%d ", e);
}
