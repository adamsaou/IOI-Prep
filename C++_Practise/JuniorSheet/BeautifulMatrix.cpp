#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int ans = 0;
    for(int i = 1; i < 6; i++){
        for(int j = 1; j < 6; j++){
            int x; cin>>x;
            if(x == 1){            
                ans = (abs(3 - i) + abs(3 - j));
            } 
        }
    }

    cout << ans;    
    return 0;
}