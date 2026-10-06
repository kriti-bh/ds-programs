#include <stdio.h>
#define MAX 3
int queue[MAX];
int front=-1,rear=-1;
void insert()
{
    int element;
    if(rear==MAX-1)
    {
        printf("Overflow");
        return;
    }
    printf("enter element:");
    scanf("%d",&element);
    if(front==-1)
    {
        front=0;
    }
        rear++;
        queue[rear]=element;
        printf("%d added to queue",element);
}
void delete()
{
    if (front==-1||front>rear)
    {
        printf("queue underflow");
        return;
    }
    printf("%d deleted from queue\n", queue[front]);
    front++;

   if (front > rear)
   {
       front=-1;
       rear=-1;
   }
}
void display()
{
   int i;

   if (front == -1)
   {
       printf("Queue is empty");
       return;
   }
   printf("queue elements are:");
   for(i=front;i<=rear;i++)
   {
       printf("%d ",queue[i]);
   }
   printf("\n");
}
int main()
{
  int choice;

  while (1)
  {
      printf("\n--- QUEUE OPERATIONS ---\n");
      printf("1. Insert\n");
      printf("2. Delete\n");
      printf("3. Display\n");
      printf("4. Exit\n");

      printf("Enter your choice: ");
      scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    insert();
    break;
  case 2:
    delete();
    break;
  case 3:
    display();
    break;
  case 4:
    return 0;
  default:
    printf("invalid choice\n");
  }
}
}
