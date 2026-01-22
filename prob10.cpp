#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,p;
    cin >> n >> m >> p;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];

    }
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int>q;
    q.push(1);
    vector<int>dist_city(n+1,-1);
    dist_city[1]=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
           
            if(dist_city[it]==-1)
            {
                dist_city[it]=dist_city[node]+1;
                q.push(it);
            }
        }
    }
    vector<int>dist(p+1,0);
    for(int i=1;i<=n;i++)
    {
        int res=a[i];
        dist[res]=max(dist[res],dist_city[i]);

    }
    for(int i=1;i<=p;i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}