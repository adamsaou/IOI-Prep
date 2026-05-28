#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false);cin.tie(NULL);

    int n; cin>>n;
    vector<int> h(n);
    vector<int> a(n);
    int ans = 0;


    for (int i = 0; i < n; i++){
        cin>>h[i];
        cin>>a[i];
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; i++){
            if (a[i] == h[j]){
                ans++;
            }
        }
    }

    cout<<ans;
    return 0;
}