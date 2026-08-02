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
#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout ("shell.out");
    ifstream fin ("shell.in");
    int t;
    
    fin >> t;
    int ans = 0;

    vector <int> shells(2);

    for(int i = 0; i<t; i++){
        int a, b, g; 
        fin >> a >> b >> g;
        // if(a == g || b == g){
        //     ans++;
        // }
        //first thing i "saw"
    
    }

    fout << ans << "\n";
    return 0;
}