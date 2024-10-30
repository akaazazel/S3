#include <stdio.h>
#define SIZE 5
int deque[SIZE], front = -1, rear = -1;

void enqueueFront(){
    int item;
    if((front == 0 && rear == SIZE - 1) || (front == rear + 1)){
        printf("Deque Overflow\n");
    } else {
        printf("Enter the element to insert at the front: ");
        scanf("%d", &item);

        if(front == -1){
            front = rear = 0;
        } else if(front == 0){
            front = SIZE - 1;
        } else {
            front--;
        }
        deque[front] = item;
        printf("%d has been inserted at the front of the deque!\n", item);
    }
}

void enqueueRear(){
    int item;
    if((front == 0 && rear == SIZE - 1) || (front == rear + 1)){
        printf("Deque Overflow\n");
    } else {
        printf("Enter the element to insert at the rear: ");
        scanf("%d", &item);

        if(front == -1){ 
            front = rear = 0; 
        } else if(rear == SIZE - 1){ 
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = item;
        printf("%d has been inserted at the rear of the deque!\n", item);
    }
}

void dequeueFront(){
    int item;
    if(front == -1){
        printf("Deque Underflow!\n");
    } else {
        item = deque[front];
        if(front == rear){ 
            front = rear = -1;
        } else if(front == SIZE - 1){ 
            front = 0;
        } else {
            front++;
        }
        printf("%d has been removed from the front of the deque!\n", item);
    }
}

void dequeueRear(){
    int item;
    if(front == -1){
        printf("Deque Underflow!\n");
    } else {
        item = deque[rear];
        if(front == rear){ 
            front = rear = -1;
        } else if(rear == 0){ 
            rear = SIZE - 1;
        } else {
            rear--;
        }
        printf("%d has been removed from the rear of the deque!\n", item);
    }
}

void display(){
    if(front == -1){
        printf("Deque is empty!\n");
    } else {
        printf("Deque elements are: ");
        if(front <= rear){
            for(int i = front; i <= rear; i++){
                printf("%d", deque[i]);
                if(i < rear) printf(", ");
            }
        } else {
            for(int i = front; i < SIZE; i++){
                printf("%d", deque[i]);
                if(i < SIZE - 1) printf(", ");
            }
            for(int i = 0; i <= rear; i++){
                if(i != 0 || front != 0) printf(", ");
                printf("%d", deque[i]);
            }
        }
        printf("\n");
    }
}

int main(){
    int running = 1;
    int choice;

    printf("Enter your choice:\n 1. enqueueFront | 2. enqueueRear | 3. dequeueFront | 4. dequeueRear | 5. display | 6. exit\n");

    while(running == 1){
        printf("\n:> ");
        scanf("%d", &choice);

        switch(choice){
            case 1: enqueueFront(); break;
            case 2: enqueueRear(); break;
            case 3: dequeueFront(); break;
            case 4: dequeueRear(); break;
            case 5: display(); break;
            case 6:
                printf("Exited!\n");
                running = 0;
                break;
            default:
                printf("Error! Try again.\n");
        }
    }
    return 0;
}
