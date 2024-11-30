#include <iostream>
using namespace std;

void Combination(char c[], int index, int n)
{
    if(index==n)
    {
        for(int i=0; i<n; i++)
        {
            cout << c[i] << " ";
        }
        cout << endl;
        return;
    }

    c[index] = 'a';
    Combination(c, index+1, n);
    c[index] = 'b';
    Combination(c, index+1, n);
    c[index] = 'c';
    Combination(c, index+1, n);
}

int main()
{
    int n;
    cin >> n;
    char c[n];
    Combination(c, 0, n);
    return 0;
}
