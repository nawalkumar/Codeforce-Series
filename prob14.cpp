#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        long long k;
        cin >> n >> k;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        int maxA = a.back();

        vector<int> freq(maxA + 1, 0);
        for(int x : a) freq[x] = 1;

        vector<int> good;

        for(int x : a){
            bool ok = true;
            for(int m = x; m <= maxA; m += x){
                if(freq[m] == 0){
                    ok = false;
                    break;
                }
            }
            if(ok) good.push_back(x);
        }

        if(good.empty()){
            cout << -1 << "\n";
            continue;
        }

        vector<int> B;

        for(int x : good){
            bool covered = false;
            for(int y : B){
                if(x % y == 0){
                    covered = true;
                    break;
                }
            }
            if(!covered) B.push_back(x);
        }

        cout << B.size() << "\n";
        for(int x : B) cout << x << " ";
        cout << "\n";
    }
}
