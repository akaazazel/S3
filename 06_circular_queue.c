#include <stdio.h>
#define SIZE 5
int queue[SIZE], front = -1, rear = -1;

void enqueue() {
    int item;

    if ((rear + 1) % SIZE == front) {
        printf("Queue Overflow\n");
    } else {
        printf("Enter the element to insert: ");
        scanf("%d", &item);

        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        queue[rear] = item;
        printf("%d has been inserted into the queue!\n", item);
    }
}

void dequeue() {
    int item;

    if (front == -1) {
        printf("Queue Underflow!\n");
    } else {
        item = queue[front];

        if (front == rear) {
            front = rear = -1; // Queue is empty
        } else {
            front = (front + 1) % SIZE;
        }
        printf("%d has been removed from the queue!\n", item);
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    int running = 1;
    int choice;

    printf("Enter your choice:\n 1. enqueue | 2. dequeue | 3. display | 4. exit\n");

    while (running == 1) {
        printf("\n:> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4:
                printf("Exited!\n");
                running = 0;
                break;
            default:
                printf("Error! Try again.\n");
        }
    }
    return 0;
}