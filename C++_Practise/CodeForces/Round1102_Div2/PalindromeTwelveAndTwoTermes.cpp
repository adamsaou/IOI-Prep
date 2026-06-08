#include <bits/stdc++.h>

using namespace std;

#define ll long long


string palindrome(string s){
    int left = 0;
    int right = s.size() - 1;
    
    while(left<right){
        s[right] = s[left];
        left++;
        right--;
    }
    return s;
}

void solve(){
    ll n;
    cin>>n;
    string s = to_string(n);
    ll tg = n%12;

    string pal = palindrome(s);
    ll a = stoll(pal);
    

    ll b = 0;
    
    cout<<a << " "<<b << "\n";
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}