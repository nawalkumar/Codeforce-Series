#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + cnt[i];

    for (int d = n; d >= 1; d--) {
        // We use a 'merged ranges' approach or simply mark valid points
        // However, for efficiency, we can just find the first S where ranges overlap
        // Overlap happens when (S+1+1)d <= (2S-1)d + 1
        
        vector<pair<int, int>> ranges;
        // 1. All multiples are valid
        for (int m = 1; m * d <= n; m++) {
            ranges.push_back({m * d, m * d});
        }
        // 2. Split ranges [ (S+1)d, (2S-1)d ] for S >= 2
        for (int s = 2; (s + 1) * d <= n; s++) {
            int L = (s + 1) * d;
            int R = min(n, (2 * s - 1) * d);
            ranges.push_back({L, R});
            if (R == n) break;
        }

        sort(ranges.begin(), ranges.end());
        
        int saved = 0;
        if (!ranges.empty()) {
            int curL = ranges[0].first;
            int curR = ranges[0].second;
            for (size_t i = 1; i < ranges.size(); i++) {
                if (ranges[i].first <= curR + 1) {
                    curR = max(curR, ranges[i].second);
                } else {
                    saved += pref[curR] - pref[curL - 1];
                    curL = ranges[i].first;
                    curR = ranges[i].second;
                }
            }
            saved += pref[curR] - pref[curL - 1];
        }

        if (n - saved <= k) {
            cout << d << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}