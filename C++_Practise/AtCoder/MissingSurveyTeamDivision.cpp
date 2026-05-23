#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n ; cin >>n;
    int res = 0;
    int occ_r = 0;
    int occ_w = 0;
    int occ_q = 0;


    for (int i = 0; i < n; i++){
        char x; cin >> x;
        if (x == 'W') occ_w++;
        else if (x == 'R') occ_r++;
        else occ_q++;
    }
    
    int d = abs(occ_w - occ_r);

    if (occ_q >= d){
        cout << (occ_q - d) % 2 << "\n";
    } else {
        cout << d - occ_q << "\n";
    }


    return 0;
}