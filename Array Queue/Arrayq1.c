#include <stdio.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
	int items[MAX];
	int count;
	
}List;

typedef struct{
	List list;
	int front;
	int rear;
}Queue;

Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
bool enqueue(Queue* q,int value);
bool front(Queue* q);
bool dequeue(Queue* q);

int main(void){
    Queue* q = initialize();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    printf("Queue: ");
    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    printf("Queue after dequeue: ");
    display(q);

    printf("Front element: %d\n", front(q));

	return 0;
}

Queue* initialize(){
	Queue* q =(Queue*)malloc(sizeof(Queue));
	q->list.count = 0;
	q->front = -1;
	q->rear = -1;
}

bool isFull(Queue* q){
	return q->list.count == MAX;
}
bool isEmpty(Queue* q){
	return q->list.count == 0;
}

bool enqueue(Queue* q,int value){
	if(isFull(q)){
		printf("\nqueue is full");
		return;
	}
	else{
		q->rear = (q->rear + 1) % MAX;
	}
	q->list.items[q->rear] = value;
	q->list.count++;
}

bool dequeue(Queue* q){
	if(isEmpty(q)){
		printf("\nqueue is empty");
		return;
	}
	int value = q->list.items[q->front];
	if(q->list.count == 1){
		q->front = -1;
		q->rear = -1;
	}
	else{
		q->front = (q->front + 1) % MAX;
	}
	q->list.count--;
	return value;
}

bool front(Queue* q){
	if(isEmpty(q)){
		printf("\nqueue is empty");
		return;
	}
	return q->list.items[q->front];
}

void display(Queue* q){
	if(isEmpty(q)){
		printf("queue is empty");
		return;
	}
	int i;
	int index = q->front;
	for(i = 0;i < q->list.items[index];i++){
		printf("%d ",q->list.items[index]);
		index = (index + 1) % MAX;
	}
	printf("\n");
}


