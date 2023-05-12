/*  ----------------------------------------   ASSIGNMENT   -------------------------------------------------*/
//   NodeGreaterthanX
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

int NodeGreaterthanX(TreeNode<int> *root, int x)
{
    int count = 0;
    if (root->data > x)
    {
        count = 1;
    }
    else
    {
        count = 0;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        count += NodeGreaterthanX(root->children[i], x);
    }
    return count;
}
int main()
{
    TreeNode<int> *root = TakeInputLevelwise();
    int x;
    cin >> x;
    cout << NodeGreaterthanX(root, x);
    delete root;
}