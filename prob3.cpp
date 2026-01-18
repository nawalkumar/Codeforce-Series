#include<bits/stdc++.h>
using namespace std;
long long calculatescore(vector<long long>&red, vector<long long>&blue, int m){
    long long mn=0,mx=0;
    for(int i=0;i<m;i++){
        // when chosing red && blue
        long long new_mn=min({mn-red[i],mx-red[i], blue[i]-mn,blue[i]-mx});
        long long new_mx=max({mn-red[i],mx-red[i], blue[i]-mn,blue[i]-mx});
        mn=new_mn;
        mx=new_mx;
    }
    return max(mn,mx);
}
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        vector<long long>red(m);
        for(int i=0;i<m;i++){
            int r;
            cin>>r;
            red[i]=r;
        }
        vector<long long>blue(m);
        for(int i=0;i<m;i++){
            int b;
            cin>>b;
            blue[i]=b;
        }
        long long score=calculatescore(red,blue,m);
        cout<<score<<"\n";
    }
    return 0;
}
