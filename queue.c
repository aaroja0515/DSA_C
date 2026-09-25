#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue()
{
    int item;
    printf("Enter element: ");
    scanf("%d", &item);

    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        
    }

     else if (front == -1 && rear==-1){
        front=rear=0;
        }
    else
    {    

    rear++;
    queue[rear] = item;
}
}

void dequeue()
{
    if (front == -1 && rear==-1)
    {
        printf("Queue Underflow\n");
        return;
    }
    else if(front==rear){

    printf("Deleted element: %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
    printf("Deleted element: %d\n",queue[front]);
    front++;
    }
}

void peek()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {

    printf("Front element: %d\n", queue[front]);
}
}

void display()
{
    int i;

    if (front == -1 && rear==-1)
    {
        printf("Queue is Empty\n");
    }
    else
    {

    printf("Queue elements: ");

    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                peek();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
