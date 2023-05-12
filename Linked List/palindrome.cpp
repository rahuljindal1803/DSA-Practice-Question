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

/* Time Complexity : O(n) Space Complexity : O(1) where n is the size of singly linked list */
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
    }
    Node *fast = head;
    Node *slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    // reverse
    Node *secondHead = slow->next;
    slow->next = NULL;
    secondHead = reverseLinkedList(secondHead);
    // compare
    Node *firstsublist = head;
    Node *secondsublist = secondHead;
    bool ans = true;
    while (secondsublist != NULL)
    {
        if (firstsublist->data != secondsublist->data)
        {
            ans = false;
            break;
        }
        firstsublist = firstsublist->next;
        secondsublist = secondsublist->next;
    } // rejoin
    firstsublist = head;
    secondsublist = reverseLinkedList(secondHead);
    while (firstsublist->next != NULL)
    {
        firstsublist = firstsublist->next;
    }
    firstsublist->next = secondsublist;

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

        if (ans = true)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }

    return 0;
}