#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin>>n;
    vector<int> nums(n*2);
    vector<int> ans(n*2);


    for(int i = 0; i<(n*2);i++){ 
        cin >> nums[i];
    }

    for(int i = 0; i<n;i++){
        ans[2*i] = nums[i];
        ans[2*i+1] = nums[i + n-1];
        
    }

    for(int i = 0; i<(n*2);i++){
        cout << ans[i] << " ";
    }    
    
    return 0;
}