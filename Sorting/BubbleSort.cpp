#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector <int>& arr)
{
    int sz = arr.size();
    bool swapped;
    for(int i=0; i<sz-1; i++)
    {
        for(int j=0; j<sz-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if(!swapped)
        {
            break;
        }
    }
}

void print(vector<int>& arr)
{
    for(int num : arr)
    {
        cout << num << " ";
    }
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
    bubbleSort(arr);
    print(arr);
    return 0;
}
