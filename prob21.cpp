#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s; cin>>s;
        vector<long long>aidx,bidx;
        for(int i=0;i<n;i++){
            if(s[i]=='a') aidx.push_back(i);
            else bidx.push_back(i);
        }
        if(aidx.size()==0 || bidx.size()==0){
            cout<<0<<"\n";
            continue;
        }
        vector<long long>adist;
        for(int i=0;i<aidx.size();i++){
            adist.push_back(aidx[i]-i);
        }
        vector<long long>bdist;
        for(int i=0;i<bidx.size();i++){
            bdist.push_back(bidx[i]-i);
        }
        long long mida=adist[adist.size()/2];
        long long midb=bdist[bdist.size()/2];
        long long ares=0;
        for(int i=0;i<adist.size();i++){
            ares+=abs(adist[i]-mida);
        }
        long long bres=0;
        for(int i=0;i<bdist.size();i++){
            bres+=abs(bdist[i]-midb);
        }
        cout<<min(ares,bres)<<"\n";
    }
}