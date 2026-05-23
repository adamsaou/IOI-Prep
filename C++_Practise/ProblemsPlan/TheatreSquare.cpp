#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){

    ll n , m , a; cin >>n >>m>>a;

    ll h_tiles = (m + a - 1) / a;
    ll v_tiles = (n + a - 1) / a;

    cout << h_tiles * v_tiles << "\n";
    
    return 0;
}

ll ceiling_divide(ll x, ll y){
    return (x + y-1) / y;
} //function to use when you need to calculate the ceil of how many a in y * m for example




