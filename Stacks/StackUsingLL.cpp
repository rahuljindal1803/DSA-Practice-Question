#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)

    {
        this->data = data;
        next = NULL;
    }
};
template <typename T>
class stack
{
    Node<T> *head;
    int size;

public:
    stack()
    {
        head = NULL;
        size = 0;
    }
    int getsize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void push(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        if (head == NULL)
        {
            newNode->next = NULL;
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    T pop()
    {
        if (isEmpty())
        {
            return 0;
        }
        else
        {
            T ans = head->data;
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            size--;
            return ans;
        }
    }
    T top()
    {
        if (isEmpty())
        {
            return 0;
        }
        else
        {
            return head->data;
        }
    }
};