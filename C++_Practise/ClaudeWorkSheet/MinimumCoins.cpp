#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n;cin>>n;

    ll ans = 0;

    while(n !=0){
        if(n >= 25){
            ans++;
            n -= 25;
    
            //  cout << "test: "<<n << "\n";
            
        }
        else if(n >= 10){
            ans++;
            n -= 10;
            //  cout << "test: "<<n << "\n";

        }
        else if(n >= 5){
            ans++;
            n -= 5;
            //  cout << "test: "<<n << "\n";

        }
        else if(n >= 1){
            ans++;
            n--;
            //  cout << "test: "<<n << "\n";
        }
    }

    cout << ans << "\n";

    return 0;
}

//Proper Solution

// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//  long long m; cin >> m;
//  int coins[] = {25, 10, 5, 1};
//  long long cnt = 0;
//  for (int c : coins) {
//  cnt += m / c; //
// take as many of the biggest as possible
//  m %= c; //
// keep the remainder
//  }
//  cout << cnt << "\n";
// }


// Lesson: greedy = take the biggest useful piece first.
// (This works for these specific coins. Greedy doesn't
// work for every coin system — that's why you sanitycheck it.)
