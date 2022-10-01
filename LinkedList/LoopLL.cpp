#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} * head, *slow, *fast = NULL;

void createLL(int *A)
{
    Node *one = new Node;
    Node *two = new Node;
    Node *three = new Node;
    Node *four = new Node;
    Node *five = new Node;

    one->data = A[0];
    two->data = A[1];
    three->data = A[2];
    four->data = A[3];
    five->data = A[4];

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = two;

    head = one;
}

void isLoop(Node *head)
{
    slow = fast = head;
    do
    {
        fast = fast->next;
        slow = slow->next;
        fast = fast ? fast->next : NULL;
    } while ((slow && fast) && slow != fast);

    if (slow == fast)
    {
        cout << "Cicular LL" << endl;
    }
    else
    {
        cout << "Hehe";
    }
}

int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    createLL(A);
    isLoop(head);
}