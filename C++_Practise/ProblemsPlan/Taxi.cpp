#include <bits/stdc++.h>

using namespace std;

int solve(int,int,int,int);

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    int ans= 0;
    vector<int> v;
    map<int, int> counts;

    for (int  i = 0; i < n; i++){
        int x; cin>>x;
        v.push_back(x);
    }

    for (int x : v){
        counts[x]++;
    }
    int t1= counts[1];
    int t2= counts[2];
    int t3= counts[3];
    int t4= counts[4];
    
    //t1 = 1
    //t2 = 1
    //t3 = 2 
    //t4 = 1 (these full the taxi)
    /*
    since we got 2 groups of 3 , and one group of 1
    we get 1 taxi with: 3 + 1
    so t3 = 0 and t1 = 1
    
    as a left over, so far we filled 2 taxis (4, (3 + 1))

    //t1 = 0
    //t2 = 1
    //t3 = 1 
    //t4 = 0
    
    we got one t2 and a t3
    since t2 < 2 and t1 > 2
    ans++; //taxis ==> (4, (3 + 1), 2)

    now we enter the left-over 3s groups:

    ans += t3 //taxis ==> (4,(3 + 1), 2, 3)
    */

    ans  = solve(t1, t2, t3, t4);

    cout << ans;

    
    return 0;
}

int solve(int t1,int t2, int t3, int taxis){
    int paired_taxis = min(t1, t3);
    taxis += paired_taxis;
    t3 -= paired_taxis;
    t1 -= paired_taxis;
    taxis += t3;

    taxis += t2/2;
    t2 = t2%2;

    if(t2 == 1){
        if(t1 >= 2){
            taxis++;
            t1 -= 2;
        } else {
            taxis++;
            t1 = 0;
        }
    }

    taxis += (t1 + 3) / 4;

    return taxis;
}