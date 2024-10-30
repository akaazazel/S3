#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Node* newNode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

void enqueue(struct Queue* q, int value) {
    struct Node* temp = newNode(value);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        printf("%d enqueued to queue\n", value);
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
    printf("%d enqueued to queue\n", value);
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue underflow\n");
        return -1;
    }
    int value = q->front->data;
    struct Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return value;
}

int peek(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

void display(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue q;
    q.front = q.rear = NULL;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    printf("Front element is %d\n", peek(&q));

    printf("%d dequeued from queue\n", dequeue(&q));
    printf("%d dequeued from queue\n", dequeue(&q));

    display(&q);

    return 0;
}