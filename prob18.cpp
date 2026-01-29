#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        // Kadane on a
        long long currA = a[0], maxA = a[0];
        for (int i = 1; i < n; i++) {
            currA = max(a[i], currA + a[i]);
            maxA = max(maxA, currA);
        }

        // Kadane on b
        long long currB = b[0], maxB = b[0];
        for (int i = 1; i < n; i++) {
            currB = max(b[i], currB + b[i]);
            maxB = max(maxB, currB);
        }

        long long ans = maxA + (k % 2) * maxB;
        cout << ans << "\n";
    }
}