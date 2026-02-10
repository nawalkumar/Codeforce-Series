#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> cnt(n+1,0);
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            cnt[x]++;
        }
        vector<int> pref(n+1,0);
        for(int i=1;i<=n;i++)
        {
            pref[i]=pref[i-1]+cnt[i];
        }
        for(int d=n;d>=1;d--)
        {
            vector<pair<int,int>>ranges;
            for(int m=1;m*d<=n;m++)
            {
                ranges.push_back({m*d,m*d});
            }
            for(int s=2;(s+1)*d<=n;s++)
            {
                int l=(s+1)*d;
                int r=min(n,(2*s-1)*d);
                ranges.push_back({l,r});
                if(r==n){
                    break;
                }
            }
            sort(ranges.begin(),ranges.end());
            int saved=0;
            if(!ranges.empty())
            {
                int curl=ranges[0].first;
                int curr=ranges[0].second;
                for(size_t i=1;i<ranges.size();i++)
                {
                    if(ranges[i].first<=curr+1)
                    {
                        curr=max(curr,ranges[i].second);
                    }
                    else{
                        saved+=pref[curr]-pref[curl-1];
                        curr=ranges[i].second;
                        curl=ranges[i].first;
                    }
                }
                saved+=pref[curr]-pref[curl-1];
            }
            if(n-saved<=k){
                cout<<d<<"\n";
                break;
            }
        }

    }

}
