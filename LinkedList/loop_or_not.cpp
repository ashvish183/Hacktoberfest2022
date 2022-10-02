#include <iostream>
using namespace std;
struct Node{
    int data;
     Node *next;
}*first=NULL; 
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
bool isloop(struct Node *f){
    Node *p,*q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q=(q!=NULL)?q->next:q;
    }while(p&&q&&p!=q);
    if(p==q) return 1;
    else return 0;
}
void display(struct Node *p)
{while(p!=NULL)
  {cout<<p->data<<" ";
    p=p->next;
  }
}
int main()
{ Node *t1,*t2;
int a[]={1,2,3,4,5};
create(a,5);
 t1=first->next->next;
 t2=first->next->next->next->next;
 t2->next=t1;
 int r=isloop(first);
 cout<<r;
    return 0;
}

