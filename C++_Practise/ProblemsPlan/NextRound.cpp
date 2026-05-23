#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;  cin >>n >> k;
    int res = 0;
    vector<int> v(n);
    
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    int reference = v[k - 1];
    for (int i = 0; i < n; i++){
        if (v[i] >= reference && v[i] > 0){
            res++;
        }
    }
    cout << res << "\n";
    
    return 0;
}