#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string pass; cin >> pass;
    int n; cin >> n;

    
    bool exact = false;
    bool right = false;
    bool left = false;
    
    for (int i = 0; i < n; i++){
        string x; cin >> x;

        

        if(pass == x){
            exact = true;
        }
        if (x[0] == pass[1]){
            left = true;
        }
        if (x[1] == pass[0]){
            right = true;
        }
    }

    if (exact == true || (right && left)){
        cout << "YES"<< "\n";
    } else {
        cout << "NO" << "\n";
    }
    return 0;
}

