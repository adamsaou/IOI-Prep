#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    int n; cin >> n;

    vector<int> v(n);
    for (int i; i < n; i++){
        cin >> v[i];
    }

    int sum = 0;

    for (int x : v){
        sum += x;
    }

    cout << sum << "\n";
    return 0;
}