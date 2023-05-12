/*  ----------------------------------------   ASSIGNMENT   -------------------------------------------------*/
#include <iostream>
#include <vector>
#include "TreeNode.h"
#include <climits>
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
template <typename T>
class maxnode
{
public:
    TreeNode<T> *Node;
    int sum;
};
maxnode<int> *maxNodesumHelper(TreeNode<int> *root)
{
    if (root == NULL)
    {
        maxnode<int> *pair = new maxnode<int>();
        pair->Node = NULL;
        pair->sum = INT_MIN;
        return pair;
    }
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
    }
    maxnode<int> *ans = new maxnode<int>();
    ans->Node = root;
    ans->sum = sum;
    for (int i = 0; i < root->children.size(); i++)
    {
        maxnode<int> *childans = maxNodesumHelper(root->children[i]);
        if (childans->sum > ans->sum)
        {
            ans = childans;
        }
    }
    return ans;
}

TreeNode<int> *maxsumNode(TreeNode<int> *root)
{
    return maxNodesumHelper(root)->Node;
}
int main()
{
    TreeNode<int> *root = TakeInputLevelwise();

    TreeNode<int> *ans = maxsumNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
}