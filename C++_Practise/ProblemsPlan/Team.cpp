#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    int res = 0;

    while (t--){
        int a, b, c; cin >> a >> b >> c;
        int s = 0;
        if (a == 1){
            s++;
        }
        if (b == 1){
            s++;
        }
        if (c == 1){
            s++;
        }
        if (s >= 2){
            res++;
        }
    }
    cout << res << "\n";
    
    return 0;
}