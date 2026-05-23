#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n; cin >> n;
    set<ll> s;

    for (int i = 0; i < n - 1; i++){ // instead of i = 1, use "int i = 0; i < n -1; i ++" since we count n - 1 nums
        int x;
        cin >>x;
        s.insert(x);
    }
    ll sum = accumulate(s.begin(), s.end(), 0LL); //whenever we need to compute an ll, use LL as a sufix in numbers 
    ll misnum = (n * (n + 1) / 2 ) - sum;
    
    cout << misnum << "\n";
    return 0;
}