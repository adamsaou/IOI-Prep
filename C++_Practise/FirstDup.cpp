#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n = 0; cin >> n; //read n

    set <int> s; //create empty set 

    for(int i = 0; i < n; i++){ //loop n times
        int x;//read x
        cin >> x;
        if(s.count(x)){ //if x is already in the set
            cout << x << "\n"; 
            return 0; //print 'x' and exit the program
        }
        s.insert(x); // add x to s
    }
    cout << "-1\n";// if no dups found, return -1
    return 0;
}

/*
Time complexity: O(n), it's better than nested double loops 'O(n²)'

Pseudo code:
(look at the comments)

IMPORTANT: 
"cout << x;
return 0;" is called an early exit, helpful in future CP exercices!
*/
