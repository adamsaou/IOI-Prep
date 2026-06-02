#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    string s; cin>>s;
    string t;

    transform(s.begin(),s.end(),s.begin(), [](unsigned char c){return tolower(c);});
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'a' ||s[i] == 'o' || s[i] == 'y' || s[i] == 'e' || s[i] == 'u' || s[i] == 'i'){
            continue;
        } else {
            t.push_back('.');
            t.push_back(s[i]);
        }
    }

    cout << t;
    
    
    return 0;
}