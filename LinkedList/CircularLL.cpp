

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
    last->next = head;
}

void PrintLL(Node *head)
{
    Node *ptr = head;
    do
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;

    } while (ptr != head);
    cout << "head" << endl;
}

void insertLL(Node *head, int index, int num)
{
    Node *ptr = head;
    while (index > 0)
    {
        ptr = ptr->next;
        index--;
    }
    Node *newNode = new Node;
    newNode->data = num;
    if (ptr == head)
    {
        newNode->next = head;
        head = newNode;
        last->next = newNode;
    }
    else if (ptr->next == head)
    {
        ptr->next = newNode;
        newNode->next = head;
    }
    else
    {
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    PrintLL(head);
}

void deleteLL(Node *head, int num)
{
    Node *ptr = head;
    Node *prev = NULL;
    while (ptr->data != num)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr == head)
    {
        head->next = ptr->next;
        delete (ptr);
    }
    else
    {
        prev->next = ptr->next;
        delete (ptr);
    }
}

int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    CreateLL(A, 5);
    insertLL(head, 0, 12);
    PrintLL(head);
    deleteLL(head, 3);
}