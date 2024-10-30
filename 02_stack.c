#include <stdio.h>
#define SIZE 5
int stack[SIZE], top = -1;

void push(){
  int element;

  printf("Enter the element to be pushed: ");
  scanf("%d", &element);

  if(top == SIZE - 1){
    printf("Stack overflow!\n");
  }else{
    top++;
    stack[top] = element;
    printf("%d is inserted into the stack!\n", element);
  }
}

void pop(){
  int element;

  if(top == -1){
    printf("Stack underflow!\n");
  }else{
    element = stack[top];
    top--;
    printf("%d is deleted from the stack!\n", element);
  }
}

void display(){
  int element;

  if(top == -1){
    printf("No elements in stack!\n");
  }else{
    for(int i = 0; i <= top; i++){
      printf("%d", stack[i]);

      if(i < top){
        printf(", ");
      }
    }
    printf("\n");
  }
}

int main(){
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