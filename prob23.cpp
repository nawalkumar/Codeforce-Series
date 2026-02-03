#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int mx=INT_MIN,mp=-1;
        for(int i=0;i<n;i++){
            if(a[i]>mx){
                mx=a[i];
                mp=i;
            }
        }
        vector<int>ua;
        for(int i=0;i<n;i++)
        {
            ua.push_back(a[(mp+i)%n]);
        }
        ua.push_back(ua[0]);
        long long ans=0;
        stack<int> st;
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && ua[st.top()]<ua[i]){
                // int curr_el=ua[st.top()];
                st.pop();
                int right_max=ua[i];
                int left_max=st.empty()?mx:ua[st.top()];
                ans+=(long long)(min(left_max,right_max));
            }
            st.push(i);
        }
        long long mxc=0;
        for(int i=0;i<n;i++){
            if(a[i]==mx){
                mxc++;
            }
        }
        if(mxc>0)
        {
            ans=ans+(long long)(mxc-1)*mx;
        }
        cout<<ans<<"\n";
    }
}