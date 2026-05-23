#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; cin >>s;
    set <char> set;

    set.insert(s.begin(), s.end());

    int n = set.size();

    if(n % 2 == 0) cout << "CHAT WITH HER!" << "\n";
    else cout << "IGNORE HIM!" << "\n";

    

    return 0;
}