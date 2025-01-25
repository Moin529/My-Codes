//18
#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n;
    int v[n];
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    cin >> m;
    int q[m];
    int count = 0;
    for(int i=0; i<m; i++){
        cin >> q[i];
        for(int j=0; j<n; j++){
            if(q[i] == v[j]){
                count++;
            }
        }
        cout << count << endl;
        count = 0;
    }
}