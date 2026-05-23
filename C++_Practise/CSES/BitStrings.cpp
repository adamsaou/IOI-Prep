#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll MOD = 1e9 + 7;
int main(){
    ll n; cin >>n;

    ll ans  = 1;
    binpow(2, n);
    

    cout << ans << "\n";


    return 0;
}

ll binpow (ll a, ll b){
    ll res = 0;
    while (b>0){
        if (b  & 1){
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}