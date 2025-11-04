
int array[3];
int f;
int r, n = 3;
#include <stdio.h>
void enqueue(int value)
{
    if (r == n - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (f == -1)
        {
            f = 0;
        }
        r++;
        array[r] = value;
    }
}
void dequeue()
{
    if (f == -1 || f == r) // check for f>r later
    {
        printf("Queue Underflow\n");
        f = -1;
        r = -1;
    }
    else
    {
        f++;
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
        for (int i = f; i <= r; i++)
        {
            printf("%d\n", array[i]);
        }
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