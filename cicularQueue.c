#include <stdio.h>
#define n 3
int array[n];
int f = -1;
int r = -1;
void enqueue(int value)
{
    if ((r + 1) % n == f)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (f == -1)
        {
            f = 0;
        }
        r = (r + 1) % n;
        array[r] = value;
    }
}
void dequeue()
{
    if (f == r)
    {
        printf("Queue Underflow\n");
        f = -1;
        r = -1;
    }
    else
    {
        f = (f + 1) % n;
    }
}
void display()
{
    if (f == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are:\n");
        int i = f;
        while (i != r)
        {
            printf("%d\n", array[i]);
            i = (i + 1) % n;
        }
        printf("%d\n", array[r]);
    }
}
int main()
{
    f = -1;
    r = -1;
    int choice, value;
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Leave\n");
    while (1)
    {
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be enqueued:\n");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
