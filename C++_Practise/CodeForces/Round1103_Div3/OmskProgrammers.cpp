#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin>>t;
    while(t--){
        int a,b,x;
        int test = 0;
        cin >>a>>b>>x;
        int ans = 0;
        while(a!=b){
            int c1 = 0,c2 = 0,c3 = 0,c4 = 0;
            //each case for difference between a and b
            c1 = abs(a+1 - b);            
            c2 = abs(b+1 - a);
            c3 = abs(b-floor(a/x));
            c4 = abs(a-floor(b/x));

            test = min({c1, c2, c3, c4});
            if(test == c1) {
                a +=1;
            } else if (test == c2){
                b +=1;
            } else if (test == c3){
                a = floor(a/x);
            } else if (test == c3){
                b = floor(b/x);
            }
            ans++;
        }

        cout << ans << "\n";
    }
    
    return 0;
}