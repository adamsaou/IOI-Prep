#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin>>n;

    vector<int> nums(n);

    int ans = 0;
    for(int i = 0; i<n;i++){

        cin>>nums[i];
        if (nums[i] % 2 == 0) ans++;
    } 

    cout << ans << "\n";
    return 0;
}

//original solution:


// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//  int n; cin >> n, cnt = 0;
//  for (int i = 0; i < n; i++) {
//  int x; cin >> x;
//  if (x % 2 == 0) cnt++;
//  }
//  cout << cnt << "\n";
// }
