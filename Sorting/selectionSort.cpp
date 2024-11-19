#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector <int> &arr)
{
    int n = arr.size();
    for(int i=0; i<n-1; i++)
    {
        int minimum = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[i])
            {
                minimum = j;
                swap(arr[i], arr[minimum]);
            }
        }

    }
}

void print(vector <int> &arr)
{
    for (int val:arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector <int> arr(n);
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    selectionSort(arr);
    print(arr);
    return 0;
}
