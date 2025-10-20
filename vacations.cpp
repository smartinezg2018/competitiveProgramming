#include<bits/stdc++.h>
#include <climits> //LLONG_MAX
#define mod 1000000007
using namespace std;
using ll = long long;
int INT_max = numeric_limits<int>::max();
priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
int inf  = 1e9;
 
 
void solve(){
	int n; cin>>n;
	vector<vector<int>> v(n,vector<int>(3)),ans(n,vector<int>(3));
	
	for(int i = 0; i <n;i++){
		cin>>v[i][0];
		cin>>v[i][1];
		cin>>v[i][2];
	}
	
	ans[0][0] = v[0][0];
	ans[0][1] = v[0][1];
	ans[0][2] = v[0][2];
	
	for(int i = 1; i <n;i++){
		ans[i][0] = max(ans[i-1][1],ans[i-1][2]) + v[i][0];
		ans[i][1] = max(ans[i-1][0],ans[i-1][2]) + v[i][1];
		ans[i][2] = max(ans[i-1][0],ans[i-1][1]) + v[i][2];
	}
	cout<<max(ans[n-1][0],max(ans[n-1][2],ans[n-1][1]));

	
	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}