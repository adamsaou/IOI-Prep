#include <bits/stdc++.h>

using namespace std;


#define ll long long
int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    ll k,n; cin>>k>>n;

    ll ans = k / n;

    cout << ans <<"\n";
    
    return 0;
}

// Lesson: n is up to 10⁹, so a loop would be too slow —
// look for a formula. Integer division n/k counts the
// multiples directly. Always check constraints first; they
// tell you whether brute force is allowed.