#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n,l,r;
        cin >> n >> l >> r;
        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            a[i]=1LL<<(i);  
        }
        long long xr=0;
        for(int j=l-1;j<r;j++)
        {
            xr=xr^a[j];
        }
        a[r-1]=a[r-1]^xr;
        for(int i=0;i<n;i++)a
        {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}