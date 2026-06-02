#include <bits/stdc++.h>

using namespace std;

#define ll long long
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    ll n, x; cin>>n>>x;
    ll d = 0;
    
    for(ll i =0;i<n;i++){
        char c; 
        ll b;
        cin>>c>>b;
        if(c == '+'){
          x+=b;  
        } else if(c == '-'){
            x-=b;
            if (x < 0) {
                d++;
                x+=b;
            }
        }
    }
    cout << x << " "<<d;
    return 0;
}