#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >>t;
    vector<vector<int>> v;
    vector<int> b;

    v.resize(t);

    for(int i = 0; i < t; i++){
        int n; cin>>n;
        for (int j = 0; j < n;j++){
            int x; cin>>x;    
            v[i].push_back(x);
        }
    }
    int x,y; cin>>x>>y;
    cout << v.at(x-1).at(y-1) << "\n";
        
    return 0;  
}