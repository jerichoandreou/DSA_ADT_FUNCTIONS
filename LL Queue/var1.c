#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct{
    Node* front;
    Node* rear;
}Queue;

Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);

int main(void){
    Queue* q = initialize();
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    display(q);
    printf("Dequeued: %d\n",dequeue(q));
    display(q);
    printf("Front: %d\n",front(q));
    return 0;
}

Queue* initialize(){
    Queue* q =(Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isFull(Queue* q){
    return false;
}

bool isEmpty(Queue* q){
   return q->front == NULL;
}

void enqueue(Queue* q,int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if(q->front == NULL){
       q->front = newNode;
       q->rear = newNode;
    }else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q){
	if(isEmpty(q)){
		printf("Queue is empty");
	}
	Node* temp = q->front;
	int value = q->front->data;
	q->front = q->front->next;
	if(isEmpty(q)){
		q->rear = NULL;
	}
	free(temp);
	return value;
}

int front(Queue* q){
	if(isEmpty(q)){
		printf("Q is empty");
	}else{
		return q->front->data;
	}
}

void display(Queue* q){
    if(isEmpty(q)){
        printf("Q is empty");
    }
    printf("Queue:\n");
    Node* trav = q->front;
    while(trav != NULL){
        printf("%d ",trav->data);
        trav = trav->next;
    }
    printf("\n");
}
