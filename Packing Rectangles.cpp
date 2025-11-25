#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool func(ll side, ll y, ll x, ll n) {
    return ((side / y)*(side / x)>=n); 
}

void solve() {
    ll y, x, n;
    cin >> y >> x >> n;

    ll l = 0, r = 1; 
    while(!func(r, y, x, n))
    	r = r * 2;
    


    while (l < r) {
        ll mid = l + (r - l) / 2;

        if (func(mid, y, x, n)) {
            r = mid;
        } else {
            l = mid+1;
        }
    }

    cout << l << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) 
    solve();
    return 0;
}
