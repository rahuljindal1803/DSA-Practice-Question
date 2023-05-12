#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
#include <climits>
#include <algorithm>

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root)
{

    pair<int, int> p;

    int min = INT_MIN;
    int max = INT_MAX;

    if (root == NULL)
        return p;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {

        BinaryTreeNode<int> *front = q.front();
        q.pop();

        if (front->data > max)
        {
            max = front->data;
        }

        if (front->data < min)
        {
            min = front->data;
        }

        if (front->right)
        {
            q.push(front->right);
        }

        if (front->left)
        {
            q.push(front->left);
        }
    }

    return p;
}

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
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;
}