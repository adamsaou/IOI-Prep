#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    //TODO learn "struct"

    struct Player{
        string name;
        int score;
    };

    int n; cin >>n;
    vector<Player> p(n);

    for(auto &x : p){
        cin >> x.name >> x.score;
    }

    sort(p.begin(), p.end(), [](const Player &a, const Player &b));




    
    return 0;
}