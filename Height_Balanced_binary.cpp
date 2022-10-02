#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;
class Node{
   public:
    int data;
    Node* left;
Node* right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
int height(Node *root)
{
    if(root==NULL)
    return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}
bool isbalanced(Node *root)
{
 if(root==NULL)
 return true;
 if(isbalanced(root->left)==false)
 { return false;

 }
 if(isbalanced(root->right)==false)
 return false;
 int lh=height(root->left);
 int rh=height(root->right);
 if(abs(lh-rh)<=1)
 return true;
 else
 {
     return false;

 }
 
}
bool isbalanced1(Node *root,int *height)
{int lh,rh=0;
 if(root==NULL)
 return true;
 
 if(isbalanced1(root->left,&lh)==false)
 { return false;

 }
 if(isbalanced1(root->right,&rh)==false)
 return false;

   *height=max(lh,rh)+1;
 if(abs(lh-rh)<=1)
 return true;
 else
 {
     return false;

 }
 
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 Node *root=new Node(1);
 root->left=new Node(2);
 root->right=new Node(3);
 root->left->left=new Node(4);
 root->left->right=new Node(5);
 root->right->left=new Node(6);
root->right->right=new Node(7);
/*
             1
            /  \
           2    3
          / \  / \
          4 5  6  7

*/
int height=0;
if(isbalanced1(root,&height)==true)
cout<<"Balanced";
else
{
    cout<<"Not Balanced";
}

return 0;
}