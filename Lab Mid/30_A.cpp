//30
//30
//30
#include <iostream>
using namespace std;

#define INT_MAX 2147483647

struct LinkedListNode {
    LinkedListNode* next;
    int val;
};

struct LinkedList {
    LinkedListNode* head = NULL;
    LinkedListNode* tail = NULL;

    void insert_last(int x) {
        // Insert int x at the last
        LinkedListNode* a = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        a->next = NULL;
        a->val = x;
        if (tail) {
            tail->next = a;
            tail = a;
        } else {
            head = a;
            tail = a;
        }
    }

    void print() {
        LinkedListNode* p = head;
        while (p) {
            cout << p->val << endl;
            p = p->next;
        }
    }
};

struct LinkedListofLinkedListNode {
    LinkedListofLinkedListNode* next;
    LinkedList* list;
};

struct LinkedListofLinkedList {
    LinkedListofLinkedListNode* head = NULL;
    LinkedListofLinkedListNode* tail = NULL;

    void insert_last(LinkedList* x) {
        // Insert LinkedList x at last
        LinkedListofLinkedListNode* a = (LinkedListofLinkedListNode*)malloc(sizeof(LinkedListofLinkedListNode));
        a->next = NULL;
        a->list = x;
        if (tail) {
            tail->next = a;
            tail = a;
        } else {
            head = a;
            tail = a;
        }
    }
};

// Helper function to merge two sorted linked lists
LinkedList* mergeTwoLists(LinkedList* l1, LinkedList* l2) {
    LinkedList* result = new LinkedList();
    LinkedListNode* p1 = l1->head;
    LinkedListNode* p2 = l2->head;

    while (p1 && p2) {
        if (p1->val <= p2->val) {
            result->insert_last(p1->val);
            p1 = p1->next;
        } else {
            result->insert_last(p2->val);
            p2 = p2->next;
        }
    }

    // Add remaining elements from l1
    while (p1) {
        result->insert_last(p1->val);
        p1 = p1->next;
    }

    // Add remaining elements from l2
    while (p2) {
        result->insert_last(p2->val);
        p2 = p2->next;
    }

    return result;
}

LinkedList* sortLinkedListofLinkedList(LinkedListofLinkedList* lol) {
    if (!lol->head) return nullptr;

    LinkedList* result = lol->head->list; // Start with the first list
    LinkedListofLinkedListNode* current = lol->head->next;

    // Iteratively merge all lists
    while (current) {
        result = mergeTwoLists(result, current->list);
        current = current->next;
    }

    return result;
}

int main() {
    int n, m, v;
    cin >> n;
    LinkedListofLinkedList* lol = new LinkedListofLinkedList();
    for (int i = 0; i < n; i++) {
        LinkedList* l = new LinkedList();
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> v;
            l->insert_last(v);
        }
        lol->insert_last(l);
    }

    LinkedList* sorted = sortLinkedListofLinkedList(lol);

    sorted->print();

    return 0;
}