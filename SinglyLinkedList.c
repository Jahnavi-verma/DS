#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *temp = NULL;
struct Node *last = NULL;

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void push(int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}
void append(int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newNode;
    }
}
void insert(int pos, int value)
{
    struct Node *newNode = createNode(value);
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        temp = head;
        for (int i = 0; i < pos - 1; i++)
        { //&& temp != NULL
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void display()
{
    temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("List elements are:\n");
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}
int main()
{
    int choice, value, pos;
    printf("1.Push\n2.Append\n3.Insert at position\n4.Display\n5.Leave\n");
    while (1)
    {
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to push:\n");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            printf("Enter value to append:\n");
            scanf("%d", &value);
            append(value);
            break;
        case 3:
            printf("Enter position and value to insert:\n");
            scanf("%d %d", &pos, &value);
            insert(pos, value);
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}