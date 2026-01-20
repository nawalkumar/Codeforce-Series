#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, j, k;
        cin >> n >> j >> k;

        string base = to_string(n);
        sort(base.begin(), base.end());

        string t1, t2;

        // j-th permutation
        string s = base;
        for (int i = 1; i < j; i++) {
            next_permutation(s.begin(), s.end());
        }
        t1 = s;

        // k-th permutation
        s = base;
        for (int i = 1; i < k; i++) {
            next_permutation(s.begin(), s.end());
        }
        t2 = s;

        int A = 0, B = 0;
        vector<bool> used1(t1.size(), false), used2(t2.size(), false);

        // Count A
        for (int i = 0; i < (int)t1.size(); i++) {
            if (t1[i] == t2[i]) {
                A++;
                used1[i] = used2[i] = true;
            }
        }

        // Count B
        for (int i = 0; i < (int)t1.size(); i++) {
            if (used1[i]) continue;
            for (int j = 0; j < (int)t2.size(); j++) {
                if (!used2[j] && t1[i] == t2[j]) {
                    B++;
                    used2[j] = true;
                    break;
                }
            }
        }

        cout << A << "A" << B << "B\n";
    }
}
