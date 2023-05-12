#include <iostream>
#include "binaryTree.h"

#include <queue>
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

pair<int, int> getminandmax(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = root->data;
        p.second = 0;
    }

    pair<int, int> ans;
    ans.first = root->data;
    ans.second = root->data;

    if (root->left != NULL)
    {
        pair<int, int> leftans = getminandmax(root->left);
        ans.first = min(ans.first, leftans.first);
        ans.second = max(ans.second, leftans.second);
    }

    if (root->right != NULL)
    {
        pair<int, int> rightans = getminandmax(root->right);
        ans.first = min(ans.first, rightans.first);
        ans.second = max(ans.second, rightans.second);
    }
    return ans;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    pair<int, int> ans = getminandmax(root);
    cout << ans.first << " " << ans.second;
}
