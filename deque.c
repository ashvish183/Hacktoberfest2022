#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int front=0,rear=0;
int queue[MAX];
void insertf(int);
void insertr(int);
void deletef();
void deleter();
void display();

void main()
{
    int d,ch;
    do
    {
    printf("Choose a function\n 1)Insert at front\n 2)Insert at rear\n 3)Delete at front\n 4)Delete at rear\n 5)Display\n 6)Exit\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        printf("Enter value:");
        scanf("%d",&d);
        insertf(d);
        break;
    
    case 2:
        printf("Enter value:");
        scanf("%d",&d);
        insertr(d);
        break;

    case 3:
        deletef();
        break;
    
    case 4:
        deleter();
        break;
    
    case 5:
        display();
        break;

    case 6:
        exit(1);

    default:
        printf("Invalid Operation\n\n");
        break;
    }
    }
while (1==1);
}
void insertf(int d)
{
    int i;
    if(rear==MAX)
    printf("Queue is full\n");
    else
    {
        for(i=MAX;i>=1;i--)
        queue[i]=queue[i-1];
        
        queue[0]=d;
        rear++;
    }
}
void insertr(int d)
{
    if(rear==MAX)
    printf("Queue is full\n");
    else
    {
        queue[rear]=d;
        rear++;
    }
}
void deletef()
{ 
    int d;
    if(front==rear)
    printf("Queue is empty\n");
    else
    {
       d=queue[front];
       printf("%d data deleted\n",d);
       front++;
    }    
}
void deleter()
{
    int d;
    if(front==rear)
    printf("Queue is empty\n");
    else
    {
        rear--;
        d=queue[rear];
        printf("%d data deleted\n",d);
    }
}
void display()
{
    int i;
    printf("Queue:\n");
    for(i=front;i<rear;i++)
    printf("%d\n",queue[i]);
}
