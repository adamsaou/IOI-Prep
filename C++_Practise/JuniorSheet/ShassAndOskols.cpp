#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin>>n;
    vector<int> birds(n);
    
    for(int i = 0; i<n;i++){
        cin>>birds[i];
    }
    int m; cin>>m;

    for(int i = 0; i < m; i++){
        int x,y; cin>>x>>y;
        birds[i] = 0;
        birds[i-1] = floor((birds[i] - 1)/2);
        birds[i+1] = ceil((birds[i] - 1)/2);
    }
    for(int i=0;i < m;i++){
        cout<<birds[i]<<"\n";
    }

    
    return 0;
}

