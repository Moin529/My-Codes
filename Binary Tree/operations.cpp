#include <iostream>
using namespace std;

//Binaray Search Tree Operation

struct Node{
    int value;
    Node *left;
    Node *right;
    Node(int x){
        value = x;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int key){
    if(root == nullptr){
        return new Node(key);
    }

    if(key < root->value){
        root->left = insert(root->left, key);
    }
    else if(key > root->value){
        root->right = insert(root->right, key);
    }

    return root;
}

Node* findMin(Node *root){
    while(root != nullptr){
        root = root->left;
    }
    return root;
}

Node* findMax(Node *root){
    while(root != nullptr){
        root = root->right;
    }
    return root;
}

Node* deleteNodeFromRight(Node *root, int key){
    if(root == nullptr){
        return root;
    }

    if(key < root->value){
        root->left = deleteNodeFromRight(root->left, key);
    }

    else if(key > root->value){
        root->right = deleteNodeFromRight(root->right, key);
    }
    else{
        if(root->left == nullptr){
            Node *temp = root->right;
            delete root;
            return temp;
        }

        else if(root->right == nullptr){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *curr = findMin(root->right);
        root->value = curr->value;
        root->right = deleteNodeFromRight(root->right, curr->value);
    }
}

Node* deleteNodeFromLeft(Node *root, int key){
    if(root == nullptr){
        return root;
    }

    if(key < root->value){
        root->left = deleteNodeFromLeft(root->left, key);
    }

    else if(key > root->value){
        root->right = deleteNodeFromLeft(root->right, key);
    }
    else{
        if(root->left == nullptr){
            Node *temp = root->right;
            delete root;
            return temp;
        }

        else if(root->right == nullptr){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *curr = findMax(root->left);
        root->value = curr->value;
        root->left = deleteNodeFromLeft(root->left, curr->value);
    }
}

bool find(Node *root, int key){
    if(root == nullptr){
        return false;
    }
    if(key > root->value){
        return find(root->right, key);
    }

    else if(key < root->value){
        return find(root->left, key);
    }
    else{
        return true;
    }
}

int main() {

    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout<<find(root, 40)<<endl;
    cout<<find(root, 41)<<endl;

    root = deleteNodeFromRight(root, 40);
    
    cout<<find(root, 40)<<endl;

    return 0;
}