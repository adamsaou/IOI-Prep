#include <bits/stdc++.h>

using namespace std;

#define ll double

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >>t;

    ll summ = 0;

    for (int i = 0; i < t ; i++){
        int x;
        cin >>x;
        summ += x;
    }

    
    cout << summ / t << "\n";
    
    return 0;
}