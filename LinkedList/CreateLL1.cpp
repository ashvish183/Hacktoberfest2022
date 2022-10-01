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

void CountLL(Node *head)
{
    Node *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    cout << count << endl;
}

void SumLL(Node *head)
{
    Node *ptr = head;
    int sum = 0;
    while (ptr != NULL)
    {
        sum += ptr->data;
        ptr = ptr->next;
    }
    cout << sum << endl;
}

void MaxLL(Node *head)
{
    Node *ptr = head;
    int max = 0;
    while (ptr != NULL)
    {
        if (ptr->data > max)
        {
            max = ptr->data;
        }
        ptr = ptr->next;
    }
    cout << max << endl;
}

void LinearSearchLL(Node *head, int num)
{
    Node *ptr = head;
    bool found = 0;
    while (ptr != NULL)
    {
        if (ptr->data == num)
        {
            cout << "Num found" << endl;
            found = 1;
        }
        ptr = ptr->next;
    }
    if (found == 0)
        cout << "Num not found";
}

void MTFLinearSearchLL(Node *head, int num)
{
    Node *ptr = head;
    Node *prev = NULL;
    bool found = 0;
    while (ptr != NULL)
    {
        if (ptr->data == num)
        {
            prev->next = ptr->next;
            ptr->next = head->next;
            head = ptr;
            cout << "Num found" << endl;
            found = 1;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    if (found == 0)
        cout << "Num not found";
}

void InsertLL(Node *head, int index, int num)
{
    Node *ptr = head;
    while (index > 0)
    {
        ptr = ptr->next;
        index--;
    }
    Node *newNode = new Node;
    newNode->data = num;
    newNode->next = ptr->next;
    ptr->next = newNode;
    if (newNode->next == NULL)
    {
        last = newNode;
    }
    if (index == 0)
    {
        head = newNode;
    }
}

void InsertatLastLL(Node *head, int num)
{
    Node *newNode = new Node;
    newNode->data = num;
    newNode->next = NULL;
    last->next = newNode;
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
    prev->next = ptr->next;
    delete (ptr);
}

void checkSorted(Node *head)
{
    Node *ptr = head;
    int min = 0;
    static bool flag = 1;
    while (ptr != NULL)
    {
        if (ptr->data < min)
        {
            cout << "Unsorted Array";
            flag = 0;
            break;
        }
        min = ptr->data;
        ptr = ptr->next;
    }
    if (flag == 1)
        cout << "Sorted";
}

void removeDuplicateLL(Node *head)
{
    Node *ptr = head->next;
    Node *prev = head;
    while (ptr != NULL)
    {
        if (prev->data != ptr->data)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = ptr->next;
        delete (ptr);
        ptr = prev->next;
    }
}

void ReverseLL(Node *head)
{
    Node *p = head;
    Node *q = NULL;
    Node *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
    PrintLL(head);
}

int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    CreateLL(A, 5);
    // MTFLinearSearchLL(head, 4);
    // InsertLL(head, 2, 12);
    // InsertatLastLL(head, 17);
    // PrintLL(head);
    // removeDuplicateLL(head);
    // deleteLL(head,4);
    ReverseLL(head);
    // PrintLL(head);
    // checkSorted(head);
}