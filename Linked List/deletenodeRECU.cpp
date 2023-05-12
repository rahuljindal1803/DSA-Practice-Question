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
Node *deleteNodeRec(Node *head, int i)
{
    if (head == NULL)
        return NULL;

    if (i == 0)
    {
        /* Node *a = temp->next;
         Node *b = a->next;
         temp->next = b;
         delete a;*/
        Node *temp = head;
        head = temp->next;
        delete temp;

        return head;
    }

    Node *small = deleteNodeRec(head->next, i - 1);

    head->next = small;
    return head;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        int pos;
        cin >> pos;
        head = deleteNodeRec(head, pos);
        print(head);
    }

    return 0;
}