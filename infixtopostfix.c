#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

int infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];


        if (isalnum(c)) {
            postfix[j++] = c;
        }


        else if (c == '(') {
            push(c);
        }


        else if (c == ')') {

            if (top == -1) {
                printf("Error: Extra ')' found.\n");
                return 0;
            }

            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();


            if (top == -1) {
                printf("Error: Missing '('.\n");
                return 0;
            }

            pop();
        }


        else if (c == '+' || c == '-' ||
                 c == '*' || c == '/' || c == '^') {

            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = pop();
            }

            push(c);
        }


        else {
            printf("Error: Invalid character '%c'.\n", c);
            return 0;
        }
    }


    while (top != -1) {
        if (stack[top] == '(') {
            printf("Error: Missing ')'.\n");
            return 0;
        }

        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    return 1;
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    if (infixToPostfix(infix, postfix)) {
        printf("Postfix expression: %s\n", postfix);
    }

    return 0;
}