#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin>>n;
    vector<int> nums(n);

    for(int i = 0; i < n;i++){
        cin>>nums[i];
    }
    for(int i = n - 1;i>=0;i--){
        cout<< nums[i]<<" ";
    }
    
    return 0;
}