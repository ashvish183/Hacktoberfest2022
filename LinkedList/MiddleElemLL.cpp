#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} * head, *last = NULL;

void CreateLL(int *A, int n)
{
    Node *firstNode = new Node;
    firstNode->data = A[0];
    firstNode->next = NULL;
    head = firstNode;
    last = head;

    for (int i = 1; i < n; i++)
    {
        Node *newNode = new Node;
        newNode->data = A[i];
        newNode->next = NULL;
        last->next = newNode;
        last = newNode;
    }
}

void PrintLL(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

void MiddleLL(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast)
    {
        fast = fast->next;
        if (fast)
            fast = fast->next;
        if (fast)
            slow = slow->next;
    }
    cout << slow->data;
}

int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    CreateLL(A, 5);
    MiddleLL(head);
    // PrintLL(head);
}