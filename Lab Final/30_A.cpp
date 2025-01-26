//30
//30
//30
#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; 
    int n2 = right - mid;    

    int L[n1];
    int R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; 
        mergeSort(arr, left, mid); 
        mergeSort(arr, mid + 1, right); 
        merge(arr, left, mid, right); 
    }
}

int frequency(int arr[], int n, int q) {

    int low = 0, high = n - 1, first = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == q) {
            first = mid;
            high = mid - 1;
        } else if (arr[mid] < q) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (first == -1) return 0;
    
    low = 0, high = n - 1;
    int last = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == q) {
            last = mid;
            low = mid + 1;
        } else if (arr[mid] < q) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return last - first + 1;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);

    int m;
    cin >> m;

    while (m--) {
        int q;
        cin >> q;
        cout << frequency(arr, n, q) << endl;
    }

    return 0;
}