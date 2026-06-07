#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int a,b; cin>>a>>b;


    vector <string> roll({"1/6", "1/3", "1/2", "2/3", "5/6", "1/1"});
    a = max(a,b);

    cout << roll[6 - a];
        
    return 0;
}