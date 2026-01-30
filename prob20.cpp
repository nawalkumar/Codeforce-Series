#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        set<long long> black;
        for(int i = 0; i < m; i++){
            long long x;
            cin >> x;
            black.insert(x);
        }

        long long cur = 1;
        for(int i = 0; i < n; i++){
            if(s[i] == 'A'){
                cur++;
            } else {  // 'B'
                // jump to next white
                while(black.count(cur + 1)) cur++;
                cur++;
            }
            black.insert(cur); // paint only the endpoint
        }

        cout << black.size() << "\n";
        for(long long x : black) cout << x << " ";
        cout << "\n";
    }
}
