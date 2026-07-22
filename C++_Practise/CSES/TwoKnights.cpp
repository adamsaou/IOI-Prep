#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll solve(ll k){
    ll ans = (k*k) * ((k*k) - 1) / 2;   
    ll att = 4 * (k - 1) * (k - 2); 
    ll bruh = ans - att; 
    return bruh;
}


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);
    
    ll k; cin>>k;

    for(ll i = 1; i<=k;i++){
        // ll ans = (i*i - 2) * (i + 1);
        //failed idea lol  
        // if(k == 1){
        //     cout << 0 << "\n";
        //     return 0;
        // }
        // if(i == 1){
        //     cout << 0 <<"\n";
        //     i++;
        // }
        
        // ll ans = (i*i) / ((i*i) - 1) / 2;   
        // ll att = 4 * (i - 1) * (i - 2); 
        // cout << ans - att <<"\n";
        cout << solve(i) << "\n";
        // ans = 0;
    }

    return 0;
}