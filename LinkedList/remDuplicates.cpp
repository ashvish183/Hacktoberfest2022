// Remove duplicates from a singly linked list

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
#define ll long long
#define sc ;
#define tc ll t sc cin >> t sc while (t--)
#define fast ios::sync_with_stdio(false)
#define spyder cin.tie(NULL)

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void removeDuplicates(Node *head)
{
    Node *current = head;
    Node *next_next;
    if (current == NULL)
        return;
    while (current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            next_next = current->next->next;
            delete (current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
    }
}
void printList(Node *head)
{
    if (head == NULL)
        return;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(20);
    head->next->next->next = new Node(30);
    head->next->next->next->next = new Node(30);
    head->next->next->next->next->next = new Node(30);
    printList(head);
    cout << endl;
    removeDuplicates(head);
    printList(head);
    return 0;
}