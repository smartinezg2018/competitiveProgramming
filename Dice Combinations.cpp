#include<bits/stdc++.h>
#include <climits> //LLONG_MAX
#define mod 1000000007
using namespace std;
using ll = long long;
int INT_max = numeric_limits<int>::max();
priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
int inf  = 1e9;
 
void solve(){
	ll n;cin>>n;
	vector<ll> v(n+1,0);
	v[0] = 1;
	
	for(ll i = 1; i <=n;i++){
		for(ll j = 1; j <=i;j++){
			v[i] = (v[i] + v[i-j])%mod;
		}
		
	}
	cout<<v[n]%mod;
	


	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}