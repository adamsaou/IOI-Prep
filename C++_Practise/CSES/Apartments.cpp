#include <bits/stdc++.h>

using namespace std;


#define ll long long
int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    ll n,m,k; cin>>n>>m>>k;
    //n -> applicants
    //m -> number of appartements
    //k -> maximum allowed difference

    vector <int> desired_size(n);
    vector <int> size(m);
    
    for(int i =0; i<n;i++){
        cin>>desired_size[i];
    }

    for(int i =0; i<m;i++){
        cin>>size[i];
    }


    sort(desired_size.begin(), desired_size.end());
    sort(size.begin(), size.end());

    ll ans = 0;
    int i = 0;
    int j = 0;
    while(i < n && j < m){
        if(abs(desired_size[i] - size[j]) <= k){
            i++;
            j++;
            ans++;
        } else {
            if(desired_size[i] - size[j] > k){
                j++;
            } else {
                i++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}