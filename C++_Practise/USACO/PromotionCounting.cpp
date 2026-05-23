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
    ofstream fout ("promote.out");
    ifstream fin ("promote.in");
    int a, b; fin >> a >> b; //Bronzebefore Bronzeafter
    int c, d; fin >> c >> d; //silver
    int e, f; fin >> e >> f; //gold
    int g, h; fin >> g >> h; //platinum
    
    int GoldPlatinum = h - g;
    int SilverGold = f - e + h - g;
    int BronzeSilver = d-c + f - e + h -g;
    
    fout << BronzeSilver << "\n" << SilverGold << "\n" << GoldPlatinum << "\n";    
    
    return 0;
}