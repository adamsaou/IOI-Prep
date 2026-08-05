#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int h, w; cin>>h>>w;


    int ob = (w/(h*h/100));
    if(ob >= 25){
        cout << "Yes" << "\n";
    } else { cout << "No" << "\n"; }
    
    return 0;
}