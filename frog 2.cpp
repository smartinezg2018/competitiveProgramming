#include<bits/stdc++.h>
#include <climits> //LLONG_MAX
#define mod 1000000007
using namespace std;
using ll = long long;
int INT_max = numeric_limits<int>::max();
priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
int inf  = 1e9;
 
 
void solve(){
	int n,k; cin>>n>>k;
	vector<int> v(n),ans(n);
	for(int i = 0; i <n;i++) cin>>v[i];
	
	ans[0] = 0;
	
	for(int i = 1; i <n;i++){
		int mn = inf;
		for(int j = i-1;j>= max(i-k,0);j--){
			mn = min(mn,ans[j]+abs(v[i]-v[j]));
		}
		ans[i] = mn;
		
	}
	cout<<ans[n-1]<<endl;
	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}