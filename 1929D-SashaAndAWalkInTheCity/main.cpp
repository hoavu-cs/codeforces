#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> edges;
vector<int> sz;
// dp[u] stores the number of good sets in the subtree rooted at u excluding u
// in which no two vertices have ancestor/descendant relationship
vector<int> dp; 
const int K = 998244353;


void dfs(int u, int p) {
    sz[u] = 1;
    dp[u] = 1;
 
    int x = 1, n_children = 0;
    for (auto v : edges[u]) {
        if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
            x = (x * (dp[v] + 1)) % K;
            n_children++;
        }
    }
    
    if (n_children == 0) {
        dp[u] = 1;
    } else {
        dp[u] = x;
    }
    
    cout << "dp[" << u << "] = " << dp[u] << endl;
}


int main() {
    int n_tests;
    cin >> n_tests;

    while (n_tests > 0) {
        int n, sz_2_good_sets = 0;
        cin >> n;
        sz.assign(n + 1, 0);
        edges.assign(n + 1, vector<int>());
        dp.assign(n + 1, 0);

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        dfs(1, 0);
    
        int ans = 0;
        ans = dp[1];
        for (int i = 2; i <= n; i++) {
            ans = (ans + (sz[i] - 1)) % K;
        }

        ans = ans + edges[1].size();
        for (auto v : edges[1]) {
            ans = (ans + dp[v]) % K;
        }

        ans = (ans - edges[1].size() + 1) % K;

        cout << ans << endl;

        n_tests--;
    }
    return 0;
}