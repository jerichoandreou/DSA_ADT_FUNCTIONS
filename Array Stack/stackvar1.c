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

int main(void){
	Stack* S = initialize();
	
	push(S,10);
	push(S,20);
	push(S,30);
	push(S,40);
	display(S);
	pop(S);
	display(S);
	peek(S);
	display(S);
	return 0;
}

Stack* initialize(){
	Stack* S =(Stack*)malloc(sizeof(Stack));
	S->top = -1;
	return S;
}

void push(Stack* S,int value){
	if(S->top == MAX - 1){
		printf("STACK OVERFLOW");
		return;
	}
	S->top++;
	S->items[S->top] = value;
}

int pop(Stack *S){
	if(S->top == -1){
		printf("STACK IS EMPTY");
	}
	int returnVal = S->items[S->top];
	S->top--;
	return returnVal;
}

int peek(Stack *S){
	if(S->top == -1){
		printf("STACK IS EMPTY");
	}
	return S->items[S->top];
}

int top(Stack* S){
	return S->items[S->top];
}

void display(Stack *S){
	if(S->top == -1){
		printf("STACK IS EMPTY");
	}
	printf("\n");
	printf("Stack from top to bottom:\n");
	int i;
	for(i = S->top;i >= 0;i--){
		printf("%d ",S->items[i]);
	}
}


