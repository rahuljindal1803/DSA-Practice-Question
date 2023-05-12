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
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
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
Node *appendLastNToFirst(Node *head, int n)
{
    if (n == 0 || head == NULL)
    {
        return head;
    }
    Node *Fast = head;
    Node *Slow = head;
    Node *initialhead = head;

    for (int i = 0; i < n; i++)
    {
        Fast = Fast->next;
    }

    while (Fast->next != NULL)
    {
        Slow = Slow->next;
        Fast = Fast->next;
    }
    Node *temp = Slow->next;
    Slow->next = NULL;
    Fast->next = initialhead;
    head = temp;
    return head;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        int n;
        cin >> n;
        head = appendLastNToFirst(head, n);
        print(head);
    }
    return 0;
}