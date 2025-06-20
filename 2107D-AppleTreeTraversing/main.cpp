#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <list>

using namespace std;

typedef u_int32_t U32;

vector<U32> longest_path_to_leaf;
vector<U32> leaf_index; 
vector<U32> parent;

// Find the longest path from u to a leaf node of the tree rooted at u. Tiebreak by the index of the leaf node.
void dfs(const vector<list<U32>>& edges, U32 u, U32 p) {
    U32 max_length = 1;
    U32 best_leaf = u;

    for (const U32& v : edges[u]) {
        if (v == p) {
            parent[u] = v;
            continue;
        }

        dfs(edges, v, u);
        U32 candidate_length = longest_path_to_leaf[v] + 1;
        
        if (candidate_length > max_length) {
            max_length = candidate_length;
            best_leaf = leaf_index[v];
        } else if (candidate_length == max_length && leaf_index[v] > best_leaf) {
            best_leaf = leaf_index[v];
        }
    }

    longest_path_to_leaf[u] = max_length;
    leaf_index[u] = best_leaf;
}

int main() {
    U32 T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<list<U32>> edges(n + 1);
        unordered_set<U32> root_set; 

        longest_path_to_leaf.assign(n + 1, 0);
        leaf_index.assign(n + 1, 0);
        parent.assign(n + 1, 0);

        for (size_t i = 0; i < n - 1; ++i) {
            U32 u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        for (size_t i = 1; i <= n; ++i) {
            root_set.insert(i);
        }

        dfs(edges, 1, 0);
        vector<tuple<U32, U32, U32>> sorted_nodes;

        for (size_t i = 1; i <= n; ++i) {

        }

        // Sort the nodes by the longest path to leaf and then by the higher index of the leaf endpoint of the path.
        
        for (size_t i = 1; i <= n; ++i) {
            sorted_nodes.push_back({i, longest_path_to_leaf[i], leaf_index[i]});
        }

        std::sort(sorted_nodes.begin(), sorted_nodes.end(), [](const auto& a, const auto& b) {
            if (get<1>(a) != get<1>(b)) {
                return get<1>(a) > get<1>(b); // Sort by longest path length
            }
            return get<2>(a) > get<2>(b); // Tiebreak by leaf index
        });

        

    }

    return 0;
}