#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    string s, t; cin>>s>>t;
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c){return tolower(c); });
    transform(t.begin(), t.end(), t.begin(), [](unsigned char c){return tolower(c); });
    if(s == t) cout <<0;
    else if (s > t) cout << 1;
    else if (s < t) cout << -1;
    
    return 0;
}