#include <iostream>
using namespace std;

#define INT_MAX 2147483647

struct BST
{
    struct node
    {
        int val;
        node* left;
        node* right;
        node* parent;
    };
    node*root=NULL;

    void insert_value(node*p, int x)
    {
       // Your code starts here - 001


       // Your code ends here - 001

    }
    
    void inorder(node*p)
    {
        // Your code starts here - 002

       
       // Your code ends here - 002
    }
    
    void delete_value(int x){
        // Your code starts here - 003

       
       // Your code ends here - 003

    }

};

int main() {
    
    BST* bst = new BST();
    int n, m;
    cin>>n;
    for(int i = 0;i<n;i++){
        int v;
        cin>>v;
        bst->insert_value(bst->root, v);
    } 
    cin>>m;
    for(int i = 0;i<m;i++){
        int v;
        cin>>v;
        bst->delete_value(v);
    } 
    bst->inorder(bst->root);
    return 0;
}

