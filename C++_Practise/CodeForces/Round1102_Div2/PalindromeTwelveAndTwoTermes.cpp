#include <bits/stdc++.h>

using namespace std;

bool Palindrome(string s){
    int left = 0;
    int right = s.size() - 1;
    
    while(left<right){
        if(s[left] == s[right]){
            left++;
            right--;
        } else {
            return false;
        }
    }
    return true;
}

void solve(int n){
    int a = n;
    string aa = to_string(a);
    int b = 0;
    while(Palindrome(aa) != true){
        a -= 12;
        b+= 12;
        aa = to_string(a);
        Palindrome(aa);
    }
    cout<<a << " "<<b << "\n";
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        solve(n);
    }
    
    return 0;
}