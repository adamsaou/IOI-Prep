#include <bits/stdc++.h>

using namespace std;

string solve(int a, int b){
    
    if((2 * a - b) % 3 || (2 * a - b)< 0 || (2 * b - a) % 3 || (2 * b - a)< 0){
        return "NO\n";
    } else {
        return "YES\n";
    }
}

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int k; cin>>k;

    for(int i=0;i<k;i++){
        int a, b; cin>>a>>b;
        cout << solve(a, b);
    }
    
    return 0;
}