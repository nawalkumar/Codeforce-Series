#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long m;
    cin >> n >> m;

    vector<string> s(n);
    vector<array<int,26>> cnt(n);
    array<long long,26> total{};
    total.fill(0);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        cnt[i].fill(0);
        for (char c : s[i]) {
            cnt[i][c - 'A']++;
            total[c - 'A']++;
        }
    }

    for (int i = 0; i < n; i++) {
        long long ans = LLONG_MAX;

        for (int c = 0; c < 26; c++) {
            long long need = cnt[i][c];
            long long rest = total[c] - need;

            if (need > 0 && rest == 0) {
                ans = -1;
                break;
            }

            if (need > 0) {
                long long maxk = m - (need + rest - 1) / rest;
                ans = min(ans, maxk);
            }
        }

        if (ans < 0) cout << -1 << " ";
        else cout << ans << " ";
    }
    cout << "\n";
}

