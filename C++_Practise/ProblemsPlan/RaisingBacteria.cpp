#include <bits/stdc++.h>

using namespace std;



int convert_to_bin(int n){
    int count = 0;
    while(n > 0){
        if(n & 1) count++;
        n = n >> 1;
    }
    return count;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;

    cout << convert_to_bin(n);
    
    return 0;
}

