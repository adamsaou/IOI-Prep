#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;

    vector <int> nums(n);

    for(int i = 0; i<n;i++){
        cin>>nums[i];
    }

    sort(nums.begin(),nums.end());
    
    ll difference = 0;
    for(int i = 0;i<n; i+= 2){
        difference += abs(nums[i] - nums[i+1]);
    }

    cout << difference << "\n";

    return 0;
}