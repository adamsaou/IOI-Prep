#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin>>n;
    
    ll g = 0;

    for(int i  = 0; i<n;i++){
        ll x; cin >> x;
        g = __gcd(g, x);
    }
    
    cout << g << "\n";

    return 0;
}

// Lesson: GCD of a whole array = fold __gcd across it.
// Starting from 0 works because gcd(0, x) = x .
