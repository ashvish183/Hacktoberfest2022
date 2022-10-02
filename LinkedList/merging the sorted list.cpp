#include <iostream>
using namespace std;
struct Node{
    int data;
     Node *next;
}*first=NULL,*second=NULL,*third=NULL; 
void create(int a[],int n){
     Node *t,*last;
    first=new Node;
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new  Node;
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void create1(int b[],int n){
     Node *t,*last;
    second=new Node;
    second->data=b[0];
    second->next=NULL;
    last=second;
    for(int i=1;i<n;i++){
        t=new  Node;
        t->data=b[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void concat(Node *p,Node *q){
    third=p;
    while(p->next!=NULL)
    p=p->next;
     
     p->next=q;
}
void merge(struct Node *p,struct Node *q){
    struct Node *last;
    if(p->data<q->data)
    {
        third=last=p;
        p=p->next;
        last->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        last->next=NULL;
    }
    while(p!=NULL&&q!=NULL)
    {
        if(p->data<q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p!=NULL) last->next=p;
    if(q) last->next=q;
}
void display(struct Node *p)
{while(p!=NULL)
  {cout<<p->data<<" ";
    p=p->next;
  }
}
int main()
{int a[]={1,4,7,9,15};
 int b[]={2,6,8,10,12};
 create(a,5);
 create1(b,5);
// concat(first,second);
// display(third);
 merge(first,second);
 display(third);
    return 0;
}

