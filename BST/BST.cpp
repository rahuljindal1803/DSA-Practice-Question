#include <iostream>
#include <bits/stdc++.h>
#include "BinarySearchTree.h"
#include "NODE.cpp"

using namespace std;

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

bool searchinBST(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == k)
    {
        return root;
    }
    if (root->data > k)
    {
        return searchinBST(root->left, k);
    }
    else
    {
        return searchinBST(root->right, k);
    }
}

void printbtwrange(BinaryTreeNode<int> *root, int k1, int k2)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data > k1)
    {
        printbtwrange(root->left, k1, k2);
    }
    if (root->data >= k1 && root->data <= k2)
    {
        cout << root->data << " ";
    }
    if (root->data <= k2)
    {
        printbtwrange(root->right, k1, k2);
    }
}
bool IsBST(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < min || root->data > max)
    {
        return false;
    }
    bool leftval = IsBST(root->left, min, root->data - 1);
    bool rightval = IsBST(root->right, root->data, max);
    return leftval && rightval;
}

void PreOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

BinaryTreeNode<int> *helper(int *input, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);
    root->left = helper(input, start, mid - 1);
    root->right = helper(input, mid + 1, end);
    return root;
}

BinaryTreeNode<int> *constructTree(int *input, int n)
{
    int start = 0;
    int end = n - 1;
    return helper(input, start, end);
}

Node<int> *constructLinkedList(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node<int> *leftans = constructLinkedList(root->left);
    Node<int> *rightans = constructLinkedList(root->right);
    Node<int> *node = new Node<int>(root->data);

    node->next = rightans;
    if (leftans == NULL)
    {
        return node;
    }
    Node<int> *temp = leftans;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
    return leftans;
}
vector<int> *getPath(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    if (data > root->data)
    {
        vector<int> *rightoutput = getPath(root->right, data);
        rightoutput->push_back(root->data);
        return rightoutput;
    }
    if (data < root->data)
    {
        vector<int> *leftoutput = getPath(root->left, data);
        leftoutput->push_back(root->data);
        return leftoutput;
    }
    else
    {
        return NULL;
    }
}
int main()
{
    //   BinaryTreeNode<int> *root = takeInput();
    /* int k;
     cin >> k;
     cout << ((searchinBST(root, k)) ? "true" : "false");*/
    /*int k1;
    int k2;
    cin >> k1;
    cin >> k2;
    printbtwrange(root, k1, k2);*/
    //   cout << ((IsBST(root)) ? "true" : "false");
    /*   int size;
       cin >> size;
       int *input = new int[size];
       for (int i = 0; i < size; i++)
       {
           cin >> input[i];
       }
       BinaryTreeNode<int> *root = constructTree(input, size);
       PreOrder(root);*/

    /*Node<int> *head = constructLinkedList(root);

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    delete[] root;*/
    /* int k;
      cin >> k;

      vector<int> *output = getPath(root, k);

      if (output != NULL)
      {
          for (int i = 0; i < output->size(); i++)
          {
              cout << output->at(i) << " ";
          }
      }
      delete root;*/
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.insert(15);
    b.print();
}
