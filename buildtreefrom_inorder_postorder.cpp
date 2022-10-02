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
Node* buildtree(int postorder[],int inorder[],int start,int end){
static int ind=4;
if(start>end)
 {return NULL;}
int val=postorder[ind];
ind--;
    Node *cur=new Node;
    cur=create(val);
     if(start==end)
     return cur;
     int pos=search(inorder,start,end,val);
     cur->right=buildtree(postorder,inorder,pos+1,end);
      cur->left=buildtree(postorder,inorder,start,pos-1);
 return cur;
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
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int inorder[]={4,2,1,5,3};
int postorder[]={4,2,5,3,1};
Node *root=buildtree(postorder,inorder,0,4);
printinorder(root);
return 0;
}