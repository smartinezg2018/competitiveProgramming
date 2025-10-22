#include<bits/stdc++.h>
#include <climits> //LLONG_MAX
#define mod 1000000007
using namespace std;
using ll = long long;
int INT_max = numeric_limits<int>::max();
priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
int inf  = 1e9;
 
 
void solve(){
	int n,x; cin>>n>>x;
	vector<int> v(n);
	for(int i = 0; i<n;i++) cin>>v[i];
	
	vector<int> dp(x+1,0);
	dp[0] =1;
	
	for(int i = 1; i<=x;i++){
		for(int j = 0;j<n;j++){
			int value = v[j];
			dp[i]+= (i>=value ? dp[i-value]:0);
		}
	}
	cout<<dp[x]<<endl;
	
	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}