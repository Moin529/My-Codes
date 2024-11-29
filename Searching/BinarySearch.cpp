//Binary Search in Iterative method(Using loop)

#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int> &arr, int target)
{
    int size = arr.size();
    int start, end, mid;
    start = 0;
    end = size - 1;
    while(start <= end)
    {
        mid = start + (end - start)/2;
        if(arr[mid] < target)
        {
            start = mid + 1;
        }
        if(arr[mid] > target)
        {
            end = mid - 1;
        }
        if(arr[mid] == target)
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cout << "Which number to search: ";
    cin >> target;
    int index = binarySearch(arr, target);
    if(index == -1)
    {
        cout << "Target not found" << endl;
    }
    else{
        cout << "Target found at index" << index << endl; 
    }
}