#include <bits/stdc++.h>

using namespace std;

#define ll long long 

bool check_sum(ll n){
    // if((n*(n+1) % 4) == 0){
    //     return true;
    // } else {
    //     return false;
    // }

    //Syntatic sugar:
    return (n*(n+1) % 4 == 0);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    ll n; cin>>n;
    vector<int> set1{};

    vector<int> set2{};

    //7
    // 4
    // 1 + 2 + 4 + 7
    // 3
    // 3 + 5 + 6
    //sum = n(n+1)/2
    //sum/2 = n(n+1)/4
    
    // old idea
    // int accumulation = accumulate(set1.begin(),set1.end(),0);
    // int num = 1;
    
    //==Entire solution logic was inside that bracket which is innefficient==
    
    // if(check_sum(n)){
    //     while(accumulation < (n*(n+1)/2)){
    //         set1.push_back(num);
    //         accumulation += num;
    //         num++;
    //     }
    //     for(int i = 1;i<n;i++){
    //         if(i == set1[i]){
    //             set2.push_back(i);
    //         }
    //     }
    // } else {
    //     cout << "NO";
    //     return 0;
    // }

    if(!check_sum(n)){
        cout << "NO\n";
        return 0; //early exit
    }

    //then if that doesn't pass, it is automaticly true
    // now the hard implentation part
    cout << "YES\n";
    
    ll target = (n*(n+1))/4; //the sum of the half of the sum

    //IDEA:
    //we move from n to 1
    for(int i = n; i >=1; i--){
        if(i <= target){
            set1.push_back(i); //reduces the target by what we found
            target -=i;
        } else {
            set2.push_back(i); //this num is too big for the remainder
        }
    } 

    //
    
    //cout set1
    cout << set1.size() <<"\n";
    for(int num : set1){
    //for(int i = 0; i < set1.size();i++){
    //syntatic sugar
        cout << num << " ";
    }
    cout  <<"\n";

    
    //cout set2
    cout << set2.size() <<"\n";
    for(int num : set2){
        //for(int i = 0; i < set2.size();i++){
        //syntatic sugar
            
        cout << num << " ";
    }    return 0;
}