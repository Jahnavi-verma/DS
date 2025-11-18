#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *temp = NULL;
struct Node *prev = NULL;

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
void Delete_first()
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
    }
    temp = head;
    head = head->next;
    free(temp);
}
void Delete_last()
{
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
void delet_at_pos(int pos)
{
    if (pos == 0)
    {
        Delete_first();
    }
    temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}
void display()
{
    temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    int choice, value, pos;
    printf("1.Push\n2.Delete_first\n3.Delete at position\n4.Delet at last\n5.Display\n6.Leave\n");
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
            printf("Deleted\n");
            Delete_first();
            break;
        case 3:
            printf("Enter position to delete:\n");
            scanf("%d", &pos);
            delet_at_pos(pos);
            break;
        case 4:
            printf("Deleted\n");
            Delete_last();
            break;
        case 5:
            display();
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}