#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    ll n; cin >> n;//10
    int ans = 0;

    ll p5 = 5;
    while(p5 <= n){
        ans += n / p5;
        p5 *= 5;
    }    
    cout << ans << "\n";
    return 0;
}

//