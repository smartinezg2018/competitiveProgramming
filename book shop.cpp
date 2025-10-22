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
	vector<int> prices(n),pages(n);
	for(int i = 0; i<n;i++) cin>>prices[i];
	for(int i = 0; i<n;i++) cin>>pages[i];
	
	vector<vector<int>> dp(n+1,vector<int>(x+1	,0));
	
	for(int i = 1;i<=n;i++){
		for(int j = 0; j<=x;j++){
			int page = pages[i-1];
			int price = prices[i-1];
			
			int pick = (j>=price ? dp[i-1][j-price]+page : 0);
			int nopick = dp[i-1][j];
			
			dp[i][j] = max(nopick,pick);
			
		}
	}

	cout<<dp[n][x];
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}