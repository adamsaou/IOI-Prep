#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >>n;

    vector <int> p(n);
    int ans = 0;


    for(int i = 0; i<n;i++){ cin >> p[i];}

    for(int i = 0; i<n - 2;i++){ 
        if(p[i+ 1] > p[i] && p[i + 2] < p[i+1]){
            ans++;
        }

    }
    cout << ans << "\n";

    return 0;
}