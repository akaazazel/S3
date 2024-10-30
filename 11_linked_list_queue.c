#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue() {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if (!newNode) {
    printf("Queue overflow!\n");
    return;
  }

  int value;
  printf("Enter the value: ");
  scanf("%d", &value);

  newNode->data = value;
  newNode->next = NULL;

  if (rear == NULL) { 
    front = rear = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }

  printf("%d added to the queue!\n", value);
}

void dequeue() {
  if (front == NULL) {
    printf("Queue underflow!\n");
    return;
  }

  struct Node* temp = front;
  front = front->next;

  if (front == NULL) { 
    rear = NULL;
  }

  printf("%d removed from the queue!\n", temp->data);
  free(temp);
}

void display() {
  if (front == NULL) {
    printf("Queue is empty!\n");
    return;
  }

  printf("Queue elements: ");
  struct Node* temp = front;
  while (temp != NULL) {
    printf("%d", temp->data);
    temp = temp->next;
    if (temp != NULL) {
      printf(", ");
    }
  }
  printf("\n");
}

int main() {
  int choice;
  int running = 1;

  printf("Enter your choice:\n 1. enqueue | 2. dequeue | 3. display | 4. exit\n");

  while (running) {
    printf(":> ");
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
        printf("Invalid choice! Try again.\n");
    }
  }

  return 0;
}
