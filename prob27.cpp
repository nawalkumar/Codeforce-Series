#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> odds, evens;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (x % 2 == 0) evens.push_back(x);
        else odds.push_back(x);
    }

    sort(odds.rbegin(), odds.rend());
    sort(evens.rbegin(), evens.rend());

    vector<long long> pref_even(evens.size() + 1, 0);
    for (int i = 0; i < evens.size(); i++) {
        pref_even[i + 1] = pref_even[i] + evens[i];
    }

    for (int k = 1; k <= n; k++) {
        long long max_score = 0;

        if (!odds.empty()) {
            
            int min_m = max(1, k - (int)evens.size());
            if (min_m % 2 == 0) min_m++;

            if (min_m <= k && min_m <= (int)odds.size()) {
                max_score = odds[0] + pref_even[k - min_m];
            }
        }

        cout << max_score << (k == n ? "" : " ");
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