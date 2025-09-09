#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
	int *elemPtr;
	int count;
	int max;
}List;

List initialize();
List insertPos(List L,int data,int position);
List deletePos(List L,int position);
int locate(List L, int data);
void display(List L);

int main(void){
	
	List L = initialize();
	printf("List:\n");
	L = insertPos(L,10,0);
	L = insertPos(L,30,1);
	L = insertPos(L,40,2);
	display(L);
	printf("\nDeleted list:\n");
	L = deletePos(L,1);
	display(L);
	int pos = locate(L,40);
	printf("\nlocated data:\n%d\n",pos);

	return 0;
}

List initialize(){
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
		//L = resize(L);
	}
	int i;
	for(i = L.count;i > position;i--){
		L.elemPtr[i] = L.elemPtr[i - 1];
	}
	L.elemPtr[position] = data;
	L.count++;
	return L;
}

List deletePos(List L,int position){
	if(position < 0 || position > L.count){
		printf("INVALID INDEX");
	}
	int i;
	for(i = position;i < L.count - 1;i++){
		L.elemPtr[i] = L.elemPtr[i + 1];
	}
	L.count--;
	return L;
}

int locate(List L, int data){
	int i;
	for(i = 0;i < L.count;i++){
		if(data == L.elemPtr[i]){
			return i + 1;
		}	
	}
	return -1;
}

void display(List L){
	int i;
	for(i = 0;i < L.count;i++){
		printf("%d ",L.elemPtr[i]); 
	}
}

