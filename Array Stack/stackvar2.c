#include <stdio.h>
#include <stdlib.h>
#define MAX 10
//stack is a linear data structure in which insertions and deletions are allowed only at the end called at the top of the stack
typedef struct{
	int items[MAX];
	int top;
}Stack;

Stack* initialize();
void push(Stack* S,int value);
void display(Stack* S);
int pop(Stack *S);
int peek(Stack *S);
int main(void){
	Stack* S = initialize();
	
	push(S,10);
	push(S,20);	
	push(S,69);
	display(S);
	pop(S);
	display(S);
	peek(S);
	display(S);
	return 0;
}

Stack* initialize(){
	Stack *S = (Stack*)malloc(sizeof(Stack));
	S->top = MAX;
	return S;
}

void push(Stack* S,int value){
		if(S->top == 0){
		printf("STACK UNDERFLOW");
		return;
	}
	S->top--;
	S->items[S->top] = value;
}

int pop(Stack *S){
	if(S->top == MAX){
		printf("STACK IS EMPTY");
		return;
	}
	S->top++;
	int value = S->items[S->top];
	return value;
}

int peek(Stack *S){
	if(S->top == MAX){
		printf("STACK IS EMPTY");
		return;
	}
	int returnVal = S->items[S->top];
	return returnVal;
}

void display(Stack *S){
	if(S->top == MAX){
		printf("STACK IS EMPTY");
	}
	printf("\n");
	printf("Stack from top to bottom:\n");
	int i;
	for(i = S->top;i < MAX;i++){
		printf("%d ",S->items[i]);
	}
}


