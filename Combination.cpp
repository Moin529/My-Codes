
#include <iostream>
#include <vector>
using namespace std;
//Print all possible combinations of k digits from (0-n) in descending order.

// Recursive function to generate combinations
void generateCombinations(int n, int k, int start, int shesh, int combination[]) {
    // If the current combination has the required size k
    if (shesh == k) {
        for (int i = 0; i < k; i++) {
            cout << combination[i];
        }
        cout << endl;
        return;
    }

    // Generate next elements
    for (int i = start; i >= 0; i--) {
        combination[shesh] = i; // Set the current depth to the number
        generateCombinations(n, k, i - 1, shesh + 1, combination);
    }
}

int main() {
    int n, k;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    int combination[k]; // Array to hold the current combination

    // Generate combinations starting from n
    generateCombinations(n, k, n-1, 0, combination);

    return 0;
}
