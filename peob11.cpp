#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin>>n;
        vector<long long> a(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]; 
        }

        ll sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=a[i];
        }
        long long curr=0;
        long long maxsum=0;
        for(int i=1;i<=n;i++)
        {
            long long b=2LL*i-a[i];
            curr=max(curr+b,b);
            maxsum=max(maxsum,curr);
        }
        cout<<sum+maxsum<<endl;
        cout<<"\n";
    }
    return 0;
}