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
    queue<Node *> q;
    cout << "enter data for root node: " << endl;
    int val;
    cin >> val;
    root = new Node(val);
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data<< endl;
        int val1;
        cin >> val1;
        if (val1 != -1)
        {
            temp->left = new Node(val1);
            q.push(temp->left);
        }
        cout << "Enter right node for: " << temp->data<< endl;
        int val2;
        cin >> val2;
        if (val2 != -1)
        {
            temp->right = new Node(val2);
             q.push(temp->right);
        }
    }
    return root;
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
    cout<<endl;
    cout<<"BFS TRAVERSAL FOR THE TREE"<<endl;
    bfs(root);
    cout << endl;
    return 0;
}