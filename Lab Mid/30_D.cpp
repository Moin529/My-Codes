//30
//30
//30
#include <iostream>
#include <vector>
using namespace std;

void Combination(int n, int k, int start, int finish, int comb[]){
    if(finish == k){
        for (int i = 0; i < k; i++) {
            cout << comb[i];
            if(i != k-1){
                cout << " ";
            }
        }
        cout << endl;
        return;
    }

    for(int i=start; i>=0; i--){
        comb[finish] = i;
        Combination(n, k, i-1, finish+1, comb);
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    int comb[k];
    Combination(n, k, n-1, 0, comb);
}