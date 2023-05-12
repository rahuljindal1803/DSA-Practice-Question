#include <iostream>
#include <vector>
#include "TreeNode.h"
#include <bits/stdc++.h>
using namespace std;

/*TreeNode<int> *takeInput()
{
    int rootdata;
    cout << "Enter the data:" << endl;
    cin >> rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);

    int n;
    cout << "Enter the children of:" << rootdata << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}
void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

int main()
{
    TreeNode<int> *root = takeInput();
    printTree(root);
}*/

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
/*
TreeNode<int> *TakeInput()
{
    int rootNode;
    cout << "Enter Root Node :" << endl;
    cin >> rootNode;
    TreeNode<int> *root = new TreeNode<int>(rootNode);

    int n;
    cout << "Enter the children of : " << rootNode << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = TakeInput();
        root->children.push_back(child);
    }
    return root;
}*/
/*
void printTree(TreeNode<int> *root)
{
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}
*/

void printTreeLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> pendingNode;
    pendingNode.push(root);

    while (!pendingNode.empty())
    {
        TreeNode<int> *Front = pendingNode.front();
        pendingNode.pop();
        cout << Front->data << ":";

        for (int i = 0; i < Front->children.size(); i++)
        {
            if (i < (Front->children.size() - 1))
            {
                cout << Front->children[i]->data << ",";
            }
            else
            {
                cout << Front->children[i]->data;
            }
            pendingNode.push(Front->children[i]);
        }
        cout << endl;
    }
}
void printTreeorPreoder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        printTreeorPreoder(root->children[i]);
    }
}
int numNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNode(root->children[i]);
    }
    return ans;
}
int sumOfNode(TreeNode<int> *root)
{
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += sumOfNode(root->children[i]);
    }
    return sum;
}
TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    TreeNode<int> *max = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *small = maxDataNode(root->children[i]);
        if (max->data < small->data)
        {
            max = small;
        }
    }
    return max;
}
int getHeight(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int childHeigth = getHeight(root->children[i]);
        if (childHeigth > ans)
        {
            ans = childHeigth;
        }
    }
    return ans + 1;
}
void printAtLevelK(TreeNode<int> *root, int k)
{
    if (k == 0)
    {
        cout << root->data << endl;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}
int times = 0;

int leafNodeCount(TreeNode<int> *root)
{

    if (root == NULL)
    {
        return 0;
    }
    if (root->children.size() == 0)
    {
        times++;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        leafNodeCount(root->children[i]);
    }
    return times;
}
void PostOrder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        PostOrder(root->children[i]);
    }
    cout << root->data << " ";
}
int main()
{

    TreeNode<int> *root = TakeInputLevelwise();
    /*  // printTreeLevelWise(root);
      //  cout << sumOfNode(root);
      TreeNode<int> *ans = maxDataNode(root);
      if (root != NULL)
      {
          cout << ans->data;
      }
      // cout << getHeight(root);
      int k;
      cin >> k;
      printAtLevelK(root, k);
      cout << leafNodeCount(root);

      root = NULL;
      //  cout << numNode(root);*/
    // PostOrder(root);
    // printTreeLevelWise(root);
    printTreeorPreoder(root);

    delete root;
}
// 1 2 2 3 2 4 5 2 6 7 0 0 0 0
