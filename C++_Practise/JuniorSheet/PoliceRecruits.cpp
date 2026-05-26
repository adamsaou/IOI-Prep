#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin>>n;
    int ans = 0;
    int total = 0;

    while(n--){
        int temp;
        cin>>temp;
        if( temp == -1){
            if(!total) ans++; //if (total == 0)
            else total--;
        } else {
            total += temp;
        }
    }
    cout << ans;
    
    return 0;
}