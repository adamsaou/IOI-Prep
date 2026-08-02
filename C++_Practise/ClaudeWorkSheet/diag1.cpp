#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vector <int> nums(n);

    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }

    ll sum = accumulate(nums.begin(), nums.end(), 0LL);

    int m = nums[0];
    int e = 0;
    for(int i = 0;i<n;i++){
        m = max(nums[i], m);
        if(nums[i] % 2 == 0) e++;
    }

    cout << sum << "\n";
    cout << m << "\n";
    cout << e << "\n";
    
    return 0;
}