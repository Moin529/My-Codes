#include <iostream>
#include <queue>  // for level order traversal
using namespace std;

struct node{
    int value;
    node *left;
    node *right;
    node(int x){
        value = x;
        left = nullptr;
        right = nullptr;
    }
};

void inorderTraversal(node *root){
    if(root == nullptr){
        return;
    }
    inorderTraversal(root->left);
    cout << root->value << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(node *root){
    if(root == nullptr){
        return;
    }
    cout << root->value << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(node *root){
    if(root == nullptr){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->value << " ";
}

void levelOrderTraversal(node *root){
    if(root == nullptr){
        return;
    }
    queue <node*> q;
    q.push(root);
    while(!q.empty()){
        node * temp = q.front();
        q.pop();
        cout << temp->value << " ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left->left = new node(8);
    root->left->left->right = new node(9);
    root->left->right->right = new node(10);
    cout << "Inorder Traversal: " << endl;
    inorderTraversal(root);
    cout << "\nPreorder Traversal: " << endl;
    preorderTraversal(root);
    cout << "\nPostorder Traversal: " << endl;
    postorderTraversal(root);
    cout << "\nLevel Order Traversal: " << endl;
    levelOrderTraversal(root);
}