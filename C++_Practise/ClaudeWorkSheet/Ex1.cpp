#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int ans = accumulate(nums.begin(), nums.end(), 0);

    cout << ans << "\n";
    
    return 0;
}