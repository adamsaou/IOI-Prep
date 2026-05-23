#include <bits/stdc++.h>

using namespace std;

int main(){
    int k,n ,w; cin >> k >> n >> w;
    // 3 9 27 36
    //17 


    int price = 0;
    price = k * w *(w+1)/2;
        
    if (n >= price){
        cout << "0" << "\n";
    } else {
        cout << (price - n) << "\n";
    }
       
    return 0;
}