#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10
//still have to continue this
typedef struct{
    int *elemPtr;
    int count;
    int max;
}List;

void initialize(List* L);
void insertPos(List* L,int data,int position);
void deletePos(List *L,int position);
void display(List *L);

int main(void){
	List L;
	initialize(&L);
	insertPos(&L,10,1);
	insertPos(&L,20,2);
	insertPos(&L,30,3);
	insertPos(&L,69,4);
	display(&L);
    return 0;
}

void initialize(List* L){
    L->elemPtr = (int*)malloc(LENGTH * sizeof(int));
    L->max = LENGTH;
    L->count = 0;
}

void insertPos(List* L,int data,int position){
	if(position < 0 || position > L->count){
		printf("Invalid index");
		}
//	}else if(L->count == L->max){
//		resize(L);
//	}
	int i;
	for(i = L->count;i > position;i--){
		L->elemPtr[i] = L->elemPtr[i - 1];
	}
	L->elemPtr[position] = data;
	L->count++;
}

void deletePos(List *L,int position){
	if(position < 0 || position > L->count){
		printf("Invalid index");
	}
	int i;
	for(i = position;i < L->count;i++){
		L->elemPtr[i] = L->elemPtr[i + 1];
	}
	L->count--;
}

void display(List *L){
	int i;
	for(i = 0;i < L->count;i++){
		printf("%d ",L->elemPtr[i]);
	}
	printf("\n");
}


