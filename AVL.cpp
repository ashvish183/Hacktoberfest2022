#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
};
Node *newNode(int data)
{
    Node *t = new Node();
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    t->height = 1;
    return (t);
}
int getHeight(Node *p)
{
    if (p == NULL)
        return 0;
    return p->height;
}
int getBalanced(Node *p)
{
    if (p == NULL)
        return 0;
    return getHeight(p->left) - getHeight(p->right);
}
Node *Rightrotation(Node *y)
{
    Node *x = y->left;
    Node *t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Node *Leftrotation(Node *x)
{
    Node *y = x->right;
    Node *t2 = y->left;
    y->left = x;
    x->right = t2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return y;
}

Node *insert(Node *p, int data)
{
    if (p == NULL)
        return (newNode(data));
    if (p->data > data)
    {
        p->left = insert(p->left, data);
    }
    else if (p->data < data)
        p->right = insert(p->right, data);
    else
        return p;
    p->height = 1 + max(getHeight(p->left), getHeight(p->right));
    int balance = getBalanced(p);
    if (balance > 1 && data < p->left->data)
        return Rightrotation(p);

    // Right Right Case
    if (balance < -1 && data > p->right->data)
        return Leftrotation(p);

    // Left Right Case
    if (balance > 1 && data > p->left->data)
    {
        p->left = Leftrotation(p->left);
        return Rightrotation(p);
    }

    // Right Left Case
    if (balance < -1 && data < p->right->data)
    {
        p->right = Rightrotation(p->right);
        return Leftrotation(p);
    }

    /* return the (unchanged) node pointer */
    return p;
}
Node * minValueNode(Node* node)
{
    Node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 
Node *deleteNode(Node *root, int key)
{

    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller
    // than the root's key, then it lies
    // in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater
    // than the root's key, then it lies
    // in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then
    // This is the node to be deleted
    else
    {
        // node with only one child or no child
        if ((root->left == NULL) ||
            (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else               // One child case
                *root = *temp; // Copy the contents of
                               // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            Node *temp = minValueNode(root->right);

            // Copy the inorder successor's
            // data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right,
                                     temp->data);
        }
    }

    // If the tree had only one node
    // then return
    if (root == NULL)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(getHeight(root->left),getHeight(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF
    // THIS NODE (to check whether this
    // node became unbalanced)
    int balance = getBalanced(root);

    // If this node becomes unbalanced,
    // then there are 4 cases

    // Left Left Case
    if (balance > 1 &&
        getBalanced(root->left) >= 0)
        return Rightrotation(root);

    // Left Right Case
    if (balance > 1 &&
        getBalanced(root->left) < 0)
    {
        root->left = Leftrotation(root->left);
        return Rightrotation(root);
    }

    // Right Right Case
    if (balance < -1 &&
        getBalanced(root->right) <= 0)
        return  Leftrotation(root);

    // Right Left Case
    if (balance < -1 &&
        getBalanced(root->right) > 0)
    {
        root->right = Rightrotation(root->right);
        return  Leftrotation(root);
    }

    return root;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /* The constructed AVL Tree would be
             30
            / \
           20 40
           / \ \
          10 25 50
    */
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);
    root=deleteNode(root,10);
    cout << "\nPreorder traversal after"
         << " deletion of 10 \n";
    preOrder(root);
    return 0;
}