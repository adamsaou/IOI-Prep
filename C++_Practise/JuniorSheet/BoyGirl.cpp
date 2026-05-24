#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    string s; cin >>s;
    set<char> set;

    for(int i = 0; i < s.length(); i++){
        set.insert(s[i]);
    }

    if(set.size() % 2 == 0) cout << "CHAT WITH HER!\n";
    else cout << "IGNORE HIM!\n";    
    return 0;
}