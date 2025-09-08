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
List deletePos(List L,int position);
List insertSorted(List L,int data);
void display(List L);

int main(void){
	List L;
	
	L = initialize(L);
	L = insertPos(L,20,1);
	L = insertPos(L,99,2);
	L = insertPos(L,33,3);
	
	display(L);
	L = deletePos(L,3);
	display(L);
	L = insertSorted(L,10);
	display(L);
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
	
	return L;
}

List deletePos(List L,int position){
	int i;
	if(L.count == 0){
		printf("Deletion is not possible,Empty List");
		return L;
	}
	else if(position < 1 || position > L.count){
		printf("Deletion is not possible");
		
		return L;
	}
	for(i = position - 1;i < L.count - 1;i++){
		L.elem[i] = L.elem[i + 1];
	}
	L.count--;
	return L;
}

int locate(List L,int data){
	int i;
	for(i = 0;i<L.count;i++){
		if(L.elem[i] == data){
			return i + 1;
		}
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
void display(List L){
	if(L.count == 0){
		printf("List is empty");
		return;
	}
	int i;
	for(i = 0;i < L.count;i++){
		printf("%d ",L.elem[i]);
	}
 printf("\n");	
}
