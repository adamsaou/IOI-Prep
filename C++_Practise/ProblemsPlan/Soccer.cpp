#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    int t; cin >>t;

    while(t--){
        int x1,y1; cin>>x1>>y1;
        int x2,y2; cin>>x2>>y2;

        if(x1 > y1 && x2 > y2){
            cout <<"YES"<<"\n";            
        } else if(x1 < y1 && x2 < y2){
            cout <<"YES"<<"\n";
        } else {
            cout <<"NO"<<"\n";
        }
    }
    
    return 0;
}