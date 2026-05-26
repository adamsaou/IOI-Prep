#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    
    string s; cin>>s;
    int ans = 0;
    int l = 26;
    char curr = 'a';
    for(int i =0; i < s.length(); i++){
        //26 lettres
        //max num to add = 26/2 = 13
        ans += min(abs(s[i] - curr),min(abs(s[i]+26-curr),abs(curr+26-s[i])));
        curr = s[i];
    }

    cout << ans;
    return 0;
}