/*Invert A binary Tree*/
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *root = NULL;
Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void insertNode(int data)
{
    Node *newNode = createNode(data);
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        else
        {
            temp->left = newNode;
            return;
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
        else
        {
            temp->right = newNode;
            return;
        }
    }
}
void invertTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    invertTree(root->left);
    invertTree(root->right);
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}
void printTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}
int main()
{
    int n;
    cout << "Enter the Number of Nodes= ";
    cin >> n;
    cout << "Enter the Nodes= ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertNode(x);
    }
    cout << "\nBefore Inverting Tree= ";
    printTree(root);
    invertTree(root);
    cout << "\nAfter Inverting Tree= ";
    printTree(root);
}
