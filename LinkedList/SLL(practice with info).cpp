
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
void insert(int pos,int data);
void search(int info);
void del(int info);
void update(int info,int new_data);
	
};

void list :: create()
{
	node *temp,*ptr;
	int add;
	
	do
	{
		temp=new node;
		cout<<"Enter your data: ";
		cin>>temp->data;
		temp->next=NULL;
		len++;
		
		if(head==NULL)
		{
			head=temp;
		}
		
		else
		{
			ptr=head;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			    
			}
	         ptr->next=temp;
		}
		
		cout<<"If you want to add more nodes enter 1: ";
		cin>>add;
		
	}  while(add==1);
	
}


void list :: display()
{
	node *ptr;
	ptr=head;
	
	
	while(ptr!=NULL)
	{
		
		cout<<ptr->data<<" ->";
		ptr=ptr->next;
	}
	cout<<"NULL";
	
}


void list :: insert(int pos,int data)
{
	
	if(pos==1)
	{
		
		node *temp,*ptr;
		temp=new node;
		temp->data=data;
		
		temp->next=head;
		head=temp;
		
		
	}
	
	else if(pos>len)
	{
		
		node *temp,*ptr;
		temp=new node;
		temp->data=data;
		
		
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
			    
		}
	      ptr->next=temp;
	        
	}
	
	else
	{
		node *temp,*ptr;
		temp=new node;
		temp->data=data;
		
		
		ptr=head;
		
		for(int i=1;i<(pos-1);i++)
		{
			ptr=ptr->next;
			
		}
		
		temp->next=ptr->next;
		ptr->next=temp;
		
		
		
	}
	
}

void list :: search(int info)
{
	node *ptr;
	ptr=head;
	int flag=0,count=1;
	
	while(ptr!=NULL)
	{
		if(ptr->data==info)
		{
			flag=1;
			break;
		}
		
		else
		{
			ptr=ptr->next;
		}
		count++;
		
	}
	
	if(flag==1)
	{
		cout<<"Your data has been found at pos: "<<count;
	}
		
	else
	{
		cout<<"Data not found";
	}
	
}

void list :: del(int info)  //using info
{
	node *curr, *prev;
	int flag=0;
	curr=head;
	prev=NULL;
	
	while(curr!=NULL)
	{
		if(curr->data==info)
		{
			if(curr==head)
			{
				head=head->next;
				delete curr;
				flag=1;
				cout<<"\nData has been deleted successfully!!!";
				len--;
				break;
			}
			
			if(curr->next==NULL)
			{
				prev->next=NULL;
				delete curr;
				flag=1;
				cout<<"\nData has been deleted successfully!!!";
				len--;
				break;
			}
			
			else
			{
				prev->next=curr->next;
				delete curr;
				flag=1;
				cout<<"\nData has been deleted successfully!!!";
			    len--;
			    break;
			}
			break;
	    }
	    
		else
		{
			prev=curr;
			curr=curr->next;
		}
		
		
		
			
	}
	
	if(flag==0)
	{
		cout<<"\nSorry!!! data not found";
	}
}
	

	

void list :: update(int info,int new_data) //using info
{
	node *ptr;
	ptr=head;
	int flag=0;
	
	while(ptr!=NULL)
	{
	    if(ptr->data==info)
	    {
	        if(ptr==head)
	        {
		        ptr->data=new_data;
		        flag=1;
		        break;
	        }
	   
	    
	        if(ptr->next==NULL)
	        {
	           ptr->data=new_data;
	           flag=1;
	           break;
	        }
	    
	        else
	        {
	            ptr->data=new_data;
	            flag=1;
	            break;
	        }
	    }
	   
	else
	{
	   ptr=ptr->next;  
	}
	   
	}
	
	
	if(flag==0)
	{
	    cout<<"\nSorry!!! data not found";
	}
	

}



int main()
{
	int pos,ch,start=1,data,info,new_data;
	node n;
	list l;
	l.create();
	cout<<"\n";
	l.display();
	
	cout<<"\n\n1)Insert\n2)Search\n3)Delete\n4)Update\n5)Exit";
	
	while(start==1)
    {
    	cout<<"\n\nEnter your choice: ";
        cin>>ch;
        
    	 switch(ch)
         {
    	
    	    case 1:
    	    	cout<<"\nEnter position where you want to insert data: ";
    	    	cin>>pos;
    	    	cout<<"Enter data: ";
    	    	cin>>data;
    		    l.insert(pos,data);
    		    cout<<"\nData inserted successfully!!!\n";
    		    l.display();
    		    break;
    		    
    	    
    		case 2:
    			cout<<"Enter data to search: ";
    			cin>>info;
    			l.search(info);
    			break;
    		
    		case 3:
    			cout<<"Enter data that you want to delete: ";
    			cin>>info;
    			
				l.del(info);
				cout<<"\n";
				l.display();
    			break;
    			
    		case 4:
    			cout<<"Enter data that you want to update: ";
    			cin>>info;
    			cout<<"Enter new data: ";
    			cin>>new_data;
    			l.update(info,new_data);
    			cout<<"\n";
    			l.display();
    			break;
    			
    		case 5:
    			cout<<"\nThankyou!!!";
    			break;
    			
    		default:
    		cout<<"\nSorry!!! you have entered wrong choice";
    	 }	
    	
    cout<<"\n\nPress 1 to contionue  or  press any key to exit: ";
    cin>>start;
    
	}
    
 	cout<<"\nThankyou!!!";
	
	return 0;
}
