#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector <int> v(n);
    ll count = 0;
    
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    for (int  i = 1; i < n; i++){
        if (v[i] < v[i - 1]){
            count += (v[i - 1] - v[i]);
            v[i]  = v[i -1];
        }
    }

    cout << count << "\n";
    
    return 0;

}