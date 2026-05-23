#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x; cin >> n >> x;
    vector <int> v(n);

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    int res = 0; 
    for (int i = 0; i < n; i++){
        if (v[i] > x){
            res += (v[i] - x);
        }
    }

    cout << res << "\n";

    return 0;
}