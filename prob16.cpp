#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;

        vector<long long> a(n);
        for(auto &x : a) cin >> x;

        vector<long long> b(m), c(m);
        for(int i = 0; i < m; i++) cin >> b[i];
        for(int i = 0; i < m; i++) cin >> c[i];

        vector<pair<long long,long long>> monsters(m);
        for(int i = 0; i < m; i++)
            monsters[i] = {b[i], c[i]};

        sort(monsters.begin(), monsters.end());

        priority_queue<long long, vector<long long>, greater<>> pq;
        long long killed = 0;
        for(auto x : a) pq.push(x);

        for(auto [need, gain] : monsters){
            while(!pq.empty() && pq.top() < need)
                pq.pop();

            if(pq.empty()) break;

            long long cur = pq.top();
            pq.pop();

            if(gain > 0)
                pq.push(max(cur, gain));

            killed++;
        }

    }
}