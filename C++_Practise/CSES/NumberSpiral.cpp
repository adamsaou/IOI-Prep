#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    ll t;cin>>t;

    while(t--){
        ll y, x; cin>>y>>x;

        if (y > x){
            ll ans = (y - 1) * (y - 1);
            ll add = 0;
            if (y % 2 != 0){
               add = x; 
            } else {
                add = 2 * y - x;
            }
            cout << ans + add << "\n";
        } else {
            ll ans = (x - 1) * (x - 1);
            ll add = 0;
            if (x % 2 == 0){
                add = y; 
            } else {
                add = 2 * x - y;
            }
            cout << ans + add << "\n";
        }
                
        // if (x = y){
        //     ans = (x*x) - (y-1);
        //     cout << ans << "\n";
        //     continue;
        // } else {
        //     // 6 3
        //     // 28 = 25 + 3
            
        //     if(x > y && x%2 == 0){
        //         ans = ((x - 1) * x ) + y;
        //         cout << ans << "\n";
        //         continue;
        //     }
        //     if(x > y && x%2 != 0){
        //         ans = (x*x) - (y - 1);
        //         cout << ans << "\n";
        //         continue;
        //     }
        //     if(x < y && y%2 == 0){
        //         ans = ((y - 1) * y ) + x;
        //         cout << ans << "\n";
        //         continue;
        //     }
        //     if(x < y && y%2 != 0){
        //         ans = (y*y) - (x - 1);
        //         cout << ans << "\n";
        //         continue;
        //     }
        // }
        //Good way to understand the difference of cases, but not the right anwser



        

    }
    
    //1 2 9
    //4 3 8 
    //5 6 7
    return 0;
}