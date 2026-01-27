#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> p(n);
        for(int i = 0; i < n; i++) cin >> p[i];
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        vector<int>a=p;
        for(int i=l;i<=r;i++){
            if(i+1<n)
            {
                a[i]=p[i+1];
            }
            else{
                a[i]=p[i];
            }
        }
        int sum_diff=a[r]-p[l];
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }        
        cout<<"\n";
    }
}