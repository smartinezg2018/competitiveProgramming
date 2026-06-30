#include<bits/stdc++.h>
#include <climits> //LLONG_MAX
#define mod 1000000007
using namespace std;
using ll = long long;
int INT_max = numeric_limits<int>::max();
priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
int inf  = 1e9;
 
 
void solve(){
	ll n; cin>>n;
	map<ll,ll> m;
	ll mx =0;
	ll mn = LLONG_MAX;
	for(int i = 0; i <n;i++) {
		ll a,b;
		cin>>a>>b;
		m[a]++;
		m[b]--;
		mx = max(mx,b);
		mn = min(mn,a);
	}
	
	ll ans = 0;
	ll curr = 0;
	for(pair<ll,ll> p : m){
		curr += p.second;
		ans = max(ans,curr);
	}
	cout<<ans<<endl;
	
	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}