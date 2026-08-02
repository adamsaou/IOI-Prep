#include <bits/stdc++.h>

using namespace std;

struct Player {
    string name;
    int score;
};

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;

    vector <Player> p(n);

    for(int i = 0;i<n;i++){
        cin >> p[i].name>> p[i].score;
    }

    sort(p.begin(), p.end(), [](const Player& a, const Player& b){
        return a.score > b.score;
    });

    for(int i = 0;i<n;i++){
       cout << p[i].name<< " "<<p[i].score << "\n";
    }
    
    return 0;
}