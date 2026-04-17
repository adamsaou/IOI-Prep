#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> v(n);

    for(int i = 0; i <n; i++){
        cin >> v[i];
    }

    int mx = v[0];
    //never use max as a variable name
    //IMPORTANT: 'int mx = 0' is good, but if it was negative it'll break, so use 'int mx = v[0];'
    for (int x : v){
        if (x >= mx)
            mx = x;
    }

    cout << mx << "\n"; 
    return 0;
}