#include <bits/stdc++.h>

using namespace std;



int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin>>t;
    string a;
    while(t--){
        int x; cin>>x;
        if (x == 10) a += "1";
        else a += "0";
    }

    int count = 1;
    for(int i = 0; i < a.length() - 1; i++){
        if(a[i] != a[i +1]) count++;
    }

    cout << count;
    return 0;
}