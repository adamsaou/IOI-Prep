#include <bits/stdc++.h>
using namespace std;

int main() {
    ios ::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n; //read total number of elements
    
    set <int> s;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        s.insert(temp); //the set filters the dups as i insert
    }

    cout << s.size() << "\n"; //printing the unique elements
    
    return 0;
}

/*
--> Seen pattern: In a lot of problems, i need to know if i have encountered an element before, instead of nested loops, i use 'insert' every element onto a set, it filters out dups
-->(IMPORTANT) Automatic sorting: the set keeps elements sorted, if i iterate in a set from 'begin()' to 'end()'

--> Time Complexity: O(N log(N)): Insertion takes O(N log(N)) time
*/