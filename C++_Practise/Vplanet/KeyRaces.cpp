#include <bits/stdc++.h>

using namespace std;

int calc_typing(int n, int v, int t){
    int ans = 2*t + (n * v);
    return ans;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int s, vf, vs, tf, ts; cin >> s>> vf>> vs>> tf>> ts;

    int first = calc_typing(s, vf, tf);
    int second = calc_typing(s, vs, ts);
    
    if (first < second){
        cout << "First" << "\n";
    } 
    else if (first > second) {
        cout << "Second" << "\n";
    }
    else{
        cout << "Friendship" << "\n";
    }

    
    return 0;
}

