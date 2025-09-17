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
List insertSorted(List L,int data);
List deletePos(List L,int position);
int locate(List L, int data);
void display(List L);
List resize(List L);

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

    printf("\nInsert Sorted:\n");
    L = insertSorted(L,20);
    L = insertSorted(L,35);
    display(L);

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
        return L;
    }
    if(L.count == L.max){
        L = resize(L);
    }
    for(int i = L.count; i > position; i--){
        L.elemPtr[i] = L.elemPtr[i - 1];
    }
    L.elemPtr[position] = data;
    L.count++;
    return L;
}

List insertSorted(List L,int data){
    if(L.count == L.max){
        L = resize(L);
    }
    int pos = 0;
    while(pos < L.count && L.elemPtr[pos] < data){
        pos++;
    }
    for(int i = L.count; i > pos; i--){
        L.elemPtr[i] = L.elemPtr[i - 1];
    }
    L.elemPtr[pos] = data;
    L.count++;
    return L;
}

List deletePos(List L,int position){
    if(position < 0 || position >= L.count){
        printf("INVALID INDEX");
        return L;
    }
    for(int i = position; i < L.count - 1; i++){
        L.elemPtr[i] = L.elemPtr[i + 1];
    }
    L.count--;
    return L;
}

int locate(List L, int data){
    for(int i = 0; i < L.count; i++){
        if(data == L.elemPtr[i]){
            return i + 1;
        }
    }
    return -1;
}

void display(List L){
    for(int i = 0; i < L.count; i++){
        printf("%d ",L.elemPtr[i]); 
    }
    printf("\n");
}

List resize(List L){
    int newMax = L.max * 2;
    int *newArr = (int*)malloc(newMax * sizeof(int));
    for(int i = 0; i < L.count; i++){
        newArr[i] = L.elemPtr[i];
    }
    free(L.elemPtr);
    L.elemPtr = newArr;
    L.max = newMax;
    return L;
}

