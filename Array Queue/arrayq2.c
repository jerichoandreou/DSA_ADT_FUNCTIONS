#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
	int items[MAX];
	int front;
	int rear;
}Queue;

Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q,int value);
int dequeue(Queue* q);
int front(Queue* q);
int display(Queue* q);

int main(void){
	Queue* q = initialize();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    display(q);

    printf("Front element: %d\n", front(q));
    
    return 0;
}

Queue* initialize(){
	Queue* q = malloc(sizeof(Queue));
	q->front = 1;
	q->rear = 0;
	return q;
}

bool isEmpty(Queue* q){
	return q->front == (q->rear + 1) % MAX;
}

bool isFull(Queue* q){
	return q->front == (q->rear + 2) % MAX;
}

void enqueue(Queue* q,int value){
	if(isFull(q)){
		printf("List is full");
		return;
	}
	q->rear = (q->rear + 1) % MAX;
	q->items[q->rear] = value; 
}

int dequeue(Queue* q){
	if(isEmpty(q)){
		printf("list is empty");
	}
	int value = q->items[q->front];
	q->front = (q->front + 1) % MAX;
	return value;
}

int front(Queue* q){
	if(isEmpty(q)){
		printf("List is empty");
	}
	return q->items[q->front];
}

int display(Queue* q){
	if(isEmpty(q)){
		printf("List is empty");
	}
	int i = q->front;
	
	while(i != (q->rear + 1) % MAX){
		printf("%d ",q->items[i]);
		i = (i + 1) % MAX;
	}
	printf("\n");
}
