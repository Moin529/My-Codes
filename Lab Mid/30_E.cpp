//30
#include <iostream>
#include <vector>
using namespace std;

void combination(vector <int> lst, int n, int id){
    if(id == n){
        for(int i=0; i<n; i++){
            cout << lst[i];
            if(i < n-1){
                cout << " ";
            }
        }
        cout << endl;
        return;
    }

    if(id % 2 != 0){
        for(int i=4; i>=0; i-=2){
            lst[id] = i;
            combination(lst, n, id + 1);
        }
    }

    else{
        for(int i=3; i>=1; i-=2){
            lst[id] = i;
            combination(lst, n, id + 1);
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector <int> lst(n);
    combination(lst, n, 0);
}
