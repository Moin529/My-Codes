//30
//30
//30
#include <iostream>
using namespace std;

struct node{
    int val;
    node* left;
    node* mid;
    node* right;
    node(int x){
        val = x;
        left = nullptr;
        mid = nullptr;
        right = nullptr;
    }
};

node* find(node* root, int key){
    if(!root){
        return NULL;
    }

    if(root->val == key){
        return root;
    }

    node* found = find(root->left, key);
    if(found){
        return found;
    }

    found = find(root->mid, key);
    if(found){
        return found;
    }

    return find(root->right, key);
}

void print(node* root){
    if(!root){
        return;
    }

    print(root->left);
    print(root->mid);
    cout << root->val << endl;
    print(root->right);
}

int main(){
    int rootvalue, n;
    cin >> rootvalue >> n;
    node* root = new node(rootvalue);
    
    for(int i=0; i<n; i++){
        int op, key, val;
        cin >> op >> key >> val;
        node* parent = find(root, key);

        if(parent){
            node* child = new node(val);

            if(op == 0){
                parent->left = child;
            }

            else if(op == 1){
                parent->mid = child;
            }

            else if(op == 2){
                parent->right = child;
            }
        }
    }

    print(root);
}