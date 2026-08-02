#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false), cin.tie(NULL);

    int n; cin>>n;

    vector <int> num(n);
    set<int> nums;

    for(int i = 0; i<n; i++){
        cin >> num[i];
        nums.insert(num[i]);
    }

    cout << nums.size() <<"\n";

    return 0;
}