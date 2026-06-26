#include <bits/stdc++.h>

using namespace std;


#define ll long long
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    ll n,c;cin>>n>>c;

    vector<ll> nums(n);

    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }

    sort(nums.begin(),nums.end());

    int ans = 0;

    int cnt = 0;
    
    for(int i = 0;i<n;i++){
        if(cnt + nums[i] <= c){
            cnt += nums[i];
            ans++;
            // cout << cnt << "\n";
        }
    }

    cout << ans << "\n";


    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//  int n; long long C; cin >> n >> C;
//  vector<long long> a(n);
//  for (auto &v : a) cin >> v;
//  sort(a.begin(), a.end()); //
// smallest first
//  long long sum = 0; int cnt = 0;
//  for (long long x : a) {
//  if (sum + x <= C) { sum += x;
// cnt++; }
//  else break;
//  }
//  cout << cnt << "\n";
// }


// Lesson: to fit the most items, always take the
// smallest available next. Sorting + gree