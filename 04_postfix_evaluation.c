#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x;
    }
}

int pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int evaluatePostfix(char* exp) {
    int i;
    
    for(i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if(isdigit(ch)) {
            push(ch - '0'); 
        } else {
            int val2 = pop();
            int val1 = pop();
            
            switch(ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': 
                    if(val2 != 0) {
                        push(val1 / val2); 
                    } else {
                        printf("Division by zero error!\n");
                        return -1;
                    }
                    break;
                default: 
                    printf("Invalid operator encountered: %c\n", ch);
                    return -1;
            }
        }
    }
    return pop();
}

int main() {
    char exp[MAX];

    printf("Enter a postfix expression: ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    if(result != -1) {
        printf("Result of postfix evaluation: %d\n", result);
    }

    return 0;
}
