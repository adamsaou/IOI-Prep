#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;cin>>n;

    vector<vector<int>> groups(4);

    for(int i = 1; i <=n; i++){
        int x; cin>>x;
        groups[x].push_back(i);
    }

    int teams = min({groups[1].size(),groups[2].size(),groups[3].size()});
    
    cout<< teams<< "\n";

    for(int i = 0; i < teams;i++){
        cout<< groups[1][i] << " " << groups[2][i] << " " << groups[3][i] << "\n";
    }
    
    return 0;
}