#include <bits/stdc++.h>

using namespace std;


#define ll long long
int main(){

    ios::sync_with_stdio(false), cin.tie(NULL);

    int n; cin>>n;
    //Watch for:
    //vector<int> nums(n);

    vector<ll> nums(n);

    // for (auto &v : nums) {
    //     cin >> v;
    // }
    //TO LOOK FOR SUGAR SYNTAX

    for(int i =0;i<n;i++){
        cin>>nums[i];
    }

    sort(nums.begin(),nums.end());

    ll ans = max(nums[0] * nums[1] , nums[n - 1] * nums[n - 2]);

    cout << ans << "\n";
    return 0;
}

// Lesson: sorting reveals the structure — the max
// product is either the two biggest or the two smallest
// (two negatives multiply to a positive). And use long
// long : 10⁹ × 10⁹ overflows int .