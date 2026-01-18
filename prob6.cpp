// optimal Shifts
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                pos.push_back(i);
        }

        // If already all ones
        if ((int)pos.size() == n) {
            cout << 0 << "\n";
            continue;
        }

        int ans = 0;
        int m = pos.size();

        // Gaps between consecutive ones
        for (int i = 1; i < m; i++) {
            ans = max(ans, pos[i] - pos[i - 1] - 1);
        }

        // Circular gap
        ans = max(ans, n - pos[m - 1] + pos[0] - 1);

        cout << ans << "\n";
    }

    return 0;
}
