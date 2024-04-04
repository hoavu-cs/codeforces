#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random tree
void generateRandomTree(int n) {
    for (int i = 2; i <= n; ++i) {
        int u = i; // Current node
        // Select a random parent from nodes [1, i-1]
        int v = rand() % (i - 1) + 1;
        cout << u << " " << v << endl;
    }
}

int main() {
    srand(time(0)); // Seed for random number generation
    int t = 1000; // Number of test cases
    cout << t << endl;

    while (t--) {
        // Generate a random number between 1 and 100 for the number of nodes
        int n = rand() % 100 + 1;
        cout << n << endl;
        generateRandomTree(n);
    }

    return 0;
}
