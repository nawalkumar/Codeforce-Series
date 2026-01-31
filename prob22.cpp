#include<bits/stdc++.h>
using namespace std;
int main()
{
    sync_with_stdio(false);cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n;
        long long k;
        cin>>n>>k;
        vector<long long>q(n);
        vector<long long>r(n);

        for(int i=0;i<n;i++) cin>>q[i];
        for(int i=0;i<n;i++) cin>>r[i];

        sort(q.begin(),q.end());
        sort(r.begin(),r.end());

        int i=0,j=0;
        int ans=0;
        while(i<n && j<n){
            if( ( q[i] * (r[j]+1) + r[j] )<=k){
                ans++;
                i++; j++;
            }
            else{
                j++;
            }
        }
        cout<<ans<<"\n";
    }
}