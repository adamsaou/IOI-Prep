#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int x=0,y=0;
    string s; cin>>s;

    for(int i = 0; i<s.length();i++){
        if(s[i] == 'U'){
            y++;
        }
        if(s[i] == 'D'){
            y--;
        }
        if(s[i] == 'L'){
            x--;
        }
        if(s[i] == 'R'){
            x++;
        }
    }

    cout << x<< " "<< y << "\n";
    
    return 0;
}


