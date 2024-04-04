#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const long MOD = 998244353;
vector<vector<long>> adj;
vector<long> A, B;

void dfs(long u, long p) {
    long n_children = 0;
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        n_children++;
    }

    if (n_children == 0) {
        A[u] = 1;
        B[u] = 0;
    } else {
        long x = 1, y = 0;
        for (auto v : adj[u]) {
            if (v == p) continue;
            x = (x * (A[v] + 1)) % MOD;
            y = (y + (A[v] - 1)) % MOD;
        }
        A[u] = x % MOD;
        B[u] = (y + n_children) % MOD;
    }    
    //cout << "A[" << u << "] = " << A[u] << ", B[" << u << "] = " << B[u] << endl;
}

int main() {

    long n_tests;
    cin >> n_tests;

    while(n_tests > 0) {
        long n;
        cin >> n;

        if (n == 0) {
            cout << 1 << endl;
            n_tests--;
            continue;
        }

        adj.assign(n + 1, vector<long>());  
        A.assign(n + 1, 0);
        B.assign(n + 1, 0);

        for (long i = 0; i < n - 1; i++) {
            long u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, -1);
        long ans = A[1] + 1;
        for (long i = 1; i <= n; i++) {
            ans = (ans + B[i]) % MOD;
        }
        
        cout << ans % MOD << endl;
        n_tests--;
    }
    return 0;
}