#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
// This function should return head to the DLL
class Solution
{
public:
    // Function to convert binary tree to doubly linked list and return it.
    Node *prev = NULL;
    Node *bToDLL(Node *root)
    {
        // your code here
        if (!root)
            return root;

        Node *head = bToDLL(root->left);

        if (prev == NULL)
            head = root;
        else
        {
            prev->right = root;
            root->left = prev;
        }
        prev = root;

        bToDLL(root->right);
        return head;
    }
    // method 2 
    // using _SPACE
     public: 
   //Function to convert binary tree to doubly linked list and return it.
   vector<int> v;
   void inOrder(Node *root){
       if(!root)
           return;
       else{
           inOrder(root->left);
           v.push_back(root->data);
           inOrder(root->right);
       }
   }
   Node * bToDLL(Node *root)
   {
       inOrder(root);
       int n = v.size();
       Node *head = new Node();
       head->data = v[0];
       Node *temp = head;
       head->right = NULL;
       head->left = NULL;
       for(int i=1;i<n;i++){
           Node *k = new Node();
           k->data = v[i];
           k->left = temp;
           k->right = NULL;
           temp->right = k;
           temp = k;
       }
       return head;   
   }
};
