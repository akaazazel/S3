#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
};

struct Node* head = NULL;


void displayForward(){
		struct Node* temp = head;
    printf("List (head to tail): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayBackward() {
		struct Node* temp = head;
		
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("List (tail to head): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void insertFront(){
	int value;
	printf("Element:> ");
	scanf("%d", &value);

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->prev = NULL;
	newNode->next = head;
	
	if(head != NULL){
		head->prev = newNode;
	}
	
	head = newNode;
	printf("%d has been added at the front!\n", value);
}


void insertRear(){
	int value;
	printf("Element:> ");
	scanf("%d", &value);
	
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	
	newNode->data = value;
	newNode->next = NULL;
	
	if(head == NULL){
		newNode->prev = NULL;
		head = newNode;
		printf("%d has been added at the end!\n", value);
		return;
	}
			
	struct Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
	printf("%d has been added at the end!\n", value);
}	


void deleteAtIndex() {
    int index;
    printf("Index:> ");
    scanf("%d", &index);

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;

    for (int i = 0; i < index; i++) {
        if (temp == NULL) {
            printf("Index out of bounds!\n");
            return;
        }
        temp = temp->next;
    }

    if (temp->prev == NULL) {
        head = temp->next;
    } else {
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    printf("%d deleted from index %d\n", temp->data, index);
    free(temp);
}



int main(){
	int running = 1;
	int choice;
	
	while(running){
		printf("\n| 1. insert at front   | 2. insert at rear   | 3. delete        |\n");
		printf("| 4. display forward   | 5. display backward | 6. quit          |\n");
		printf("\nChoice:> ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1: insertFront(); break;
			case 2: insertRear(); break;
			case 3: deleteAtIndex(); break;
			case 4: displayForward(); break;
			case 5: displayBackward(); break;
			case 6: running = 0; break;
			default:
				printf("Invalid choice! Try again!\n");
		}
	}
	return 0;
}