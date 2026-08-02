#include <bits/stdc++.h>

using namespace std;

struct Player {
    string name;
    int wins;
    int losses;
    int rating;
};

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin>>n;

    vector <Player> p(n);

    for(int i = 0;i<n; i++){
        cin >>p[i].name>>p[i].wins>>p[i].losses>>p[i].rating;
    }

    sort(p.begin(), p.end(), [](const Player& a, const Player& b){
        if (a.wins != b.wins){
            return a.wins > b.wins;
        }
        if(a.losses != b.losses){
            return a.losses < b.losses;
        }
        if(a.rating != b.rating){
            return a.rating > b.rating;
        }
        return a.name < b.name;
    });

    for(int i = 0;i<n;i++){
        cout << p[i].name << " " << p[i].wins << " " << p[i].losses << " " << p[i].rating << "\n";
    }
    
    return 0;
}