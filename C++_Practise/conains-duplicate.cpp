#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0; cin >> n;
    
    vector <int> v(n);
    set <int> s;


    for (int i = 0; i < n; i++){
        cin >> v[i];
        s.insert(v[i]);
    }

    if (s.size() < v.size()){
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
    
    return 0;
}

/*
Better solution:
======================================================
int x;
cin >> x;

if (s.count(x)) {
    cout << "YES\n";
    return 0;
}

s.insert(x);
*/