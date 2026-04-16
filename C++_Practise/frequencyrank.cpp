#include <bits/stdc++.h>
using namespace std;

int main(){


    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    map <char, int> freq;

    for (char c : s){
        freq[c] ++;
    }

    int max_count = 0;
    char  best_char = ' ';
    
  //for (auto const& [key......, value] : freq)  
    for (auto const& [character, count] : freq) {
        //key is the character ex: 'p'
        //value is the count ex: 2

        if (count > max_count) {
            max_count = count;
            best_char = character;
        }
    }

    cout << best_char << " appears " << max_count << " times " << "\n";
    return 0;
}

/*
--> Map as a counter: 'std::map' is an array where the index doesn't have to be a number

-->(IMPORTANT) the C++17 "Structured Binding" the synatx 'for (auto const& [key, value] : my_map)' is the cleanest way to look in everything  inside the/a map, it's very readable/fast

--> Time Complexity: O(N log(M)): string of N and M unique characters (very efficient)
*/