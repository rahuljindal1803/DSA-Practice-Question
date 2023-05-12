/*  ----------------------------------------   ASSIGNMENT   -------------------------------------------------*/
#include <iostream>
#include <vector>
#include "TreeNode.h"
#include <bits/stdc++.h>
using namespace std;

TreeNode<int> *TakeInputLevelwise()
{
    int rootNode;
    cout << "Enter Root Node :" << endl;
    cin >> rootNode;
    TreeNode<int> *root = new TreeNode<int>(rootNode);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter no of children of " << front->data << endl;
        int numchild;
        cin >> numchild;
        for (int i = 0; i < numchild; i++)
        {
            int childdata;
            cout << "enter " << i << "th child of " << front->data << endl;
            cin >> childdata;
            TreeNode<int> *child = new TreeNode<int>(childdata);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
void printLevelATNewLine(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() != 0)
    {
        TreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL)
        {
            if (q.size() == 0)
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        for (int i = 0; i < first->children.size(); i++)
        {
            q.push(first->children[i]);
        }
    }
}

void helper(TreeNode<int> *root, int depth)
{
    root->data = depth;
    for (int i = 0; i < root->children.size(); i++)
    {
        helper(root->children[i], depth + 1);
    }
}
void replacewithdepth(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    helper(root, 0);
}
int main()
{
    TreeNode<int> *root = TakeInputLevelwise();
    replacewithdepth(root);
    printLevelATNewLine(root);
}