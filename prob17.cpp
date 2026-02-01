#include<bits/stdc++.h>
using namespace std;
int countSetBits(int n)
{
    int count=0;
    while(n)
    {
        count+=n&1;
        n=n>>1;
    }
    return count;
}

void solve(){
    int n;
    cin>>n;
    if(n==0){
        cout<<"YES\n";
        return;
    }
    if(countSetBits(n)%2!=0){
        cout<<"NO"<<"\n";
        return;
    }

    string s="";
    for(int i=29;i>=0;i--)
    {
        if(n&(1<<i)){
            for(int j=i;j>=0;j--)
            {
                s+=(n&(1<<j))?'1':'0';
            }
            break;
        }
    }
    int zeros=0;
    while(zeros<s.length() && s[s.length()-1-zeros]=='0'){
        zeros++;
    }
    for(int k=0;k<=zeros;k++)
    {
        string temp=string(k,'0')+s;
        string rev_t=temp;
        reverse(rev_t.begin(),rev_t.end());
        if(temp==rev_t)
        {
            if(temp.size()%2!=0)
            {
                if(temp[temp.size()/2]=='0')
                {
                    cout<<"YES\n";
                    return;
                }
            }
            else{
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";   
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       solve();
    }
}
