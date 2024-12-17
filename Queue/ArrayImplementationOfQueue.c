#include<stdlib.h>
#include <stdbool.h>
#include<stdio.h>
#include<conio.h>

#define MAX 10

typedef struct Queue {
    int arr[MAX];
    int front;
    int rare;
}Queue;


void initialize(Queue *q) {
    q->front = 0;
    q->rare = 0;
}


bool isEmpty(Queue *q) {
    if(q->front == q->rare) {
        return true;
    }else{
        return false;
    }
}

bool isFull(Queue *q) {
    if(q->rare == MAX -1) {
        return true;
    }else{
        return false;
    }
}

void enqueue(Queue *q , int element) {
    if(isFull(q)) {
        printf("queue is full ");
        return;
    }

    q->arr[q->rare] = element;
    q->rare++;
}

int dequeue(Queue *q) {

    if(isEmpty(q)) {
        printf("queue is empty");
        return -1;

    }
    int ans = q->arr[q->front];
    q->arr[q->front] = -1;
    q->front++;

    if(q->front == q->rare) {
        q->front = 0;
        q->rare = 0;
    }

    return ans;

}

int front(Queue *q) {
    if(isEmpty(q)) {
        printf("queue is empty");
        return -1;

    }

    return q->arr[q->front];
}

int main () {
    Queue q;
    initialize(&q);



    enqueue(&q , 1);
    enqueue(&q , 2);
    enqueue(&q , 3);
    enqueue(&q , 4);
    enqueue(&q , 5);

    printf("%d" , isFull(&q));


    printf("%d" , front(&q));
    dequeue(&q);
    printf("%d" , front(&q));
    dequeue(&q);
    printf("%d" , front(&q));
    dequeue(&q);
    printf("%d" , front(&q));
    dequeue(&q);
    printf("%d" , front(&q));


    printf("%d" , isEmpty(&q));
    

    return 0;
}