#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x;
    int y;
};

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;

    vector <Point> p(n);

    for(int i = 0; i<n;i++){
        cin >> p[i].x >> p[i].y;
    }

    Point best = p[0];

    for(int i = 0;i<n;i++){
        if(p[i].y > best.y){
            best = p[i];
        }
    }

    cout << best.x << " "<< best.y << "\n";

    for(int i = 0; i<n;i++){
        cout << p[i].x << " "<< p[i].y << "\n";
    }
    

    sort(p.begin(), p.end(), [](const Point& a, const Point& b){
        return a.x < b.x;
    });

    for(int i = 0; i<n;i++){
        cout << p[i].x <<" " << p[i].y << "\n";
    }
    return 0;
}