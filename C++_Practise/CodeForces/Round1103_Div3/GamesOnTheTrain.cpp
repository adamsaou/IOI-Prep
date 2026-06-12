#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> towers(n);

        for(int i = 0;i<n;i++){
            cin>>towers[i];
        }
        sort(towers.rbegin(), towers.rend());

        int k = towers[0] - towers.back() + 1;
        cout << k << "\n";
    }
    
    return 0;
}