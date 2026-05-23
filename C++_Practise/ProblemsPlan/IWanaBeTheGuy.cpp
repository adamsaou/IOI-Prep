#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin >>n;
    int p; cin>>p;
    set<int> levels;

    for (int i = 0; i < p; i++){
        int x; cin >> x;
        levels.insert(x);
    }
    int q; cin>>q;
    for (int i = 0; i < q; i++){
        int x; cin >> x;
        levels.insert(x);
    }

    if (levels.size() < n){
        cout << "Oh, my keyboard!\n";
    } else {
        cout << "I become the guy.\n";
    }
    return 0;
}