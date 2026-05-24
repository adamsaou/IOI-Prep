#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<int> v;

    for(int i = 0; i < n; i++){
        int x; cin>>x;
        v.pb(x);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    
    return 0;
}