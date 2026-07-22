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
    ofstream fout ("mixmilk.out");
    ifstream fin ("mixmilk.in");
    int t = 100;
    // int a,b,c; fin >> a>> b>> c;
    // int ma, mb, mc; fin >> ma>> mb>> mc;
    
    
    vector<int> m_amounts(3);
    vector<int> buckets(3);

    // buckets[0] = a;
    // buckets[1] = b;
    // buckets[2] = c;

    // m_amounts[0] = ma;
    // m_amounts[1] = mb;
    // m_amounts[2] = mc;

    for(int i = 0; i < 3; i++){
        fin >> m_amounts[i] >> buckets[i];
    }

    // int bucket1 = 0;
    // int bucket2 = 0;

    for(int i = 0; i < t; i++){
        // if (buckets[bucket] + buckets[(bucket + 1) % 3] <= m_amounts[bucket]){
        //     buckets[bucket] += buckets[(bucket + 1) % 3];
        //     bucket++;
        // } else {
        //     buckets[bucket] = m_amounts[bucket];
        //     bucket++;
        //     buckets[bucket - 1] = (m_amounts[bucket] - buckets[bucket]);
        // }
        int bucket1 = i % 3;
        int bucket2 = (i +1) % 3;

        int amount = min(buckets[bucket1],m_amounts[bucket2] - buckets[bucket2] );

        buckets[bucket1] -= amount;
        buckets[bucket2] += amount;
    }

    fout << buckets[0] << "\n";
    fout << buckets[1] << "\n";
    fout << buckets[2] << "\n";
    
    return 0;
}