//30
#include <iostream>
using namespace std;

struct Student{
    int id;
    int marks;
};

void merge(Student arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Student* leftArr = new Student[n1];
    Student* rightArr = new Student[n2];

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        // Sort primarily by marks, and by ID in case of tie
        if (leftArr[i].marks < rightArr[j].marks ||
            (leftArr[i].marks == rightArr[j].marks && leftArr[i].id < rightArr[j].id)) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1) {
        arr[k++] = leftArr[i++];
    }
    while (j < n2) {
        arr[k++] = rightArr[j++];
    }

}

void mergeSort(Student arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main(){
    int n;
    cin >> n;
    Student* students = new Student[n];

    for(int i=0; i<n; i++){
        cin >> students[i].id >> students[i].marks;
    }

    mergeSort(students, 0, n-1);
    for(int i=0; i<n; i++){
        cout << students[i].id << endl;
    }
    return 0;
}