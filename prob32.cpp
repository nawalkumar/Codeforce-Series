#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    long long x;
    cin>>n>>x;
    vector<vector<long long>> a(n, vector<long long>(3));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        if(1LL*(a[i][1]-1)*a[i][0]>=x)
        {
            cout<<0<<"\n";
            return;
        }
    }
    long long rolled=LLONG_MAX;
    for(int i=0;i<n;i++)
    {
        long long xrem=x;
        if((1LL*(a[i][1])*a[i][0] - a[i][2])<=0)
        {
           continue;
        }
        xrem-=(1LL*(a[i][1]-1)*a[i][0]);
        long long gain=(1LL*a[i][1]*a[i][0] - a[i][2]);
        long long currolled=(xrem+gain-1)/gain;
        rolled=min(rolled,currolled);
    }
    if(rolled==LLONG_MAX)
    {
        cout<<-1<<"\n";
    }
    else
    {
        cout<<rolled<<"\n";
    }
   
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}