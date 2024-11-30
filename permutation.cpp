#include <iostream>
using namespace std;

void permutation(char arr[], int start, int stop)
{
    if(start == stop)
    {
        for(int i=0; i<=stop; i++)
        {
            cout << arr[i];
        }
        cout << endl;
        return;
    }

    for(int i=start; i<=stop; i++)
    {
        swap(arr[start], arr[i]);
        permutation(arr, start+1, stop);
        swap(arr[start], arr[i]);
    }
}

int main()
{
    char arr[] = {'a', 'b', 'c'};
    permutation(arr, 0, 2);
    return 0;
}
