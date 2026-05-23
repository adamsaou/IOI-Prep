#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >>n;

    int count_25 = 0;
    int count_50 = 0;

    bool possible = true;

    for (int i = 0; i < n; i++){
        int x; cin >>x;
        if (x == 25){
            count_25++;
        }
        else if (x == 50){
            if (count_25 > 0){
                count_25 --;
                count_50 ++;
            } else {
                possible = false;
                break;
            }
        }
        else if (x == 100){
            if (count_25 > 0 && count_50 > 0){
                count_50 --;
                count_25 --;
            } else if (count_25 >= 3){
                count_25 -= 3;
            } else {
                possible = false;
                break;
            }
        }
        
    }
    if (possible) cout << "YES" << "\n";
    else  cout << "NO" << "\n";
    

    
    return 0;
}