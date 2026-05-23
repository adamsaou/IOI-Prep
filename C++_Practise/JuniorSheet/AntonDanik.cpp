#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >>n;
    string s; cin>>s;
    int a = 0;
    int d = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'A') a++;
        else d++;
    }
    
    if(a > d) cout << "Anton\n";
    else if (a < d) cout << "Danik\n";
    else cout << "Friendship\n";
    
    return 0;
}