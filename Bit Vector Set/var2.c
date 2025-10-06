#include <stdio.h>
#include <stdbool.h>

typedef struct{
	unsigned int field: 8;
} Set;

void initialize(Set *s);
void insert(Set *s, int element);
void deleteElement(Set *s, int element);
bool find(Set s, int element);
Set unionSet(Set A, Set B);
Set intersection(Set A, Set B);
Set difference(Set A, Set B);
void display(Set s);

int main(void){
	Set A,B,C;
	initialize(&A);
	printf("Set A:\n");
	insert(&A,1);
	insert(&A,2);
	insert(&A,3);
	insert(&A,4);
	insert(&A,5);
	display(A);
	printf("\n");
	deleteElement(&A,5);
	display(A);
	
	return 0;
}

void initialize(Set *s){
	s->field = 0;
}

void insert(Set *s, int element){
	if(element < 0 || element > 7){
		return;
	}
	s->field |= (1 << element);
}

void deleteElement(Set *s, int element){
	if(element < 0 || element > 7){
		return;
	}
	s->field &= (~(1 << element));
}
bool find(Set s, int element){
	if(element < 0 || element > 7){
		return false;
	}
	return ((s.field &(1 << element))!= 0);
}

Set unionSet(Set A, Set B){
	Set C;
	
	C.field = A.field | B.field;
	return C;
}

Set intersection(Set A, Set B){
	Set C;
	
	C.field = A.field & B.field;
	return C;
}

Set difference(Set A, Set B){
	Set C;
	
	C.field = A.field & ~B.field;
	return C;
}

void display(Set s){
	int i;
		for(i = 0;i <= 7;i++){
			if (s.field & (1 << i)){
				printf("%d ",i);
			}
		}
}

