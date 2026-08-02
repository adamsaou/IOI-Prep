#include <bits/stdc++.h>

using namespace std;

struct Building {
    string name;
    int height;
};

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;

    vector <Building> b(n);


    for(int i =0; i<n;i++){
        cin >> b[i].name >> b[i].height;
    }


    Building best = b[0];
    for(int i =0; i<n;i++){
        if(b[i].height > best.height){
            best = b[i];
        }

    }
    
    cout << best.name << " "<< best.height << "\n";
    
    return 0;
}