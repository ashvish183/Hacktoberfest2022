#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        this->data=x;
        this->left=NULL;
        this->right=nullptr;
    }
};
int sum(Node *root)
{
    if(!root) return 0;
    return root->data+sum(root->left)+sum(root->right);
}
bool sumTree(Node *root)
{
    if(!root || (!root->left and !root->right))
    return 1;
    int leftSum=sum(root->left);
    int rightSum=sum(root->right);
    if(root->data==leftSum+rightSum and sumTree(root->left) and sumTree(root->right))
    return 1;
    return 0;
}
bool flag;
int sumTree1(Node *root)
{
    if(root==NULL) return 0;
    if(root->left==NULL and root->right==NULL)
    return root->data;
  int l=sumTree1(root->left);
  int r=sumTree1(root->right);
  if(root->data!=l+r)
  {
  flag=false;
  }
  return root->data+l+r;
}
int main()
{
    Node *root=new Node(26);
    root->left=new Node(10);
    root->right=new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);
   flag=true;
   sumTree1(root);
    if(flag)
    {
        cout<<"Yes\n";
    }
    else
    cout<<"No\n";
    return 0;
}