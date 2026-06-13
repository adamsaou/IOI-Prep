/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: your_id_here
TASK: ride
LANG: C++       
PROG: ride          
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    fin >> a >> b;
    int x = 1,y = 1;
    for(int i = 0;i<a.length();i++){
        x *= (static_cast<int>(a[i]) - 64);
    }

    for(int i = 0;i<b.length();i++){
        y *= (static_cast<int>(b[i]) - 64);
    }

    if ((x % 47) == (y % 47)){
        fout << "GO" << "\n";
    } else {
        fout << "STAY" << endl;
    }
    
    return 0;
}