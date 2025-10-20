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
	vector<int> v(n),ans(n);
	for(int i = 0; i <n;i++) cin>>v[i];
	
	ans[0] = 0;
	ans[1] = abs(v[0]-v[1]);
	
	
	for(int i = 2; i < n;i++){
		ans[i] = min(abs(v[i]-v[i-1])+ans[i-1],abs(v[i]-v[i-2])+ans[i-2]);
	}
	cout<<ans[n-1]<<endl;
	
	
	
	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}