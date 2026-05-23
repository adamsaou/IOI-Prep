#include <bits/stdc++.h>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c; cin >> a >> b >> c;

    bool condition1 = false;
    bool condition2 = false;

    if(a != b){
        condition1 = true;
    }
    if(b == c){
        condition2 = true;
    }

    if(condition1 && condition2){
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
    
    return 0;
}