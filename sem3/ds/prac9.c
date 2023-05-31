#include <stdio.h>
#include <stdlib.h>
#define size 5
int front = -1, rear = -1;
int queue[size];
void insert()
{
    int data;
    printf("\nElement : ");
    scanf("%d", &data);
    if (rear == size - 1)
    {
        printf("\nOverflow\n");
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    queue[rear] = data;
}
void delete()
{
    int data;
    if (front == -1 || front > rear)
    {
        printf("\nUnderflow\n");
        return;
    }
    else
    {
        data = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = front + 1;
        }
        printf("\nValue deleted ");
    }
}
void display()
{
    int i;
    if (rear == -1)
    {
        printf("\nEmpty queue\n");
    }
    else
    {
        printf("[ ");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("]\n");
    }
}
void main()
{
    int choice;
    while (choice != 4)
    {
        printf("\n1.Insert an element\n");
        printf("2.Delete an element");
        printf("\n3.Display the queue");
        printf("\n4.Exit\n");
        printf("\nResponse : ");
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
                exit(0);
                break;
            default:
                printf("\nEnter valid choice? \n");
                break;
        }
    }
}
