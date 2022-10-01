#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;
struct node *p,*nw,*q;
void insertion_begin(int val)
{
	nw=((struct node*)malloc(sizeof(struct node)));
	nw->data=val;
	nw->next=NULL;
	nw->prev=NULL;
	p=head;
	if(head==NULL)
		head=nw;
	else
	{
	nw->next=p;
	p->prev=nw;
	head=nw;
	}
}

void insertion_end(int val)
{
	nw=((struct node*)malloc(sizeof(struct node)));
	nw->data=val;
	nw->next=NULL;
	nw->prev=NULL;
	p=head;
	if(head==NULL)
		head=nw;
	while(p->next!=NULL)
		p=p->next;
	p->next=nw;
	nw->prev=p;
}
int deletion_begin()
{
	p=head;
	if(head==NULL)
	{
	printf("Deletion is not possible or empty list");
	return 0;
	}
	else
	{
	int x=p->data;
	head=p->next;
	(p->next)->prev=NULL;
	free(q);
	return x;
	}
}
int deletion_end()
{
	p=head;
	if(head==NULL)
	{
		printf("Deletion is not possible or empty list");
	return 0;
	}
	else
	{
		while(p!=NULL)
		{
			q=p;
			p=p->next;
		}
		q->next=NULL;
		int x=p->data;
		free(p);
		return x;
	}
}
void display()
{
	printf("The linked list is\n");
	p=head; q=p;
	while(p!=NULL)
	{
		q=p;
		printf("%d\t",p->data);
		p=p->next;
	}
	printf("\n");
}
void ins_at_any(int val,int pos)
{
	nw=((struct node*)malloc(sizeof(struct node)));
	nw->data=val;
	nw->next=NULL;
	nw->prev=NULL;
	p=head;
	q=p;
	int i=1;
	if(head==NULL)
	{
		head=nw;
	}
	while(i<=pos&&p!=NULL)
	{
		q=p;
		p=p->next;
		i++;
	}
	q->next=nw;
	nw->prev=q;
	nw->next=p;
	p->prev=nw;
	if(i==1)
		printf("Desired position not available.Value inserted at end\n");
}
int del_at_any(int pos)
{
	p=head;
	int i=1;
	int k;
	q=p;
	if(head==NULL)
	{
		printf("Deletion is not possible or empty list");
		return 0;
	}
	else
	{
		while(i!=pos)
		{
			q=p;
			p=p->next;
			i++;
			k++;
		}
		if(k==0)
		{
			printf("Value not found in list\n");
		return 0;
		}
		else
		{
			q->next=p->next;
			(p->next)->prev=q->next;
			int x=p->data;
			free(p);
			return x;
		}
	}
}
int search(int val)
{
	int i=1;
	int k;
	p=head;
	if(head==NULL)
	{
		printf("List empty\n");
		return 0;
	}
	else
	{
		while(p!=NULL)
		{
			if(p->data==val)
			{
				return i;
				break;
				k++;
			}
		}
		if(k==0)
		{
			printf("The number is not present in the list\n");
			return 0;
		}
	}
}
main()
{
int ch,val,pos;
while(1)
{
	printf("Enter choice for operation in linked list:\n1for insertion at beginning\n2for insertion at end\n3for deletion from beginning\n4for deletion from end\n5for displaying the linked list\n6to enter atany point\n7to delete from anypoint\n8to search the position of an element\n9toexit from list\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("Enter the value to enter\n");
			scanf("%d",&val);
			insertion_begin(val);
			break;
		case 2:
			printf("Enter the value to insert\n");
			scanf("%d",&val);
			insertion_end(val);
			break;
		case 3:
			val=deletion_begin();
			printf("The deleted value is %d",val);
			break;
		case 4:
			val=deletion_end();
			printf("The deleted value is %d",val);
			break;
		case 5:
			display();
			break;
		case 6:
			printf("Enter the value to enter\n");
			scanf("%d",&val);
			printf("Enter the position to enter\n");
			scanf("%d",&pos);
			ins_at_any(val,pos);
			break;
		case 7:
			printf("Enter the position to delete value\n");
			scanf("%d",&pos);
			val=del_at_any(pos);
			printf("The deleted value is %d",val);
			break;
		case 8:
			printf("The value to search in the list\n");
			scanf("%d",&val);
			pos=search(val);
			printf("The value searched is in %d the position\n",pos);
			break;
		case 9:
			printf("End of the list\n");
			exit(0);
		}
	}
}
