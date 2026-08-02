#include <bits/stdc++.h>

using namespace std;

struct Player{
    string name;
    int solved;
    int penalty;
};

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;

    vector <Player> p(n);

    for(int i = 0; i <n; i++){
        cin >> p[i].name >> p[i].solved>> p[i].penalty;
    }

    sort(p.begin(),p.end(), [](const Player& a, const Player& b){
        if (a.solved == b.solved){
            return a.penalty < b.penalty;
        }
        return a.solved > b.solved;
    });

    for(int i = 0; i <n; i++){
        cout << p[i].name << " "<<  p[i].solved <<" "<< p[i].penalty << "\n";
    }
    
    return 0;
}