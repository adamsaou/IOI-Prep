#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin>>s;
    int counter = 1;
    for (int i = 1; i < s.length(); i++){
        if (s[i - 1] == s[i]){
            counter++;
            if (counter ==7){
                cout << "YES" << "\n";  
                return 0;
            }
        }else {
            counter = 1;
        }
    }
    cout << "NO" << "\n";
}