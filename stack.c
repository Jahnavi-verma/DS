#include <stdio.h>
int i=-1;
int stack[10];
void push(int stack[],int *i,int value)
{
    if(*i>=9)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        (*i)++;
        stack[*i]=value;
        printf("%d pushed to stack\n",value);
    }
}
void pop(int stack[],int *i)
{
    if(*i==-1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        (*i)--;
        printf("%d is deleted\n",stack[*i+1]);
    }
}
void display(int stack[],int *i)
{
        printf("Stack elements are:\n");
        for(int j=*i;j>=0;j--)
        {
            printf("%d\n",stack[j]);
        }
}
int main(){
    int choice,value;
    printf("1.Push\n2.Pop\n3.Display\n4.Leave\n");
    while(1)
    {
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the value to be pushed:\n");
                scanf("%d",&value);
                push(stack,&i,value);
                break;
            case 2:
                pop(stack,&i);
                break;
            case 3:
                display(stack,&i);
                break;
            case 4:
                return 0;
                break;
            default:
                printf("Error\n");
        }
    }
    return 0;
}