#include <stdio.h>
#include <ctype.h> 
#include <string.h> 

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x;
    }
}

char pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int precedence(char x) {
    if(x == '*' || x == '/' || x == '%')
        return 2;
    else if(x == '+' || x == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char *exp) {
    int i, k;
    char output[MAX];

    k = 0;

    for(i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if(isalnum(ch)) {
            output[k++] = ch;
        }
        else if(ch == '(') {
            push(ch);
        }
        else if(ch == ')') {
            while(top != -1 && stack[top] != '(') {
                output[k++] = pop();
            }
            pop();
        }
        else {
            while(top != -1 && precedence(stack[top]) >= precedence(ch)) {
                output[k++] = pop();
            }
            push(ch);
        }
    }

    while(top != -1) {
        output[k++] = pop();
    }

    output[k] = '\0';
    printf("Postfix Expression: %s\n", output);
}

int main() {
    char exp[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", exp);

    infixToPostfix(exp);

    return 0;
}
