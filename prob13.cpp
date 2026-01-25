#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        multiset<long long> A, B;

        for(int i = 0; i < n; i++) {
            long long x; cin >> x;
            A.insert(x);
        }
        for(int i = 0; i < m; i++) {
            long long x; cin >> x;
            B.insert(x);
        }

        bool aliceTurn = true;
        while(!A.empty() && !B.empty()) {
            if(aliceTurn) {
                
                auto a = prev(A.end()); 
                auto b = prev(B.end()); 

                if(*a >= *b) B.erase(b);         
                else {                           
                    long long val = *b - *a;
                    B.erase(b);
                    B.insert(val);
                }
            } else {
               
                auto b = prev(B.end()); 
                auto a = prev(A.end()); 

                if(*b >= *a) A.erase(a);          
                else {                           
                    long long val = *a - *b;
                    A.erase(a);
                    A.insert(val);
                }
            }
            aliceTurn = !aliceTurn;
        }

        if(A.empty()) cout << "Bob\n";
        else cout << "Alice\n";
    }
    return 0;
}
