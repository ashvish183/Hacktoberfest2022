#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;
class Node 
{
    public:
    int data;
    Node *left;
    Node *right;
    Node* create(int data);
};
class Node* create(int data)
{
    class Node *n=new Node;
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
int search(int inorder[],int start,int end,int cur)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==cur)
        return i;
    }
    return -1;
}

Node* buildtree(int preorder[],int inorder[],int start,int end)
{ if(start>end)
 {return NULL;}
    static int ind=0;
    int cur=preorder[ind];
    ind++;
    Node *t=new Node;
    t=create(cur);
    if(start==end)
    return t;
    int pos=search(inorder,start,end,cur);
    t->left=buildtree(preorder,inorder,start,pos-1);
    t->right=buildtree(preorder,inorder,pos+1,end);
    return t;
}
void printinorder(Node* root)
{
     if(root==NULL)
     return;
     printinorder(root->left);
     cout<<root->data<<" ";
     printinorder(root->right);
}
int main()
{ int preorder[]={1,2,4,3,5};
  int inorder[]={4,2,1,5,3};
  
  Node *root=buildtree(preorder,inorder,0,4);
  printinorder(root);
    return 0;
}