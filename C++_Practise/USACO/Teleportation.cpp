/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: your_id_here
TASK: test
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("teleport.out");
    ifstream fin ("teleport.in");
    int a, b, x, y;
    int min_dist = 0;
    int travel_dist = 0;
    fin >> a >> b >> x >> y;

    min_dist = abs(min(a,b) - min(x, y)) + abs(max(a,b) - max(x,y)); 
    travel_dist = abs(a - b);
    
    min_dist= min(min_dist, travel_dist);

    fout << min_dist << endl;
    return 0;
}