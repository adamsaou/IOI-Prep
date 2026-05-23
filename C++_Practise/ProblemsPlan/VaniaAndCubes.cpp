#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);

    cin.tie(NULL);

    int n ; cin >>n;
    int h = 0;
    int i = 0;//accumulative of cubes
    while (i <= n){
        h++;
        i += (h*(h+1))/2;
    }
    cout << h - 1 << "\n";
    
    return 0;
}