#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

 
int t, n;
 
long long ans;
 
ordered_set st;
 
void solve(){
    cin >> n;
    vector<pair<int, int>> arr(n);
    
    for(int i = 0; i <n ; i++){
        cin>>arr[i].first;
        cin>>arr[i].second;
    }

    sort(arr.begin(),arr.end());

    ordered_set s;

    long long acum = 0;
    for(int i = 0; i <n; i++){
        acum += s.size() - s.order_of_key(arr[i].second);
        s.insert(arr[i].second);

    }

    cout << acum << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
 
    cin >> t;
 
    while(t--){
        solve();
    }
}