#include <stdio.h>
#include<stdlib.h>
#define MAX 6

void enqueue_f(int[],int*,int);
int delqueue_f(int[],int*);
void display_f(int[],int,int);
int main()
{
    int Q[5],num,choice,f=1,r=0;
    while(1)
    {
        printf("Choose any one for the following:\n");
        printf("1.\tINSERTION\n2.\tDELETION\n3.\tDISPLAY\n4.\tEXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    if(r%MAX+1==f&r!=0)
                        printf("QUEUE IS FULL!\n");
                    else
                    {
                        printf("Enter the value you want to enter\n");
                        scanf("%d",&num);
                        enqueue_f(Q,&r,num);
                    }
                    break;
            case 2:
                    if(r==0)
                        printf("QUEUE IS EMPTY!\n");
                    else
                    {
                        if(f==r)
                        {
                            num=delqueue_f(Q,&f);
                            printf("Deleted value is:%d\n",num);
                            f=1,r=0;                                //resetting the pointers
                        }
                        else
                        {
                            num=delqueue_f(Q,&f);
                            printf("Delted value is:%d\n",num);
                        }
                    }
                    break;
            case 3:
                    if(r==0)
                        printf("QUEUE IS EMPTY!\n");
                    else
                        display_f(Q,r,f);
                    break;
            case 4:
                    exit(0);
            case 5:
                    printf("INVALID INPUT\nPlease choose correct option\n");
        }
    }
    return 0;
}
    
    //functions
    void enqueue_f(int q[5],int *rear,int temp)
    {
        *rear=*rear%MAX+1;
        q[*rear]=temp;
    }
    int delqueue_f(int q[5],int *front)
    {
        int temp;
        temp=q[*front];
        *front=*front%MAX+1;
        return temp;
    }
    void display_f(int q[5],int rear,int front)
    {
            int i;
            for(i=0;i<5;i=i%MAX+1)
            {
                printf("%d",q[i]);
            }
    }

