#include <iostream>
using namespace std;

struct ll
{
    struct node
    {
        int value;
        node *next;
    };

    node *head = NULL;
    node *tail = NULL;

    void insertFirst(int v)
    {
        node *newnode = new node();
        newnode->value = v;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = tail = newnode;
        }

        else
        {
            newnode->next = head;
            head = newnode;
        }
    }

    void insertLast(int v)
    {
        node *newnode = new node();
        newnode->value = v;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }

    int deleteFirst()
    {
        if(head == NULL)
        {
            return -1;
        }
        if(head == tail)
        {
            int x = head->value;
            head = tail = NULL;
            return x;
        }
        else{
            int x = head->value;
            head = head->next;
            return x;
        }
    }

    int deleteLast()
    {
        if(head == NULL)
        {
            return -1;
        }
        if(head == tail)
        {
            int x = tail->value;
            head = tail = NULL;
            return x;
        }
        else{
            node *temp = head;
            while(temp->next->next)
            {
                temp = temp->next;
            }
            //1, 2, 3, 4, (5), 6
            int x = temp->next->value;
            tail = temp;
            temp->next = NULL;
            return x;
        }
    }

    int deleteRange(int l, int u)
    {
        while(head && head->value >= l && head->value <= u)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
        node *t = head;

        while(t && t->next)
        {
            if(t->next->value >= l && t->next->value <= u)
            {
                node *current = t->next;
                t->next = t->next->next;
                delete current;
                if(t->next == NULL)
                {
                    tail = t;
                }
            }
            else
            {
                t = t->next;
            }
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
    ll List;
    int n, v;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> v;
        List.insertLast(v);
    }
    cout << "List: " << endl;
    List.printList();
    int l, u;
    cout << "Delete Range:\nLower: ";
    cin >> l;
    cout << "Upper: ";
    cin >> u;
    //List.deleteFirst();
    //cout << "Deleting First element: " << endl;
    //List.printList();
    //List.deleteLast();
    //cout << "Deleting Last element: " << endl;
    //List.printList();
    List.deleteRange(l, u);
    cout << "After deleting range:" << endl;
    List.printList();
}
