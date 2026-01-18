#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string t, s;
        cin >> t;
        cin>> s;

        map<char,int> mps;
        for (char c : s) mps[c]++;


        bool ok = true;
        for (char c : t) {
            if (--mps[c] < 0) {
                cout << "Impossible\n";
                ok = false;
                break;
            }
        }
        if (!ok) continue;

        char x = t[0];
        string ans = "";

        for (char c = 'a'; c < x; c++) {
            ans += string(mps[c], c);
            mps[c] = 0;
        }

        string same(t.size(), x);
        if (t < same) {
            ans += t;
            ans += string(mps[x], x);
        } else {
            ans += string(mps[x], x);
            ans += t;
        }
        mps[x] = 0;

        for (char c = x + 1; c <= 'z'; c++) {
            ans += string(mps[c], c);
        }

        cout << ans << "\n";
    }
    return 0;
}