#include <bits/stdc++.h>

#define pb push_back
using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin>>t;
    vector<int> v(t);
    
    for(int i = 0; i <t;i++){
        cin>>v[i];
    }    
    
    int left = 0;
    int right = v.size() - 1;
    
    int s = 0;
    int d = 0;
    
    for(int i = 0; i < t; i++){
        if(i%2==0){
            if(max(v[left], v[right]) == v[left]){
                s+= v[left];

                left++;
            } else if (max(v[left], v[right]) == v[right]) {
                s+= v[right];
                
                right--;
            } else {
                s+= v[left];
            }
        }    
            
        else {
            if(max(v[left], v[right]) == v[left]){
                d+= v[left];
                            
                left++;
            } else if(max(v[left], v[right]) == v[right]) {
                d+= v[right];
                            
                right--;
            } else {
                d+= v[left];
            }
        }
    
    }
    
    cout <<s<< " "<<d;
    
    return 0;
}