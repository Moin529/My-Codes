#include <iostream>
using namespace std;


int heap[1000];
int last_index = -1;

int get_max(){
    if(last_index == -1){
        return -1;
    }
    return heap[0];
}

int parent(int i){
    return (i-1)/2;
}


void heapifyUp_Loop(int i){
    while(1){
        if (i==0)
            break;
        if(heap[parent(i)]>heap[i])
            break;
        
        // swap
        int temp = heap[parent(i)];
        heap[parent(i)] = heap[i];
        heap[i] = temp;

        i = parent(i);

    }
}

void heapifyUp_Rec(int i){
    if(i==0){
        return;
    }

    if(heap[parent(i)] > heap[i]){
        return;
    }

    //swap
    int temp = heap[parent(i)];
    heap[parent(i)] = heap[i];
    heap[i] = temp;

    heapifyUp_Rec(parent(i));
}

void insert(int x){

    heap[last_index+1] = x;
    last_index++;
    heapifyUp_Loop(last_index);
    //heapifyUp_Rec(last_index);
}

int leftChild(int i){
    return 2 * i + 1;
}

int rightChild(int i){
    return 2 * i + 2;
}


void heapifyDown_Rec(int i){

    if(leftChild(i) > last_index){
        return;
    }

    int mx_node = -1;
    if (rightChild(i) <= last_index && heap[rightChild(i)] > heap[leftChild(i)]) {
            mx_node = rightChild(i);
        }
    else {
        mx_node = leftChild(i);
    }

    if(heap[i]>=heap[mx_node]){
        return;
    }

    // swap
    int temp = heap[i];
    heap[i] = heap[mx_node];
    heap[mx_node] = temp;

    heapifyDown_Rec(mx_node);

}

void heapifyDown_Loop(int i){
    while(1){
        if(leftChild(i) > last_index){
            break;;
        }

        int mx_node = -1;
        if (rightChild(i) <= last_index && heap[rightChild(i)] > heap[leftChild(i)]) {
            mx_node = rightChild(i);
        }
        else {
            mx_node = leftChild(i);
        }

        if(heap[i]>=heap[mx_node]){
            break;
        }

        // swap
        int temp = heap[i];
        heap[i] = heap[mx_node];
        heap[mx_node] = temp;

        i = mx_node;
    }
}

int extractMax(){
    int ret = heap[0];

    heap[0] = heap[last_index];
    last_index--;


    return ret;
}

int main() {

    insert(10);
    insert(10);
    insert(20);
    insert(15);
    insert(25);
    insert(5);
    insert(21);
    cout << extractMax() << endl;

    return 0;
}