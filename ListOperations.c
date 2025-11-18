#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *head2 = NULL;
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
void push2(int value)
{
    struct Node *newNode = createNode(value);
    if (head2 == NULL)
    {
        head2 = newNode;
    }
    else
    {
        newNode->next = head2;
        head2 = newNode;
    }
}
void swap(struct Node *a, struct Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
void bubbleSort()
{
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
void concatinate()
{
    struct Node *ptr1 = head;
    struct Node *ptr2 = head2;
    if (ptr1 == NULL)
    {
        head = head2;
        return;
    }
    while (ptr1->next != NULL)
    {
        ptr1 = ptr1->next;
    }
    ptr1->next = ptr2;
}
void reverse()
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void display()
{
    temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("List elements are:\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int choice, value, value2;
    printf("\n--------Menue--------\n1.Push to List 1\n2.Push to List 2\n3.Bubble Sort List 1\n4.Concatinate List 1 and List 2\n5.Reverse List 1\n6.Display List 1\n7.Exit\n");
    while (1)
    {
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to push to List 1:\n");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            printf("Enter value to push to List 2:\n");
            scanf("%d", &value2);
            push2(value2);
            break;
        case 3:
            bubbleSort();
            printf("List 1 sorted using Bubble Sort.\n");
            break;
        case 4:
            concatinate();
            printf("List 1 and List 2 concatenated.\n");
            break;
        case 5:
            reverse();
            printf("List 1 reversed.\n");
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
