#include <bits/stdc++.h>

using namespace std;

int32_t main(){ //find minimum possible sum

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<int> v(n);
    map<int, int> frequency;

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    for (int x : v){
        frequency[x]++;
    }
    for (int i = 0; i < n; i++){
        int sum = accumulate(v.begin(), v.end(), -1 *(v[i] * frequency[i]));
    }

    cout <<"\n";
    
    return 0;
}