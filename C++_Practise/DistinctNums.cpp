#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

    int n = 0; cin >> n;

    set <int> s;
    vector<int> v(n);

    for (int i = 0; i < n; i++){
        cin >> v[i];
        s.insert(v[i]);
    }
    

    cout << s.size() << "\n";
    return 0;
}