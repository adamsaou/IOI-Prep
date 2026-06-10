#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int a,b; cin>>a>>b;

    int sum = 0;
    for(int i = a; i<=b;i++){
        sum+=nums[i];
    }
    cout<<sum;

    
    return 0;
}