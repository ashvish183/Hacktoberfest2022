#include<bits/stdc++.h>
using namespace std;
template<typename t>
class node
{
public:
t data;
node *left;
node *right;
node(t data)
{
    this->data=data;
    left=NULL;
    right=NULL;
}
};
node <int>*takeinput()
{
    int rootdata;
    cout<<"enter the root data"<<endl;
    cin>>rootdata;
    node<int>*root=new node<int>(rootdata);
    queue<node<int>*>q;
    q.push(root);
    while(!q.empty())
    {
        node<int>*front=q.front();
        q.pop();
        cout<<"enter the left child data of "<<front->data<<endl;
        cin>>rootdata;
        if(rootdata!=-1)
        {
            node<int>*child=new node<int>(rootdata);
            front->left=child;
            q.push(child);
        }
          cout<<"enter the right child data of "<<front->data<<endl;
        cin>>rootdata;
        if(rootdata!=-1)
        {
            node<int>*child=new node<int>(rootdata);
            front->right=child;
            q.push(child);
        }
    }
    return root;
}
void display(node<int>*root)
{
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}
void insertnode(node<int>*root,int data)
{
node <int>*newnode=new node<int>(data);
queue<node<int>*>q;
q.push(root);
while(!q.empty())
{
    node<int>*front=q.front();
    q.pop();
    if(!front->left)
    {
        front->left=newnode;
        return;
    }
    else if( !front->right)
    {
        front->right=newnode;
        return;
    }
else{
q.push(front->left);
    q.push(front->right);
}   
}
}
int main()
{
node<int>*root=takeinput();
insertnode(root,50);
display(root);
}