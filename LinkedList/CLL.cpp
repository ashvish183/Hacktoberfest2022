#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node* next;	
};

class list
{
	public:
		node* head;
		int len;
	
	list() //Default constructor
	{
		head==NULL;
		len=0;
	
	}

void create();
void display();

};

void list :: create()
{
	node *temp,*p;
	int add;
	
	do
	{
		temp=new node;
		cout<<"Enter data: ";
		cin>>temp->data;
		temp->next=head;
		
		if(head==NULL)
		{
			head=temp;
			
		}
		
		else
		{
			p=head;
			while(p->next!=head)
			{
				p=p->next;
			}
			
			p->next=temp;
			temp->next=head;
		}
		
		cout<<"If you want to add more nodes enter 1: ";
		cin>>add;
		
		
	} while(add==1);
	
}


void list :: display()
{
	cout<<"\n";
	node*p;
	p=head;
	
	while(p->next!=head)
	{
		cout<<p->data;
		p=p->next;
	}
}


int main()
{
	
	int ch;
	
    list l;
    
    l.create();
    l.display();
	
	
	return 0;
}
