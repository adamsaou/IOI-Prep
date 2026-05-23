#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    string s; cin >>s;
    int count = 0;
    for (int i = 1; i < n; i++){
        if (s[i - 1] == s[i]) count++;
    }

    cout << count;

    return 0;
}