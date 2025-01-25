//18
//18
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ids[n];
    int marks[n];

    for (int i = 0; i < n; i++) {
        cin >> ids[i] >> marks[i];
    }

    //Selection sort
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            // Compare marks first, then IDs if marks are the same
            if (marks[j] < marks[minIndex] || 
                (marks[j] == marks[minIndex] && ids[j] < ids[minIndex])) {
                minIndex = j;
            }
        }
        // Swap marks
        int tempMark = marks[i];
        marks[i] = marks[minIndex];
        marks[minIndex] = tempMark;

        // Swap IDs
        int tempID = ids[i];
        ids[i] = ids[minIndex];
        ids[minIndex] = tempID;
    }

    for (int i = 0; i < n; i++) {
        cout << ids[i] << endl;
    }
    return 0;
}

