#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> v(n);

    //always 'int i = something' than 'int i;' since it has an undefined behaviour
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int even = 0;
    for (int x : v){
        if (x%2 == 0){
            even +=1; //or 'even++'
        }
    }

    cout << even << "\n";
    
    return 0;
}