#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    string s; cin>>s;
    map <char, int> freq;

    for(char c: s){
        freq[c]++;
    }
    for(auto p : freq){
        cout << p.first << " : " << p.second << "\n";
    }

    //bool exists = true;
    int uneven = 0;
    for(auto p : freq){
        if(p.second % 2 != 0){
            uneven++;
        } else if(uneven > 1){
            cout << "NO SOLUTION" << "\n";
            return 0;
        }
        //cout << p.first << " : " << p.second << "\n";
    }

    
    return 0;
}