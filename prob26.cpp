#include<bits/stdc++.h>
using namespace std;
string reverse(string s)
{
    string temp=s;
    reverse(temp.begin(),temp.end());
    return temp;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        string sorted_s=s;
        sort(sorted_s.begin(),sorted_s.end());
        if(s==sorted_s)
        {
            cout<<"Bob\n";
            continue;
        }
        vector<int>indces;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=sorted_s[i])
            {
                indces.push_back(i+1);
            }
        }

        cout<<"Alice\n";
        cout<<indces.size()<<"\n";
        for(int i=0;i<indces.size();i++)
        {
            cout<<indces[i]<<(i==indces.size()-1?"":" ");
        }

        cout<<"\n";
    }
}