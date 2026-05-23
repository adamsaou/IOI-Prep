#include <bits/stdc++.h>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin >> s;//string
    int c = 1; int b = 1; //c is current and b is best value

    for (int i = 0; i < s.length() - 1; i++){
        if(s[i] == s[i +1]){
            c++;
        } else {
            c = 1;    
        }
        b = max(c , b);

    }

    cout << b << "\n";
    return 0;
}