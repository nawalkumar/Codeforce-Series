#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        long long x;
        cin >> n>> x;
        vector<long long> b(n);
        multiset<long long> ms;
        for(int i = 0; i < n; i++){
            cin >> b[i];
            ms.insert(b[i]);
        }

        long long sum=0,bp=0;
        vector<long long>a;
        while(!ms.empty()){
          long long need=(sum/x + 1)*x;
          long long req=need - sum;
          auto it=ms.lower_bound(req);
          if(it!=ms.end()){
                auto best=prev(ms.end());
                long long p=*best;
                a.push_back(p);

                sum+=p;
                ms.erase(best);
                bp+=p;

          }
          else{
                auto best=ms.begin();
                long long p=*best;
                a.push_back(p);

                sum+=p;
                ms.erase(best);
          }
        }
        cout << bp << "\n";
        for(long long val : a){
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}