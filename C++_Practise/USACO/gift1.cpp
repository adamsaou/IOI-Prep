/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: your_id_here
TASK: ride
LANG: C++       
PROG: gift1          
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


#define pb push_back
int main() {

    //.at()
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int  np = 0; fin >> np;
    vector<pair<string, int>> ppl(np);
    //{"dave", 0},{"laura", 0},etc

    for(int i = 0;i<np;i++){
        string s; fin>>s;
        ppl.pb({s, 0});
    }

    for(int i = 0;i<np;i++){
        string s; fin>>s; //person
        int money; fin>>money;
        int people; fin>>people;
        int mp = money/people;
        int rest = money % people;
        for(int j=0;j<people;j++){
            string person; cin >> person;
            ppl[j] = 
        }

    }
    
    return 0;
}