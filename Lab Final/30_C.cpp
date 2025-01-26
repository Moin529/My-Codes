//30
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int x){
    int low = 0, high = n - 1, result = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= x) {
            result = mid;
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    return result + 1;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int m;
    cin >> m;

    for(int i=0; i<m; i++){
        int q;
        cin >> q;
        cout << binarySearch(arr, n, q) << endl;
    }

    return 0;
}