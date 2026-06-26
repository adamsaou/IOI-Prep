#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);


    int n,x; cin>>n>>x;
    vector<int> nums(n);

    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    for(int i = 1;i<n;i++){
        if(nums[i - 1] + nums[i] == x){
            cout << "YES" << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";

    
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//  int n; long long x; cin >> n >> x;
//  vector<long long> a(n);
//  for (auto &v : a) cin >> v;
//  bool found = false;
//  for (int i = 0; i < n && !found; i++)
//  for (int j = i + 1; j < n; j++)
//  if (a[i] + a[j] == x) { found =
// true; break; }
//  cout << (found ? "YES" : "NO") << "\n";
// }



// Lesson: n ≤ 2000 means n² ≈ 4×10⁶ checks —
// totally fine. When the input is small, brute force every
// pair. (A faster O(n) set-based way exists; learn it
// once this clicks.)
