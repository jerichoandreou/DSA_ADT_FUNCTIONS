#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
	int elem[MAX];
	int count;
}Etype, *EPtr;

void initialize(EPtr L);
void insertPos(Eptr L,int data,int position);

int main(void){
	EPtr L;
	L = (EPtr)malloc(sizeof(Etype));
	
	L = initialize(EPtr L);
	L = insertPos(EPtr L,10,1);
	L = insertPos(EPtr L,20,2);
	L = insertPos(EPtr L,30,3);	
	
	return 0;
}

void initialize(EPtr L){
	EPtr->count = 0;

	return L;
}
//position is 1 based count is 0
void insertPos(Eptr L,int data,int position){
	if(L->count == MAX{
		printf("LIST IS FULL");
	}
	else if(position < 1 || position <= L->count + 1){
		printf("INVALID POSITION");
	}
	int i;
	for(i = L->count;i >= position;i--){
		L->elem[i] = L->elem[i - 1];
	}
	L->elem[i - 1] = data;
	L->count++;
}
