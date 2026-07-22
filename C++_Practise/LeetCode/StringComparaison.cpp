#include <bits/stdc++.h>

using namespace std;

int solve(){
    string s; cin >> s;

    // sort(s.begin(), s.end());
    
    string ans;

    for(int i = 0; i < s.length(); ){
        int j = i;

        while(j < s.length() && s[i] == s[j]){
            j++;
        }

        ans += s[i];
        
        int cnt = j-i;
        if(cnt > 1){
            ans += to_string(cnt);

        }
        i = j;
    }

    cout << ans << "\n";
    return 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    solve();
    
    return 0;

}