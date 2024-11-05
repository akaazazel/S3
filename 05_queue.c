#include <stdio.h>
#define SIZE 5
int queue[SIZE], front = -1, rear = -1;

void enqueue(){
  int element;

  printf("Enter element to be inserted: ");
  scanf("%d", &element);

  if(rear == SIZE-1){
    printf("Queue overflow!\n");
  }else if(front == -1){
    front = 0;
    rear = 0;
    queue[rear] = element;
    printf("%d inserted inserted into queue.\n", element);
    printf("%d", front);
  }else{
    rear++;
    queue[rear] = element;
    printf("%d inserted inserted into queue.\n", element);
  }
}

void dequeue(){
  int element;

  if(front == -1 || (front > rear)){
    printf("Queue underflow!\n");
    front = -1;
    rear = -1;
  }else{
    element = queue[front];
    printf("%d deleted from the queue.\n", element);
    front++;
  }
}

void display(){
  int element;

  if((front == -1) || front > rear){
    printf("Queue is empty!");
  }else{
    for(int i = 0; i <= rear; i++){
      printf("%d", queue[i]);

      if(i < rear){
        printf(", ");
      }
    }
    printf("\n");
  }
}


int main(){
  int running = 1;
  int choice;

  printf("Enter your choice:\n 1. enqueue | 2. dequeue | 3. display | 4. exit\n");

  while (running == 1){
    printf(":> ");
    scanf("%d", &choice);

    switch (choice){
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
  
}