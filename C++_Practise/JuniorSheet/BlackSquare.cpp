#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int a, b, c, d; cin>>a>>b>>c>>d;
    string s; cin>>s;
    // 1+2+3+2+1+4 = 13
    // 1+1+5+5+1 = 13
    int ans = 0;

    for(int i = 0; i < s.length(); i++){//each character in the string s
        if(s[i] == '1') ans += a;
        else if(s[i] == '2') ans+=b;
        else if(s[i] == '3') ans+=c;
        else if(s[i] == '4') ans+=d;
    }

    cout << ans;


    
    return 0;
}


