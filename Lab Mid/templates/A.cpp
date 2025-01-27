#include <iostream>
using namespace std;

#define INT_MAX 2147483647

struct LinkedListNode{
        LinkedListNode *next;
        int val;
};

struct LinkedList{

    LinkedListNode *head=NULL;
    LinkedListNode *tail=NULL;

    void insert_last(int x)
    {
        //insert int x at last
        LinkedListNode* a=(LinkedListNode*)malloc(sizeof(LinkedListNode));
        a->next=NULL;
        a->val=x;
        if(tail)
        {
            tail->next=a;
            tail=a;
        }
        else
        {
            head=a;
            tail=a;
        }
    }

    void print()
    {
        LinkedListNode *p=head;
        while(p)
        {
            cout<<p->val<<endl;
            p=p->next;
        }
    }
};

struct LinkedListofLinkedListNode{
        LinkedListofLinkedListNode *next;
        LinkedList* list;
};

struct LinkedListofLinkedList{

    LinkedListofLinkedListNode *head=NULL;
    LinkedListofLinkedListNode *tail=NULL;

    void insert_last(LinkedList* x)
    {
        //insert LinkedList x at last
        LinkedListofLinkedListNode *a=(LinkedListofLinkedListNode*)malloc(sizeof(LinkedListofLinkedListNode));
        a->next=NULL;
        a->list=x;
        if(tail)
        {
            tail->next=a;
            tail=a;
        }
        else
        {
            head=a;
            tail=a;
        }
    }
};

LinkedList* sortLinkedListofLinkedList(LinkedListofLinkedList* lol){
    // You code starts here - 001

    // You code ends here - 001
}

int main() {
    
    int n, m, v;
    cin>>n;
    LinkedListofLinkedList* lol = new LinkedListofLinkedList();
    for(int i = 0;i<n;i++){
        LinkedList* l = new LinkedList();
        cin>>m;
        for(int j= 0;j<m;j++){
            cin>>v;
            l->insert_last(v);
        }
        lol->insert_last(l);
    }
    
    LinkedList* sorted = sortLinkedListofLinkedList(lol);

    sorted->print();
    


    return 0;
}

