#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    string s; cin>>s;
    string c;

    if(s.length() == 1){
        cout<<s<<"\n"; 
        return 0;
    } 
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1' || s[i] == '2' || s[i] == '3'){
            c.push_back(s[i]);
        }
    }
    sort(c.begin(), c.end());

    cout<<c[0];
    for(int i = 1; i < c.length(); i++){
        cout<<"+"<<c[i];
    }
    return 0;
}