#include <iostream>
using namespace std;

int getMax(int arr[], int n)
{
    int max = arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n, int place)
{
    int max = 10;
    int output[max];
    int count[max];

    for(int i=0; i<max; i++)
    {
        count[i] = 0;
    }

    for(int i=0; i<n; i++)
    {
        count[(arr[i]/place) % 10]++;
    }

    for(int i=1; i<max; i++)
    {
        count[i] += count[i-1];
    }

    for(int i=n-1; i>=0; i--)
    {
        output[count[(arr[i]/place) % 10] - 1] = arr[i];
        count[(arr[i]/place) % 10]--;
    }

    for(int i=0; i<n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);

    for(int place = 1; max/place > 0; place*=10)
    {
        countSort(arr, n, place);
    }
}

void printSort(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    //121, 432, 564, 23, 1, 45, 788
    radixSort(arr, n);
    printSort(arr, n);
}