#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{

    typedef struct node Node;

    Node *first, *lastNode, *curNode, *start, *searchNode, *temp;
    int run = 1, response;
    first = 0;
    int con = 1;

    while (run)
    {
        printf("\n1.Add data");
        printf("\n2.Delete data");
        printf("\n3.Display data");
        printf("\n4.Add at specified position");
        printf("\nResponse : ");
        scanf("%d", &response);
        switch (response)
        {
        case 1:
            while (con)
            {
                curNode = (Node *)malloc(sizeof(Node));
                printf("enter data : ");
                scanf("%d", &curNode->data);
                if (first != 0)
                {
                    lastNode->next = curNode;
                    lastNode = curNode;
                }
                else
                {
                    first = lastNode = curNode;
                }
                fflush(stdin);
                printf("continue data entry (0/1) : ");
                scanf("%d", &con);
            }
            lastNode->next = 0;
            curNode = 0;
            break;

        case 2:
        {
            int data, delstatus;
            searchNode = first;
            printf("Enter data to be deleted : ");
            scanf("%d", &data);
            while (searchNode != 0)
            {
                if (searchNode->data == data)
                    break;
                temp = searchNode;
                searchNode = searchNode->next;
            }
            if (searchNode == 0)
                printf("ID not found");
            else
                printf("Record with ID = %d is stored on address %d\n", data, searchNode);
            printf("Do you want to delete this record ? (Yes=1 | No=0)");
            scanf("%d", &delstatus);

            if (delstatus == 1)
            {
                printf("Record of ID = %d Deleted", data);
                temp->next = searchNode->next;
                free(searchNode);
            }
            else
                printf("NOT DELETED ");
            break;
        }

        case 3:
            curNode = first;
            printf("[ ");
            while (curNode != 0)
            {
                printf("%d ", curNode->data);
                curNode = curNode->next;
            }
            printf("]\n");

            curNode = 0;
            break;

        case 4:
            curNode = first;
            int index;
            Node *nextNode, *prevNode, *addNode;
            printf("Add element at after pos : ");
            scanf("%d", &index);

            addNode = (Node *)malloc(sizeof(Node));
            for (int i = 0; i < index; i++)
            {
                if (curNode != 0)
                {
                    curNode = curNode->next;
                }
            }
            addNode->next = curNode->next;
            curNode->next = addNode;

            printf("Data : ");
            scanf("%d", &addNode->data);

            break;

        default:
            break;
        }

        fflush(stdin);
        printf("back to menu? (0/1) : ");
        scanf("%d", &run);
    }
    return 0;
}