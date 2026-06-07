#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool check_euclid(vector<ll> nums){
    for(int i=0;i<nums.size() - 2;i++){
        if(nums[i] % nums[i + 1] == nums[i + 2]){
            continue;
        } else {
            return false;
        }
    }
    return true;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;cin>>t;

    while(t--){
        int n; cin>>n;
        vector<ll> nums(n);

        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        sort(nums.rbegin(), nums.rend());
        check_euclid(nums);
        if(check_euclid(nums) == true){
            cout<< nums[0] << " " << nums[1]<< "\n";
        } else {
            cout << -1 << "\n";
        }

    }
    
    return 0;

}