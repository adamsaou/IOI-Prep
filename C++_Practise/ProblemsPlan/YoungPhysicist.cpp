#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    //x, y ,z equlibrium if if the sum al xi =0, yi = 0 and zi=0 then output YES, else NO

    int n; cin >>n;


        int sum_x =0;

        int sum_y =0;

        int sum_z =0;


    for (int i = 0; i < n; i ++){
        int x, y, z; cin >>x>>y>>z;
        sum_x += x;
        sum_y += x;
        sum_z += x;

    }

    if(sum_x == 0 && sum_y == 0 && sum_z == 0) cout << "YES" << "\n";
    else {
        cout << "NO" << "\n";
    }
    return 0;
}