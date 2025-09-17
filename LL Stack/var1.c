#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;
typedef struct Stack{
    Node* top;
}Stack;

Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack *s,int value);
int pop(Stack *s);
int peek(Stack* s);
void display(Stack* s);

int main(void){
	Stack* s = initialize();
    
    push(s,10);
    push(s,20);
    push(s,69);
    display(s);
    int popValue = pop(s);
    printf("\nPopped value:%d\n",popValue);

    return 0;
}

Stack* initialize(){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

bool isFull(Stack* s){
    return false;
}

bool isEmpty(Stack* s){
    return s->top == NULL;
}

void push(Stack *s,int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value; 
    newNode->next = s->top; //so i will first link the node to the current top, i see thats crazy 
    s->top = newNode; // so top is going to point to the new node
}

int pop(Stack *s){
    if(isEmpty(s)){
        printf("List is empty");
    }
    Node* temp = s->top;
    int data = s->top->data;//storing the data of the top node.. aw
    s->top = temp->next;
    free(temp);
    return data;
}

int peek(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty");
    }
    return s->top->data;
}

void display(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty");
        return;
    }
    Node* trav = s->top;
    while(trav != NULL){
        printf("%d ",trav->data);
        trav = trav->next;
    }
    
}