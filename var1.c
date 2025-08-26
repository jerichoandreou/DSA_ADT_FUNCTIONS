#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
	int elem[MAX];
	int count;
}List;

List initialize(List L);
List insertPos(List L,int data,int position);
int locate(List L,int data);
int main(void){
	List L;
	
	L = initialize(L);
	L = insertPos(L,20,1);
	L = insertPos(L,99,2);
	L = insertPos(L,33,3);
	L = deletePos(L,3);
	locate(L,99);
	return 0;
}

List initialize(List L){
	L.count = 0;
	return L;
}

List insertPos(List L,int data,int position){
	int i;
	if(L.count == MAX){
		printf("List is full");
	}
	else if(position < 1 || position > MAX){
		printf("Invalid position");
	}
	
	for(i = L.count;i >= position;i--){
		L.elem[i] = L.elem[i-1];
	}
	
	L.elem[position - 1] = data;
	L.count++;
}

List deletePos(List L,int position){
	int i;
	if(L.count == NULL){
		printf("Deletion is not possible");
	}
	else if(position < 1 || position > L.count){
		prinf("Deletion is not possible");
	}
	for(i = position - 1;i < L.count - 1;i++){
		L.elem[i] = L.elem[i + 1];
	}
	L.count--;
}

int locate(List L,int data){
	int i;
	for(i = 0;i<L.count;i++){
		if(L.elem[i] == data);
		return i + 1;
	}
	return -1;
}

List insertSorted(List L,int data){
	int pos = 0;
	int i;
	if(L.count == MAX){
		printf("List is full");
		return L;
	}
	
	while(pos < L.count && L.elem[pos] < data){
		pos++;
	}
	
	for(i = L.count;i > pos;i--){
		L.elem[i] = L.elem[i-1];
	}
	L.elem[pos] = data;
	L.count++;
	
	return L;
}
