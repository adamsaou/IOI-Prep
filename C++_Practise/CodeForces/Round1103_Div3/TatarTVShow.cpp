#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        string s; cin>>s;
        vector<int> counts(k, 0);
        for(int i = 0; i < n; i++){
            if (s[i] == '1'){
                counts[i % k]++;
            }
        }

        bool poss = true;
        for (int i=0; i<k;i++){
            if (counts[i] % 2 != 0){
                poss = false;
                break;
            }
        }

        if(poss) {
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
    
    return 0;
}