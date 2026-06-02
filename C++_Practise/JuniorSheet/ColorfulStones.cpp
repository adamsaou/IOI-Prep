#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin>>s;
    string t; cin>>t;

    int current = 0;

    for(int i = 0; i < t.length(); i ++){
        if(s[current] == t[i]){
            current++;
        }
    }

    cout << current+1;

    return 0;
}