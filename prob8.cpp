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

        vector<int> b(n);
        int maxb = 0;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            maxb = max(maxb, b[i]);
        }

        // frequency of values
        vector<int> freq(maxb + 1, 0);
        for (int x : b) {
            if (x > 0) freq[x]++;
        }

        int suf = 0, ans = 0;
        // suffix count: how many elements >= v
        for (int v = maxb; v >= 1; v--) {
            suf += freq[v];
            ans = max(ans, min(suf, v));
        }

        cout << ans << "\n";
    }

    return 0;
}
