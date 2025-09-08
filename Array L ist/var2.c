#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;

EPtr initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void display(EPtr L);
void insertSorted(EPtr L, int data);
void makeNull(EPtr L);

int main(void) {
    EPtr L;
    L = (EPtr)malloc(sizeof(Etype));

    L = initialize(L);

    insertPos(L, 10, 1);
    insertPos(L, 20, 2);
    insertPos(L, 30, 3);

    display(L);

    deletePos(L, 2);
    display(L);

    printf("Retrieve position 2: %d\n", retrieve(L, 2));
    printf("Locate 30: %d\n", locate(L, 30));
	insertPos(L,20,2);
	insertSorted(L,69);
	display(L);
    makeNull(L);
    return 0;
}

EPtr initialize(EPtr L) {
    L->count = 0;
    return L;
}

void insertPos(EPtr L, int data, int position) {
    int i;
    if (L->count == MAX) {
        printf("LIST IS FULL\n");
        return;
    } else if (position < 1 || position > L->count + 1) {
        printf("INVALID POSITION\n");
        return;
    }
    for (i = L->count; i >= position; i--) {
        L->elem[i] = L->elem[i - 1];
    }
    L->elem[position - 1] = data;
    L->count++;
}

void deletePos(EPtr L, int position) {
    int i;
    if (position < 1 || position > L->count) {
        printf("INVALID POSITION\n");
        return;
    }
    for (i = position - 1; i < L->count - 1; i++) {
        L->elem[i] = L->elem[i + 1];
    }
    L->count--;
}

int locate(EPtr L, int data) {
    int i;
    for (i = 0; i < L->count; i++) {
        if (L->elem[i] == data) {
            return i + 1;  // return position (1-based)
        }
    }
    return -1;
}

int retrieve(EPtr L, int position) {
    if (L->count < 1) {
        printf("LIST IS EMPTY\n");
        return -1;
    } else if (position > L->count || position < 1) {
        printf("INVALID POSITION\n");
        return -1;
    }
    return L->elem[position - 1];
}

void insertSorted(EPtr L, int data){
	if(L->count == MAX){
		printf("List is full");
	}
	int i;
	int pos = 0;
		while(pos < L->count && L->elem[pos] < data){
			pos++;
		}
		for(i = L->count;i > pos;i--){
		L->elem[i] = L->elem[i - 1]; 
	}
	L->elem[pos] = data;
	L->count++;
	}


void display(EPtr L) {
    int i;
    if (L->count == 0) {
        printf("LIST IS EMPTY\n");
        return;
    }
    for (i = 0; i < L->count; i++) {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

void makeNull(EPtr L){
	free(L);
}


