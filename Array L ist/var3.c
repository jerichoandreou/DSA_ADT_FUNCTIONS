#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
	int *elemPtr;
	int count;
	int max;
}List;

List initialize(List L);
List insertPos(List L,int data,int position);
int main(void){
	
	List L = initialize(L);
	insertPos(L,10,1);
		
	return 0;
}

List initialize(List L){
	List L;
	L.elemPtr = (int*)malloc(LENGTH * sizeof(int));
	L.max = LENGTH;
	L.count = 0;
	
	return L;
}

List insertPos(List L,int data,int position){
	if(position < 0 || position > L.count){
		printf("INVALID INDEX");
	}
	if(L.count == L.max){
		L = resize(L);
	}
	int i;
	for(i = position;i > L.count;i--){
		L.elemPtr[i] = L.elemPtr[i - 1];
	}
	L.elemPtr[position] = data;
	L.count++;
	return L;
}
