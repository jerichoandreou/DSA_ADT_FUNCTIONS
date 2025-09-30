#include <stdio.h>
#include <stdbool.h>
typedef unsigned char set8;

void initialize(set8 *set);
void insert(set8 *set, int element);
void deleteSet(set8 *set, int element);
bool findSet(set8 set, int element);
unsigned char unionSet(set8 A,set8 B);
unsigned char intersection(set8 A, set8 B);
unsigned char difference(set8 A, set8 B);
void display(set8 set);

int main(void){
    set8 A,B,C;
    
    initialize(&A);
    printf("Set A:\n");
    insert(&A,1);
    insert(&A,6);
    insert(&A,3);
    display(A);
    deleteSet(&A,3);
    display(A);
    
    return 0;
}

void initialize(set8 *set){
    *set = 0;
}

void insert(set8 *set, int element){
    if(element > 7 || element < 0){
        return;
    }
    *set |= (1 << element);
}

void deleteSet(set8 *set, int element){
        if(element > 7 || element < 0){
        return;
    }
    *set &= ~(1 << element);
}

bool findSet(set8 set,int element){
	if((set & (1 << element != 0))){
		return 1;
	}else{
		return 0;
	}
}

set8 unionSet(set8 A,set8 B){
	return A | B;
}

set8 intersection(set8 A,set8 B){
	return A & B;
}

void display(set8 set){
    int first = 1;
    int i;
    for(i = 0;i <= 7;i++){
        if(set & (1 << i)){
            printf("%d ", i);
        }
    }
    printf("\n");
}

