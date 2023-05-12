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

void printLevelATNewLine(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL)
        {
            q.push(first->left);
        }
        if (first->right != NULL)
        {
            q.push(first->right);
        }
    }
}

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

BinaryTreeNode<int> *buildTreeHelper(int *preoder, int *inorder, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    static int idx = end;
    int curr = preoder[idx];
    idx--;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(curr);
    if (start == end)
    {
        return root;
    }
    int pos = search(inorder, start, end, curr);

    root->right = buildTreeHelper(preoder, inorder, pos + 1, end);
    root->left = buildTreeHelper(preoder, inorder, start, pos - 1);
    return root;
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
        cout << "L" << root->left->data;
    }

    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int> *buildTree(int *preorder, int preLength, int *inorder, int inLength)
{
    int start = 0;
    int end = preLength - 1;
    return buildTreeHelper(preorder, inorder, start, end);
}
pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    int heigth = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = heigth;
    p.second = diameter;
    return p;
}
int main()
{
    /* int size;
     cin >> size;
     int *pre = new int[size];
     int *in = new int[size];
     for (int i = 0; i < size; i++)
         cin >> pre[i];
     for (int i = 0; i < size; i++)
         cin >> in[i];
     BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
     printLevelATNewLine(root);*/
    BinaryTreeNode<int> *root = takeInput();
    printTree(root);
    cout << endl;
    pair<int, int> p = heightDiameter(root);
    cout << "Height: " << p.first << endl;
    cout << "Diameter: " << p.second << endl;
    delete root;
}
/*7
4 5 2 6 7 3 1
4 2 5 1 6 3 7
*/
