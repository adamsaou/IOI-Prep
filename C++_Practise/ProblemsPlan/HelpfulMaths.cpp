#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >>s;

    string nums;

    for (int i = 0; i < s.length(); i++){
        if(s[i] == '+') continue;
        else {
            nums.push_back(s[i]);
        }
    }
    sort(nums.begin(),nums.end());

    cout << nums[0];
    for(int i = 1; i < nums.length(); i++){
        cout << "+" << nums[i];  
    } 
    return 0;
}