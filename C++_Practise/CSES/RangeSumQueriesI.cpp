#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, q; cin >>n>>q;

    vector <int> nums(n);
    vector <ll> pref(n + 1);

    for(int i = 0; i<n;i++){
        cin>>nums[i];
    }
    pref[0] = 0;
    for(int i = 1; i<=n;i++){
        pref[i] = nums[i - 1] + pref[i - 1];
    }
    for(int i = 0; i<q;i++){
        int x, y; cin>>x>>y;
        cout << pref[y] - pref[x - 1]<< "\n";
    }
    
    return 0;
}