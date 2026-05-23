#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin>>s;
    string t; cin>>t;
    
    int pos = 1;

    for (int i = 0; i < t.length(); i++){
        if (s[pos - 1] == t[i]) pos++;
    }

    cout << pos << "\n";

    return 0;
}