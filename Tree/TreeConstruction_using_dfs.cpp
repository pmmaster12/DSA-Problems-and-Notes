#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *TreeConstruction(Node *root)
{
    int val;
    cout << "enter the value of node :";
    cin >> val;
    if (val == -1)
    {
        root = NULL;
        return root;
    }
    Node *temp = new Node(val);
    root = temp;
    root->left = TreeConstruction(root->left);
    root->right = TreeConstruction(root->right);
    return root;
}
void dfs(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    dfs(root->left);
    dfs(root->right);
    return;
}
void bfs(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> level;
    level.push(root);
    level.push(NULL);
    while (!level.empty())
    {
        Node *temp = level.front();
        level.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!level.empty())
            {
                level.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left != NULL)
                level.push(temp->left);
            if (temp->right != NULL)
                level.push(temp->right);
        }
    }
    return;
}
int main()
{

    // constructing tree
    Node *root = NULL;
    root = TreeConstruction(root);
    dfs(root);
    cout << endl;
    bfs(root);
    return 0;
}