//30
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int smallest = i;          
    int left = 2 * i + 1;      
    int right = 2 * i + 2;     

    // If left child is smaller than the current smallest
    if (left < n && arr[left] < arr[smallest]){
        smallest = left;
    }
    // If right child is smaller than the current smallest
    if (right < n && arr[right] < arr[smallest]){
        smallest = right;
    }
    // If the smallest is not the root, swap and heapify recursively
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i){
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    buildMinHeap(arr, n); 
    for (int i = n - 1; i >= 0; --i) {
        cout << arr[0] << endl; 
        arr[0] = arr[i]; 
        heapify(arr, i, 0); 
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    heapSort(arr, n);
    return 0;
}
