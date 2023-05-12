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
Node *reverseLinkedList(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *fwd = NULL;
    while (curr != NULL)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    } // Find center of list
    Node *fast = head;
    Node *slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *secondHead = slow->next;
    slow->next = NULL;
    secondHead = reverseLinkedList(secondHead);
    // Compare the two sublists
    Node *firstSubList = head;
    Node *secondSubList = secondHead;
    bool ans = true;
    while (secondSubList != NULL)
    {
        if (firstSubList->data != secondSubList->data)
        {
            ans = false;
            break;
        }
        firstSubList = firstSubList->next;
        secondSubList = secondSubList->next;
    }
    // Rejoin the two sublists
    firstSubList = head;
    secondSubList = reverseLinkedList(secondHead);
    while (firstSubList->next != NULL)
    {
        firstSubList = firstSubList->next;
    }
    firstSubList->next = secondSubList;
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        bool ans = isPalindrome(head);

        if (ans)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }

    return 0;
}