#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define PB push_back
typedef long long ll;
#define endl "\n"

using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Tree
{
private:
    Node *root;

public:
    Tree();
    void CreateTree();
    void Preorder(Node *p);
    void Preorder() { Preorder(root); }
    void Inorder(Node *p);
    void Inorder() { Inorder(root); }
    void Postorder(Node *p);
    void Postorder() { Postorder(root); }
    void Levelorder(Node *p);
    void Levelorder() { Levelorder(root); }
    int Height(Node *p);
    int Height() { return Height(root); }
};

Tree::Tree()
{
    root = NULL;
}

void Tree::CreateTree()
{
    Node *p;
    Node *t;
    int x;
    queue<Node *> q;

    root = new Node;
    cout << "Enter root data : ";
    cin >> x;
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    q.emplace(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        cout << "Enter left child data of [-1 if you don't want] " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            q.emplace(t);
        }

        cout << "Enter right child data of [-1 if you don't want] " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->rchild = t;
            q.emplace(t);
        }
    }
}

void Tree::Preorder(Node *p)
{
    if (p)
    {
        cout << p->data << ", ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << ", ";
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << endl;
    }
}

void Tree::Levelorder(Node *p)
{
    queue<Node *> q;
    cout << root->data << ", ";
    q.emplace(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        if (p->lchild)
        {
            cout << p->lchild->data << ", ";
            q.emplace(p->lchild);
        }

        if (p->rchild)
        {
            cout << p->rchild->data << ", ";
            q.emplace(p->rchild);
        }
    }
}

int Tree::Height(Node *p)
{
    int l = 0;
    int r = 0;
    if (p == NULL)
    {
        return 0;
    }

    l = Height(p->lchild);
    r = Height(p->rchild);

    if (l > r)
    {
        return l + 1;
    }
    else
    {
        return r + 1;
    }
}

int main()
{

    Tree bt;

    bt.CreateTree();
    cout << endl;

    cout << "Preorder : " << endl;
    bt.Preorder();
    cout << endl;

    cout << "Inorder : " << endl;
    bt.Inorder();
    cout << endl;

    cout << "Postorder : " << endl;
    bt.Postorder();
    cout << endl;

    cout << "Levelorder : " << endl;
    bt.Levelorder();
    cout << endl;

    cout << "Height : " << bt.Height() << endl;

    return 0;
}
