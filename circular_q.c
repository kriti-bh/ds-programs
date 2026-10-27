
#include <stdio.h>
#define SIZE 5

int q[SIZE], front = -1, rear = -1;

void insert()
{
    int x;

    if ((front == 0 && rear == SIZE - 1) ||
        (rear + 1 == front))
        printf("Queue is Full\n");
    else
    {
        printf("Enter element: ");
        scanf("%d", &x);

        if (front == -1)
            front = rear = 0;
        else if (rear == SIZE - 1)
            rear = 0;
        else
            rear++;

        q[rear] = x;
        printf("Successfully inserted %d\n", x);
    }
}

void delete()
{
    if (front == -1)
        printf("Queue is Empty\n");
    else
    {
        printf("Successfully deleted: %d\n", q[front]);

        if (front == rear)
            front = rear = -1;
        else if (front == SIZE - 1)
            front = 0;
        else
            front++;
    }
}

void display()
{
    int i;

    if (front == -1)
        printf("Queue is Empty, no elements to display.\n");
    else
    {
        i = front;

        while (1)
        {
            printf("%d ", q[i]);

            if (i == rear)
                break;

            if (i == SIZE - 1)
                i = 0;
            else
                i++;
        }
        printf("\n");
    }
}

int main()
{
    int ch;

    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4:
                printf("exiting program");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
