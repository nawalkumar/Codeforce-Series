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
        int n,l,r;
        cin>>n>>l>>r;
        vector<int> p(n+1);
        int currval=1;
        for(int i=0;i<=n;i++)
        {
            
            if(i==r)
            {
                p[i]=p[l-1];
            }
            else if(i==l-1)
            {
                if(i==0)
                {
                    p[i]=0;
                }
                else{
                    p[i]=currval++;;
                }
            }
            else{
                if(i==0)
                {
                    p[i]=0;
                }
                else{
                    p[i]=currval++;
                }
            }
        }
       
        for(int i=1;i<=n;i++)
        {
            cout<<(p[i]^p[i-1])<<((i==n)?"":" ");
        }
        cout<<"\n";
    }
}