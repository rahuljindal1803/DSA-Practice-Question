/*  ----------------------------------------   ASSIGNMENT   -------------------------------------------------*/
#include <iostream>
#include <vector>
#include "TreeNode.h"
#include <bits/stdc++.h>
using namespace std;

TreeNode<int> *takeInputLevelWise()
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
bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 != NULL && root2 == NULL || root1 == NULL && root2 != NULL)
    {
        return false;
    }
    if (root1->data != root2->data || root1->children.size() != root2->children.size())
    {
        return false;
    }

    for (int i = 0; i < root1->children.size(); i++)
    {
        TreeNode<int> *child1 = root1->children[i];
        TreeNode<int> *child2 = root2->children[i];
        if (!areIdentical(child1, child2))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    TreeNode<int> *root1 = takeInputLevelWise();
    TreeNode<int> *root2 = takeInputLevelWise();
    cout << (areIdentical(root1, root2) ? "true" : "false");
}