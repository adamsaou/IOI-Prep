#include <bits/stdc++.h>

using namespace std;

int all_digits_distinct(int n);

int solve (int n){
    if (all_digits_distinct(n)){
        return n;
    }
    return solve(n +1);
}

int all_digits_distinct(int n){
    string s  = to_string(n);
    set<char> digits(s.begin(), s.end());
    return digits.size() == s.length();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    
    
    cout << solve(n+1) << "\n";
    return 0;
}