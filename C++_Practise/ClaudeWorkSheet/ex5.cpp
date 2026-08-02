#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct Player{
    string name;
    ll score;
};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);


    int n; cin>>n;
    vector <Player> p(n);

    for(int i = 0; i<n; i++){
        cin >> p[i].name >> p[i].score;
    }

    sort(p.begin(), p.end(), [](const Player& a, const Player& b){
        if (a.score == b.score){
            return a.name < b.name;
        }
        return a.score > b.score;
    });

    for(int i = 0; i<n; i++){
        cout << p[i].name <<" "<< p[i].score << "\n";
    }

    ll sum = 0;
    for(int i = 0; i<n; i++){
        sum += p[i].score;
    }
    cout << sum << "\n";
    return 0;
}