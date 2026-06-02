#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int a,b,c,d; cin>>a>>b>>c>>d;
    set<int> shoes;
    shoes.insert(a);
    shoes.insert(b);
    shoes.insert(c);
    shoes.insert(d);
    
    cout<< 4 - shoes.size();
    
    return 0;
}