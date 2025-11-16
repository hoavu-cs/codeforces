#include <iostream>
#include <vector>
#include <map>

using namespace std;

int binary_search(const vector<int>& vec, int target) {
    int left = 0, right = vec.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target) {
            return mid;
        } else if (vec[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> dp(n, 0);
        map<int, vector<int>> positions; // positions[value] = list of indices with that value

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            positions[a[i]].push_back(i);
        }

        dp[0] = (a[0] == 1) ? 1 : 0;

        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1];
            int j = binary_search(positions[a[i]], i);
            
            /*
                We have 2 cases:
                1. The best neat subsequence in a[1..n] contains a[i]
                In this case, we need to look for the index of the previous occurrence of a[i] that is at position j - a[i] + 1 to cover the last block.
                Then, the total length will be dp[prev_index - 1] + a[i].

                2. The best neat subsequence in a[1..n] does not contain a[i]
                In this case, dp[i] = dp[i - 1]
            */

            if (j >= a[i] - 1) {
                int prev_index = positions[a[i]][j - a[i] + 1];
                if (prev_index == 0) {
                    dp[i] = max(dp[i], a[i]);
                } else {
                    dp[i] = max(dp[i], dp[prev_index - 1] + a[i]); 
                }
            }
        }

        cout << dp[n - 1] << endl;

    }


    return 0;
}