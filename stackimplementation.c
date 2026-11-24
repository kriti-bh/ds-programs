#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into stack\n", value);
}

void pop() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;
    printf("Deleted element: %d\n", top->data);

    top = top->next;
    free(temp);
}

void display() {
    struct Node *temp = top;

    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
