#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,s; cin >>n>>s;
    int price_candies = s*100; //converts this onto candies, or cents wtvr
    int max_sweets = -1;

    for (int i = 0; i < n;i++){
        int x,y; cin >>x>>y;

        int price_shop = (x*100) +y;
        if(price_shop <= price_candies){
            int change = price_candies - price_shop;
            int sweets = change %100;

            max_sweets = max(max_sweets, sweets);
        }
    }

    cout << max_sweets << "\n";

    return 0;
}

