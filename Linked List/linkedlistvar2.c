#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct{
    Node *head;
    int count;
}List;

List* initialize();
void empty(List *list);
void insertFirst(List *list,int data);
void insertLast(List *list,int data);
void insertPos(List *list,int data,int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list,int index);
int retrieve(List *list, int index);
int locate(List *list,int data);
void display(List *list);

int main(void){
    List *L = initialize();
	
    insertFirst(L,20);
    insertFirst(L,69);
    display(L);
    insertLast(L,25);
    insertLast(L,37);
    display(L);
    return 0;
}

List* initialize(){
    List *list = (List*)malloc(sizeof(List));
    if(list == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }
    list->head = NULL;
    list->count = 0;
    return list;
}

void empty(List *list){
    if(list == NULL) return;
    Node *cur = list->head;
    while(cur != NULL){
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    list->head = NULL;
    list->count = 0;
}

void insertFirst(List *list,int data){
    if(list == NULL) return;
    Node *newNode =(Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

void insertLast(List *list,int data){
    if(list == NULL) return;
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if(list->head == NULL){
        list->head = newNode;
    } else {
        Node *cur = list->head;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = newNode;
    }
    list->count++;
}

void insertPos(List *list,int data,int index){
    if(index > list->count || index < 0){
        printf("INVALID POSITION\n");
        return;
    }
    if(index == 0){
        insertFirst(list,data);
        return;
    }
    if(index == list->count){
        insertLast(list,data);
        return;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    Node *current = list->head;
    int i;
    for(i = 0; i < index - 1; i++){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    list->count++;
}

void deleteStart(List *list){
    if(list == NULL || list->head == NULL){
        printf("List is empty\n");
        return;
    }
    Node *current = list->head;
    list->head = list->head->next;
    free(current);
    list->count--;
} 

void deleteLast(List *list){
    if(list == NULL || list->head == NULL){
        printf("List is empty\n");
        return;
    }
    if(list->head->next == NULL){
        free(list->head);
        list->head = NULL;
    } else {
        Node* current = list->head;
        while(current->next->next != NULL){
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
    list->count--;
}

void deletePos(List *list,int index){
    if(list == NULL) return;
    if(index < 0 || index >= list->count){
        printf("Invalid index!\n");
        return;
    }
    if(index == 0){
        deleteStart(list);
        return;
    }
    Node *current = list->head;
    int i;
    for(i = 0; i < index - 1; i++){
        current = current->next;
    }
    Node *delNode = current->next;
    current->next = delNode->next;
    free(delNode);
    list->count--;
}

int retrieve(List *list, int index){
    if(index < 0 || index >= list->count){
        printf("Invalid index\n");
        return -1;
    }
    Node* current = list->head;
    int i;
    for(i = 0; i < index; i++){
        current = current->next;
    }
    return current->data;
}

int locate(List *list,int data){
    if(list == NULL) return -1;
    Node *current = list->head;
    int index = 0;
    while(current != NULL){
        if(current->data == data){
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

void display(List *list){
    if (list == NULL){
        printf("List pointer is NULL\n");
        return;
    }
    if (list->head == NULL){
        printf("List is empty\n");
        return;
    }
    Node *current = list->head;
    while(current != NULL){
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

