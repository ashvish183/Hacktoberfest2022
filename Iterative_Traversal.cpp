//NOT COMPLETE
#include <bits/stdc++.h>
using namespace std;
struct Node{
Node *lchild;
int data;
Node *rchild;
};
struct Queue
{
    int size;
    int front;
    int rear;
    
    Node **Q;
};
void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (Node **)malloc(q->size * sizeof(Node *));
}
void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
        cout << "Queue is Full";
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}
Node *Deque(struct Queue *q)
{
    Node *x = NULL;
    if (q->rear == q->front)
        cout << "Queue is empty";
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}
void Display(struct Queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++)
    {
        cout << q.Q[i] << " ";
    }
    cout << endl;
}

struct Stack{
    int size;
    int top;
    struct Node **S;
};
void Stackcreate(Stack *st,int size)
{
    st->size=size;
    st->top=-1;
    st->S=new Node;

}
void push(Stack *st,Node *x)
{
    if(st->top==st->size-1)
    {
        cout<<"Stack Overflow";
    }
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}
struct Node *pop(Stack *st)
{
    Node *x=NULL;
    if(st->top==-1)
    {
        cout<<"Stack underflow";

    }
    else
    {
      x=st->S[st->top--];
    }
    return x;
}
int isemptystack(Stack st)
{
    if(st.top==-1)
    return 1;
    return 0;
}

void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    cout<<"Eneter root value ";
    cin>>x;
    root = new Node//(struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
    cout<<"enter left child of "<<p->data;
        cin>>x;
        if (x != -1)
        {
            t = new Node//(struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        cout<<"enter right child of "<<p->data;
        cin>>x;
        if (x != -1)
        {
            t = new Node//(struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}
void preorder(struct Node *p)
{
    struct stack stk;
    Stackcreate(&stk,100);
    while(p||!isemptystack(stk))
    {
        if(p)
        {
            cout<<p->data;
            push(&stk,p);
            p=p->lchild;
        }
        else
        {
            p=pop(&stk);
            p=p->rchild;
        }
    }
}
void IInorder(struct Node *p)
{
 struct Stack stk;
 Stackcreate(&stk,100);
 
 while(p || !isEmptyStack(stk))
 {
 if(p)
 {
 push(&stk,p);
 p=p->lchild;
 }
 else
 {
 p=pop(&stk);
 cout<<p->data;
 p=p->rchild;
 }
 }
}
int main()
{Treecreate();

 preorder(root);
    return 0;
}