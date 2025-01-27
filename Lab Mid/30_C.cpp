//30
#include <iostream>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int x){
        val = x;
        left = nullptr;
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

    node* leftSearch = find(root->left, key);
    if(leftSearch != nullptr){
        return leftSearch;
    }
    return find(root->right, key);
}

bool areEqual(node* root1, node* root2){
    if (root1 == nullptr && root2 == nullptr) return true;
    if (root1 == nullptr || root2 == nullptr) return false;
    if (root1->val != root2->val) return false;

    return areEqual(root1->left, root2->left) && areEqual(root1->right, root2->right);
}

int main(){
    int r1, n1, r2, n2;
    cin >> r1 >> n1;
    node* root1 = new node(r1);

    for(int i=0; i<n1; i++){
        int op, key, val;
        cin >> op >> key >> val;
        node* parent = find(root1, key);
        if(parent){
            if(op == 0){
                parent->left = new node(val);
            }
            else if(op == 1){
                parent->right = new node(val);
            }
        }
    }

    cin >> r2 >> n2;
    node* root2 = new node(r2);

    for(int i=0; i<n1; i++){
        int op, key, val;
        cin >> op >> key >> val;
        node* parent = find(root2, key);
        if(parent){
            if(op == 0){
                parent->left = new node(val);
            }
            else if(op == 1){
                parent->right = new node(val);
            }
        }
    }

    if(areEqual(root1, root2)){
        cout << "1" << endl;
    }
    else{
        cout << "0" << endl;
    }
}