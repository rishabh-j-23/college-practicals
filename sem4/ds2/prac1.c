#include <stdio.h>
#include <malloc.h>
typedef struct node Node;
struct node
{
    int data;
    Node *next;
};
Node *head = NULL, *last;
int size()
{
    Node *i = head;
    int len = 0;
    while (i != NULL)
    {
        len++;
        i = i->next;
    }
    return len;
}
void addNodeAtStart(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = head;
    head = newNode;
    newNode->data = data;
}
void addNodeAtEnd(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if (head == NULL)
    {
        head = newNode;
        head->next = NULL;
        last = head;
    }
    else
    {
        last->next = newNode;
        last = newNode;
        newNode->next = NULL;
    }
}
void addNodeAt(int index, int data)
{
    if (index < 0)
    {
        return;
    }
    if (index > size() - 1)
    {
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    Node *currNode = head, *prev;
    int i;
    for (i = 0; i < index; i++)
    {
        prev = currNode;
        currNode = currNode->next;
    }
    newNode->next = currNode;
    prev->next = newNode;
}
void deleteAt(int index)
{
    if (index < 0)
    {
        return;
    }
    if (index > size() - 1)
    {
        return;
    }
    Node *currNode = head, *prev;
    int i;
    for (i = 0; i < index; i++)
    {
        prev = currNode;
        currNode = currNode->next;
    }
    prev->next = currNode->next;
    free(currNode);
}
void deleteFirst()
{
    Node *temp = head;
    head = head->next;
    free(temp);
}
void deleteLast()
{
    Node *temp = head, *prev;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    last = prev;
    prev->next = NULL;
    free(temp);
}
void traverse(char message[])
{
    Node *i = head;
    printf("LL (%s) : ", message);
    while (i != NULL)
    {
        printf("%d ", i->data);
        i = i->next;
    }
    printf("\n");
}
int main()
{
    addNodeAtEnd(1);
    addNodeAtEnd(3);
    addNodeAtEnd(4);
    addNodeAtEnd(12);
    addNodeAtEnd(123);
    traverse("node added at last");
    addNodeAt(3, 8);
    traverse("node added at index 3");
    addNodeAtStart(10);
    traverse("node added at head");
    deleteAt(2);
    traverse("node at index 2 deleted");
    deleteFirst();
    traverse("first node deleted");
    deleteLast();
    traverse("last node deleted");
    return 0;
}