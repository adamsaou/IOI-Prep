#include <bits/stdc++.h>

using namespace std;

struct Player {
    string name;
    int score;
    int age;
};

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;

    vector <Player> p(n);

    for (int i = 0; i <n;i++){
        cin >> p[i].name>> p[i].score>> p[i].age;
    }

    sort(p.begin(), p.end(), [](const Player& a,const Player& b){
        if(a.score != b.score) return a.score > b.score;
        return a.age < b.age;
    });

    for(int i =0;i<n;i++){
        cout << p[i].name <<" "<< p[i].score <<" "<< p[i].age << "\n";
    } 

    return 0;
}