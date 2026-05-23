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
    ofstream fout ("test.out");
    ifstream fin ("test.in");

    vector<int> v;

    for (int i = 0; i < 7; i++){
        int x; cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int sum = v[6];
    int a = v[0], b = v[1];

    int c = sum - a - b;

    cout << a << ' '<< b << ' '<< c << '\n';

    return 0;
}