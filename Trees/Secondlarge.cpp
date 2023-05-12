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
template <typename T>
class Secondlargestreturntype
{
public:
    TreeNode<int> *Largest;
    TreeNode<int> *Secondlargest;

    Secondlargestreturntype(TreeNode<T> *first, TreeNode<T> *second)
    {
        this->Largest = first;
        this->Secondlargest = second;
    }
};

Secondlargestreturntype<int> *getsecondlargesthelper(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return new Secondlargestreturntype<int>(NULL, NULL);
    }
    Secondlargestreturntype<int> *ans = new Secondlargestreturntype<int>(root, NULL);
    for (int i = 0; i < root->children.size(); i++)
    {
        Secondlargestreturntype<int> *childans = getsecondlargesthelper(root->children[i]);

        if (childans->Largest->data > ans->Largest->data)
        {
            if (childans->Secondlargest == NULL)
            {
                ans->Secondlargest = ans->Largest;
                ans->Largest = childans->Largest;
            }
            else
            {
                if (childans->Secondlargest > ans->Largest)
                {
                    ans->Secondlargest = childans->Secondlargest;
                    ans->Largest = childans->Largest;
                }
                else
                {
                    ans->Secondlargest = ans->Largest;
                    ans->Largest = childans->Largest;
                }
            }
        }
        else
        {
            if (ans->Largest != childans->Largest && ans->Secondlargest == NULL || childans->Largest > ans->Secondlargest)
            {
                ans->Secondlargest = childans->Largest;
            }
        }
    }
    return ans;
}
TreeNode<int> *getsecondlargesthNode(TreeNode<int> *root)
{
    return getsecondlargesthelper(root)->Secondlargest;
}
int main()
{
    TreeNode<int> *root = takeInputLevelWise();

    TreeNode<int> *ans = getsecondlargesthNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
    else
    {
        cout << INT_MIN;
    }
}