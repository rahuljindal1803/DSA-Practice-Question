#include <iostream>
#include "NODE.cpp"
using namespace std;

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *reverseLinkedListrec(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *smallhead = reverseLinkedListrec(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallhead;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        Node *reverse = reverseLinkedListrec(head);
        print(reverse);
    }
    return 0;
}