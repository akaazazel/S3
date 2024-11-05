#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("List elements: \nHEAD -> ");
    while (temp != NULL) {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertFront() {
    int value;
    printf("Element:> ");
    scanf("%d", &value);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("%d has been added at the front!\n", value);
}

void insertRear() {
    int value;
    printf("Element:> ");
    scanf("%d", &value);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("%d has been added at the end!\n", value);
}

void insertAtIndex() {
    int value, index;
    printf("Element:> ");
    scanf("%d", &value);
    printf("Index:> ");
    scanf("%d", &index);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;

    if (index == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* temp = head;
        for (int i = 0; i < index - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of bounds!\n");
            free(newNode);
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("%d has been inserted at index %d\n", value, index);
}

void deleteFront() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("%d has been removed from front!\n", temp->data);
    free(temp);
}

void deleteRear() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL) {
        printf("%d has been removed from rear!\n", head->data);
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        printf("%d has been removed from rear!\n", temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
}

void deleteAtIndex() {
    int index;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Index:> ");
    scanf("%d", &index);

    if (index == 0) {
        struct Node* temp = head;
        head = head->next;
        printf("%d deleted from index %d\n", temp->data, index);
        free(temp);
        return;
    }

    struct Node* temp = head;
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds!\n");
        return;
    }
    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    printf("%d deleted from index %d\n", delNode->data, index);
    free(delNode);
}

int main() {
    int running = 1;
    int choice;
    while (running) {
        printf("\n| 1. insert at front  | 2. insert at rear    |\n");
        printf("| 3. insert at index  | 4. delete from front |\n");
        printf("| 5. delete from rear | 6. delete at index   |\n");
        printf("| 7. display | 8. quit |\n");
        printf("Choice:> ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertFront(); break;
            case 2: insertRear(); break;
            case 3: insertAtIndex(); break;
            case 4: deleteFront(); break;
            case 5: deleteRear(); break;
            case 6: deleteAtIndex(); break;
            case 7: display(); break;
            case 8: running = 0; break;
            default: printf("Invalid choice! Try again!\n");
        }
    }
    return 0;
}
