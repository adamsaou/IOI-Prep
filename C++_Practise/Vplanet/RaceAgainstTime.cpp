#include <bits/stdc++.h>

using namespace std;

int main(){
    ios:: sync_with_stdio(false);
    cin.tie(NULL);


    int h, m, s, t1, t2; cin >> h >> m >> s >> t1 >> t2;

    h %= 12;
    
    //making all values ranged between 0 and 10
    double h_ang = 30.0 * h+0.5 * m + (0.5 / 60.0) * s; 
    double m_ang = 6.0 * m + 0.1 * s; 
    double s_ang = 6.0 * s; 

    double t1_ang = t1 * 30.0;
    double t2_ang = t2 * 30.0;
    
    
    int hands = 0;
    //compare the angles in intervals

    auto between = [&](double x) {
        if (t1_ang < t2_ang)
            return t1_ang < x && x < t2_ang;
        else    
            return x > t1_ang || x < t2_ang;
    };
    
    if(between(h_ang)) hands++;
    if(between(m_ang)) hands++;
    if(between(s_ang)) hands++;

    if (hands == 0 || hands == 3){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    // cout << h << " " << m << " " << s << " " << t1 << " " << t2 << "\n";
    // cout << h_ang << " " << m_ang << " " << s_ang << " " << t1_ang << " " << t2_ang << "\n";
    return 0;
}