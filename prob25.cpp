#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> dp(n + 1, 1e9);
    vector<int> unique_elements;
    bool contains_one = false;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x <= n) {
            if (x == 1) {
                contains_one = true;
                dp[1] = 1;
            } else {
                if (dp[x] == 1e9) {
                    unique_elements.push_back(x);
                }
                dp[x] = 1;
            }
        }
    }

    sort(unique_elements.begin(), unique_elements.end());


    for (int i = 1; i <= n; i++) {
        if (dp[i] == 1e9) continue;
        
        for (int val : unique_elements) {
            if (1LL * i * val > n) break; 
            
            int target = i * val;
            if (dp[i] + 1 < dp[target]) {
                dp[target] = dp[i] + 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (dp[i] == 1e9 ? -1 : dp[i]) << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}