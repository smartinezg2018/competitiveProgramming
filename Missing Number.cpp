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
	ll sum = 0;
	for(int i =0; i<n-1;i++){
		ll temp; 
		cin>>temp;
		sum+=temp;
	} 
	cout<<(n*(n+1)/2)-sum;
	
	

	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}