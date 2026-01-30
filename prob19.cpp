#include<bits/stdc++.h>
using namespace std;    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
       
        int n;
        cin >> n;
        vector<long long> a(2*n);
        for (int i = 0; i < 2*n; i++) cin >> a[i];
        int oc=0,ec=0;
        for(int i=0;i<2*n-1;i++){
           
            if(a[i]%2==0)
            {
                ec++;
            }
            else{
                oc++;
            }
        }
        cout<<(oc+2*ec)<<"\n";

    }
}