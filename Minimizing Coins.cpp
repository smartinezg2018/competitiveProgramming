#include<bits/stdc++.h>
#include <climits> //LLONG_MAX
#define mod 1000000007
using namespace std;
using ll = long long;
int INT_max = numeric_limits<int>::max();
priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
int inf  = 1e9;
 
void solve(){
	ll n,x; cin>>n>>x;
	vector<ll> v(n),dp(x+1,inf);
	
	for(ll i = 0; i <n;i++) cin>>v[i];
	
	dp[0] = 0;
	
	for(ll i = 1;i<=x;i++){
		for(ll coin:v){
			if(coin>i) continue;
			dp[i] = min(dp[i],dp[i-coin]+1);
		}
	}
	if(dp[x]!=inf)
		cout<<dp[x];
	else
		cout<<-1;
		

	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}