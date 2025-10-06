#include <stdio.h>
#include <stdbool.h>
#define ARRAY_SIZE 8

typedef bool Set[ARRAY_SIZE];

void initialize(Set set);
void insert(Set set, int element);
void delete(Set set, int element);
bool find(Set set, int element);
void unionSet(Set A, Set B, Set C);
void intersection(Set A, Set B, Set C);
void difference(Set A, Set B, Set C);
void display(Set set);

int main(void){
	
	return 0;
}

void initialize(Set set){
	int i;
	for(i = 0;i < ARRAY_SIZE;i++){
		set[i] = false;
	}
}

void insert(Set set, int element){
	if(element < 0 || element >= ARRAY_SIZE){
		return;
	}
		set[element] = true;
}

void delete(Set set, int element){
		if(element < 0 || element >= ARRAY_SIZE){
		return;
	}
	set[element] = false;
}
bool find(Set set, int element){
	if(element < 0 || element >= ARRAY_SIZE){
		return;
	}
	return set[element];
}

void unionSet(Set A, Set B, Set C){
	for(i = 0;i <ARRAY_SIZE;i++){
		C[i] = A[i] || B[i];
	}
}

void intersection(Set A, Set B, Set C){
	for(i = 0;i <ARRAY_SIZE;i++){
		C[i] = A[i] && B[i];
	}
}

void difference(Set A, Set B, Set C){
		for(i = 0;i <ARRAY_SIZE;i++){
		C[i] = A[i] && !B[i];
	}
}

void display(Set set) {
    printf("{");
    bool first = true;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (set[i]) {
            if (!first) printf(", ");
            printf("%d", i);
            first = false;
        }
    }
    printf("}\n");
}



