#include <iostream>
using namespace std;
#include "NODE.cpp"

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *Tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            Tail = newNode;
        }
        else
        {
            Tail->next = newNode;
            Tail = Tail->next;
            //or Tail=newNode;
        }
        cin >> data;
    }
    return head;
}
Node *InsertNode(Node *head, int i, int data)
{
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;
    if (head = NULL)
    {
        return head;
    }
    if (i == 0)
    {

        return head->next;
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

Node *DeleteNode(Node *head, int i, int data)
{
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;

    if (i == 0)
    {

        return head->next;
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        Node *a = temp->next;
        Node *b = a->next;
        temp->next = b;
    }
    if (head = NULL)
    {
        return head;
    }
    return head;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    Node *head = takeInput();
    print(head);
    int i, data;
    cin >> i;
    head = DeleteNode(head, i, data);
    print(head);
}