#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0; cin >> n;
    set<int> s;
    map<int, int> m;

    for (int i = 0; i < n; i++){
        int x;
        cin >>x;

        m[x]++;
    }
    int count = 0;
    for (auto p : m){
        if (p.second >=2){
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}