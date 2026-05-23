#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b; cin >>a>>b;
    // each year a*3 while b*2
    //cout each year while a < b
    int c = 0;
    while (a <= b){
        a *= 3;
        b *= 2;
        c++;
    }

    cout << c;


    return 0;
}