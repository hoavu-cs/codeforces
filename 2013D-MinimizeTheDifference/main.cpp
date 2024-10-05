#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;
typedef long long ll;


int main() {
    int num_tests;
    cin >> num_tests;

    while (num_tests--) {
        int n;
        cin >> n;

        vector<ll> a(n);
        stack<pair<ll, ll>> s;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        s.push({a[0], 1});
        for (int i = 1; i < n; i++) {
            if (a[i] == s.top().first) {
                s.top().second++;
            } else if (a[i] > s.top().first) {
                s.push({a[i], 1});
            } else {
                ll sum = a[i];
                int num_elements = 1;
                
                while (s.size() > 0 && sum / num_elements < s.top().first) {
                    sum += s.top().first * s.top().second;
                    num_elements += s.top().second;
                    s.pop();
                }

                ll d = sum / num_elements;
                ll r = sum % num_elements;

                s.push({d, num_elements - r});
                if (r) s.push({d + 1, r});
            }
        }

        ll min_val = LLONG_MAX;
        ll max_val = LLONG_MIN;

        while (!s.empty()) {
            min_val = min(min_val, s.top().first);
            max_val = max(max_val, s.top().first);
            s.pop();
        }

        cout << max_val - min_val << endl;
    }

    return 0;
}