#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* top = NULL;

void push(){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if(!newNode){
    printf("Stack overflow!\n");
    return;
  }

  int value;
  printf("Enter the value: ");
  scanf("%d", &value);

  newNode->data = value;
  newNode->next = top;
  top = newNode;
  printf("%d pushed to the stack!\n", value);
}

void pop(){
  if(top == NULL){
    printf("Stack is underflow!\n");
    return;
  }
  struct Node* temp = top;
  top = top->next;
  int poppedValue = temp->data;
  free(temp);
  printf("%d removed from the stack!\n", poppedValue);
}

void display(){
  if(top == NULL){
    printf("Stack is empty!\n");
    return;
  }
  printf("Stack elements: ");
  struct Node* temp = top;
  while(temp != NULL){
    printf("%d", temp->data);
    temp = temp->next;
    if(temp != NULL){
      printf(", ");
    }
  }
  printf("\n");
}

void main(){
  int choice;
  int running = 1;

  printf("Enter your choice:\n 1. push | 2. pop | 3. display | 4. exit\n");

  while(running == 1){
    printf(":> ");
    scanf("%d", &choice);

    switch (choice){
      case 1: push(); break;
      case 2: pop(); break;
      case 3: display(); break;
      case 4: 
        printf("Exited!");
        running = 0;
        break;
      default:
        printf("Error! Try again.\n");
    }
  }
}