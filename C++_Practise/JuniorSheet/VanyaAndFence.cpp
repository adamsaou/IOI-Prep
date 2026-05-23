#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,h; cin >>n>>h;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        if(x > h) ans += 2;
        else ans++;
    }
    
    cout << ans << "\n";
    return 0;
}