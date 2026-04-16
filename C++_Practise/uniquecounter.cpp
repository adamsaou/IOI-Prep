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