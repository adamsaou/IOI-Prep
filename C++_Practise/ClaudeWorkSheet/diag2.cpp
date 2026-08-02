#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin>>n;

    vector <int> nums(n);

    for(int  i = 0;i<n;i++){
        cin>>nums[i];
    }

    sort(nums.begin(), nums.end());
    
    int difference = abs(nums[0] - nums[1]);
    for(int  i = 0;i<n - 1;i++){
        difference = min(abs(nums[i] - nums[i + 1]) , difference);
    }

    cout << difference << "\n";

    
    return 0;
}