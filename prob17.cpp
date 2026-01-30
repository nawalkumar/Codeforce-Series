#include<bits/stdc++.h>
using namespace std;
int reverse(int n)
{
    int rev=0;
    while(n)
    {
        rev=(rev<<1)|(n&1);
        n=n>>1;
    }
    return rev;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    bool ok=false;
    while(t--){
       int n;
       cin>>n;
       for(int x=1;x<(1<<15);x++)
       {
            if(x^reverse(x)==n)
            {
                ok=true;
                break;
            }
       }
       if(ok) cout<<"YES\n";
       else cout<<"NO\n";
        ok=false;
    }
}