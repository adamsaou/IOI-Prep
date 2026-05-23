#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int t; cin >>t;


    for (int i = 0; i < t; i++){
        int n; cin >> n;    
        vector<int> v(n);
        
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int maxx = 0;
        for(int i = 0;i < n - 1; i+=2){
            maxx = max(maxx, abs(v[i] - v[i + 1]));
        }
        cout << maxx << "\n";   
    }

    return 0;
}

// #include <bits/stdc++.h> 
// #define int long long 
// #define ld long double
// using namespace std;
// void solve() {
// // here write ur code 
// }
// int32_t main() {
// ios_base::sync_with_stdio(false);
// cin.tie(nullptr); cout.tie(nullptr);
// int t = 1 ;
// //cin >> t ; if you need test cases remove //
// while (t--) solve() ; 
// return 0 ; 
// }