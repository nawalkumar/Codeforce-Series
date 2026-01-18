#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> odd, even;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            if (x % 2 == 0)
                even.push_back(x);
            else
                odd.push_back(x);
        }

        // Sort in descending order
        sort(odd.begin(), odd.end(), greater<long long>());
        sort(even.begin(), even.end(), greater<long long>());

        int o = odd.size();
        int e = even.size();

        // Prefix sums
        vector<long long> prefOdd(o + 1, 0), prefEven(e + 1, 0);

        for (int i = 0; i < o; i++)
            prefOdd[i + 1] = prefOdd[i] + odd[i];

        for (int i = 0; i < e; i++)
            prefEven[i + 1] = prefEven[i] + even[i];

        // Answer for k = 1 to n
        for (int k = 1; k <= n; k++) {
            long long ans = 0;

            // i = number of odd coins (must be odd)
            for (int i = 1; i <= o && i <= k; i += 2) {
                int j = k - i; // even coins
                if (j <= e) {
                    ans = max(ans, prefOdd[i] + prefEven[j]);
                }
            }

            cout << ans;
            // if (k < n) cout;
        }
        cout << "\n";
    }

    return 0;
}