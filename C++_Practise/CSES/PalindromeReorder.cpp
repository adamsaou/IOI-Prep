#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s; cin>>s;
    map <char, int> freq;

    
    //counts frequency of each letter
    for(char c: s){
        freq[c]++;
    // }
    // for(auto p : freq){
    //     cout << p.first << " : " << p.second << "\n";
    }

    int min_freq = INT_MAX;
    int min_freq_element = -1;

    for (const auto& pair: freq){
        if(pair.second < min_freq){
            min_freq = pair.second;
            min_freq_element = pair.first;
        }

    }

    //bool exists = true;
    int uneven = 0;
    for(auto p : freq){
        if(p.second % 2 != 0){
            uneven++;
        }
        if(uneven > 1){
            cout << "NO SOLUTION" << "\n";
            return 0;
        }
        // cout << p.first << " : " << p.second << "\n";
    }
    //check if it's possible to make a palindroe out of that string


    sort(s.begin(),s.end());
    // cout << s<< "\n";
    // cout << "YES"<< "\n";

    string first;
    string m;
    //making a const alg to make the palindrome    
    //AAAACACBA
    
    for(int i = 0;i<s.length(); ){
        if(i == s.length() - 1 || s[i] != s[i+1]){
            m = s[i];
            i++;
        } else {
            first.push_back(s[i]);
            i += 2;
        }

    }
    string end = first; 
    reverse(first.begin(), first.end());




    //idea: sort from A-Z
    //AAAAAABCC
    //construct 2 substrings:


    //AACABACAA


    string last = first + m + end;
    cout << last << "\n";

    
    return 0;
}