#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int k,r; cin>>k>>r;
    int ans = 1;
    while((k*ans) % 10 != 0 && (k*ans) % 10 != r){
        ans++;
    }
    
    cout<<ans;
    
    return 0;
}