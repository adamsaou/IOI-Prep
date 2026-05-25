#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin>>n;
    vector<int> v(n);
    int police = 0;
    int crime = 0;
    int ans = 0;

    for(int i = 0; i < n;i++){
        cin>>v[i];
    }

    for(int i = 0; i < n;i++){
        if(v[i] == 1){
            police++;
            if(crime < 0){
                crime += police;
                police += crime;
            }
        } else if (v[i] == -1){
            crime --;
            if(police > 0){
                crime += police;
                police += crime;
            } else {
                ans++;
            }
        }

    }
    cout << ans;
    
    return 0;
}