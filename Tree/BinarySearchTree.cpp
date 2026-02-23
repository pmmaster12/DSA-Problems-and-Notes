#include<iostream>
using namespace std;

class Node{

    public:
        int data;
        Node* left;
        Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insert_node(Node* root, int data){
    
    //base case
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data < root->data){
        root->left = insert_node(root->left,data);
    }
    else{
        root->right = insert_node(root->right,data);
    }
    return root;
}

Node* take_input(Node* root){

    int data;
    cin>>data;
    
    while(data!=-1){
            root = insert_node(root,data);
            cin>>data;
    }
    return root;
}



void dfs(Node* root){
    if(root == NULL)
        return;
    
    cout<<root->data<<endl;
    dfs(root->left);
    dfs(root->right);

    return;
}

Node* min_node(Node* root){
    Node* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}

Node* max_node(Node* root){
    Node* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp;
}

int main(){
    
    Node* root = NULL;
    cout<<"Taking input for BST Construction "<<endl;
    root = take_input(root);

    cout<<"dfs traversal of tree"<<endl;
    dfs(root);

    cout<<"min node in bst is -> "<<min_node(root)->data<<endl;
    cout<<"max node in bst is -> "<<max_node(root)->data<<endl;
    return 0;
}