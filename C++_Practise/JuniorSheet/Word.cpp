#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    string s; cin>>s;
    int u = 0;
    int l=0;
    for(int i = 0; i < s.length(); i++){
        if(isupper(s[i])){
            u++;
        } else {
            l++;
        }
    }
    if(l >= u){
        transform(s.begin(),s.end(),s.begin(), [](unsigned char c) {return tolower(c); });
    } else {
        transform(s.begin(),s.end(),s.begin(), [](unsigned char c) {return toupper(c); });
    }
    
    cout << s;
    return 0;
}