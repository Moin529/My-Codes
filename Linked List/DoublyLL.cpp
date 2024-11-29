#include <iostream>
using namespace std;
struct ll
{
    struct node
    {
        int value;
        node *next;
        node *prev;
    };
    node *head = NULL;
    node *tail = NULL;
    int insertFirst(int v)
    {
        node *newnode = new node();
        newnode->value = v;
        newnode->next = NULL;
        newnode->prev = NULL;
        if(head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            head->prev = newnode;
            newnode->next = head;
            head = newnode;
        }
    }

    int insertLast(int v)
    {
        node *newnode = new node();
        newnode->value = v;
        newnode->next = NULL;
        newnode->prev = NULL;
        if(head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    int deleteFirst()
    {
        if(head == NULL)
        {
            return -1;
        }
        else if(head == tail)
        {
            int x = head->value;
            head = tail = NULL;
            return x;
        }
        else
        {
            int x = head->value;
            head = head->next;
            head->prev = NULL;
            return x;
        }
    }

    int deleteLast()
    {
        if(head == NULL)
        {
            return -1;
        }
        else if(head == tail)
        {
            int x = head->value;
            head = tail = NULL;
            return x;
        }
        else
        {
            int x = tail->value;
            tail = tail->prev;
            tail->next = NULL;
            return x;
        }
    }

    void printList()
    {
        node *temp = head;
        while(temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    ll LinkedList;
    int n, v;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> v;
        LinkedList.insertLast(v);
    }
    cout << "List:" << endl;
    LinkedList.printList();
    cout << "Deleting First:" << endl;
    LinkedList.deleteFirst();
    LinkedList.printList();
    cout << "Deleting Last:" << endl;
    LinkedList.deleteLast();
    LinkedList.printList();
}
