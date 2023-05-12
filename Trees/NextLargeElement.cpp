/*  ----------------------------------------   ASSIGNMENT   -------------------------------------------------*/
#include <iostream>
#include <vector>
#include "TreeNode.h"
#include <bits/stdc++.h>
using namespace std;

TreeNode<int> *takeInputLevelWise()
{
    int rootNode;
    cout << "Enter Root Node : " << endl;
    cin >> rootNode;
    TreeNode<int> *root = new TreeNode<int>(rootNode);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numchild;
        cin >> numchild;
        for (int i = 0; i < numchild; i++)
        {
            int childdata;
            cin >> childdata;
            TreeNode<int> *child = new TreeNode<int>(childdata);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
TreeNode<int> *getnextLargeElement(TreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return 0;
    }
    TreeNode<int> *nextlarge = NULL;
    if (root->data > x)
    {
        nextlarge = root;
    }
    for (int i = 0; i < root->children.size(); i++)
    {

        TreeNode<int> *smallans = getnextLargeElement(root->children[i], x);
        if (nextlarge == NULL)
        {
            nextlarge = smallans;
        }
        else if (smallans != NULL && smallans->data < nextlarge->data)
        {
            nextlarge = smallans;
        }
        cout << getnextLargeElement(root->children[i], x) << endl;
    }
    return nextlarge;
}
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    int x;
    cin >> x;
    TreeNode<int> *ans = getnextLargeElement(root, x);

    if (ans != NULL)
    {
        cout << "NextLargetElement is: " << ans->data;
    }
    delete root;
}
// 10 3 20 30 40 2 50 60 0 0 0 0