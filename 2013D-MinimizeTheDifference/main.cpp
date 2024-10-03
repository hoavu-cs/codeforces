#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

// Difference Array Functions

void update_diff_array(vector<ull>& diff, int i, int j, ull val) {
    // Add val to all elements in the range [i, j]
    diff[i] += val;
    diff[j+1] -= val;
}

vector<ull> reconstruct_array(const vector<ull>& diff) {
    // Reconstruct the original array from the difference array
    vector<ull> arr(diff.size());
    arr[0] = diff[0];
    for (int i = 1; i < diff.size(); i++) {
        arr[i] = arr[i-1] + diff[i];
    }
    return arr;
}