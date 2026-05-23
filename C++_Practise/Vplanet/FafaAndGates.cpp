#include <bits/stdc++.h>

using namespace std;
// #define F p.first
// #define S p.second
// #define x cord.first
// #define y cord.second
// #define xc current.first
// #define yc current.second

int solve();

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << solve() << "\n";
    return 0;
}

int solve(){
        
    int n; 
    cin >> n;
    string s; 
    cin >> s;
    
    int x = 0;
    int y = 0;

    int ans = 0;
    
    for (int i = 0; i < n; i++){
        int prev = x - y;
        
        //storing the cords        
        if(s[i] == 'R'){
            x++;
        } else {
            y++;
        }

        int curr = x - y;

        //comparaison
        if (curr != 0 && prev == 0 && i > 0){
            if (s[i] == s[i - 1]){
                ans++;
            }
        }
        
    }
    return ans;
}

