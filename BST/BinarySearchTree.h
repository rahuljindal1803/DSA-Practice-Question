#include <iostream>
#include <bits/stdc++.h>
#include "binaryTree.h"
using namespace std;
class BST
{
    BinaryTreeNode<int> *root;

private:
    bool hasData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return false;
        }
        if (root->data == data)
        {
            return true;
        }
        if (data > root->data)
        {
            return hasData(data, node->right);
        }
        else
            return hasData(data, node->left);
    }
    BinaryTreeNode<int> *deletepath(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (data > root->data)
        {
            node->right = deletepath(data, node->right);
            return node;
        }
        else if (data < root->data)
        {
            node->left = deletepath(data, node->left);
            return node;
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                BinaryTreeNode<int> *temp = root->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode<int> *temp = root->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minnode = node->right;
                while (minnode->left != NULL)
                {
                    minnode = minnode->left;
                }
                int rightmin = minnode->data;
                node->data = rightmin;
                node->right = deletepath(data, root->right);
                return node;
            }
        }
    }

    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (data <= node->data)
        {
            node->left = insert(data, node->left);
        }
        else
        {
            node->right = insert(data, node->right);
        }
        return node;
    }
    void printTree(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << ":";
        if (root->left != NULL)
        {
            cout << "L:" << root->left->data << ",";
        }

        if (root->right != NULL)
        {
            cout << "R:" << root->right->data;
        }
        cout << endl;
        printTree(root->left);
        printTree(root->right);
    }

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }
    bool hasData(int data)
    {
        return hasData(data, root);
    }
    void deletepath(int data)
    {
        root = deletepath(data, root);
    }
    void print()
    {
        printTree(root);
    }
    void insert(int data)
    {
        this->root = insert(data, this->root);
    }
};