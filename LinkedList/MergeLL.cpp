#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} * head, *head2, *newHead, *last = NULL;

void createLL(int *A)
{
    Node *firstNode = new Node;
    firstNode->data = A[0];
    firstNode->next = NULL;
    head = firstNode;
    last = head;

    for (int i = 1; i < 4; i++)
    {
        Node *newNode = new Node;
        newNode->data = A[i];
        newNode->next = NULL;
        last->next = newNode;
        last = newNode;
    }
}
void createLL2(int *A)
{
    Node *firstNode = new Node;
    firstNode->data = A[0];
    firstNode->next = NULL;
    head2 = firstNode;
    last = head2;

    for (int i = 1; i < 4; i++)
    {
        Node *newNode = new Node;
        newNode->data = A[i];
        newNode->next = NULL;
        last->next = newNode;
        last = newNode;
    }
}

void MergeLL(Node *head, Node *head2)
{
    Node *ptr1 = head;
    Node *ptr2 = head2;
    Node *prev = NULL;

    if (ptr1->data < ptr2->data)
    {
        prev = newHead = ptr1;
        ptr1 = ptr1->next;
        prev->next = NULL;
    }
    else
    {
        prev = newHead = ptr2;
        ptr2 = ptr2->next;
        prev->next = NULL;
    }
    while (ptr1 && ptr2)
    {
        if (ptr1->data < ptr2->data)
        {
            prev->next = ptr1;
            prev = ptr1;
            ptr1 = ptr1->next;
            prev->next = NULL;
        }
        else
        {
            prev->next = ptr2;
            prev = ptr2;
            ptr2 = ptr2->next;
            prev->next = NULL;
        }
    }
    if (ptr1)
        prev->next = ptr1;

    if (ptr2)
        prev->next = ptr2;
}

void PrintLL(Node *newHead)
{
    Node *ptr = newHead;
    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    int A[4] = {2, 8, 15, 16};
    int B[4] = {4, 7, 14, 20};

    createLL(A);
    createLL2(B);

    MergeLL(head, head2);
    PrintLL(newHead);
}