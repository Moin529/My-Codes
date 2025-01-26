//30
#include <iostream>
using namespace std;

void combination(int lst[], int n, int index)
{
    if(index == n)
    {
        for(int i=0; i<n; i++)
        {
            cout << lst[i];
            if(i < n-1)
            {
                cout << " ";
            }
        }
        cout << endl;
        return;
    }
    if(index % 2 == 0)
    {
        for(int i=0; i<=4; i+=2)
        {
            lst[index] = i;
            combination(lst, n, index+1);
        }
    }
    else
    {
        for(int i=1; i<=3; i+=2)
        {
            lst[index] = i;
            combination(lst, n, index+1);
        }
    }
}

int main(){
    int n;
    cin >> n;
    int lst[n];
    combination(lst, n, 0);
    return 0;
}