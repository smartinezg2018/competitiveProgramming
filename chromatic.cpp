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
	priority_queue<ll> b;
	priority_queue<ll> r;
	for(int i = 0; i<n;i++){
		ll a; cin>>a;
		b.push(a);
	}
	for(int i = 0; i<n;i++){
		ll a; cin>>a;
		r.push(-a);			
	}
	
	ll mn = LLONG_MAX;
	ll mx = 0;
	
	while(!b.empty()){
		// cout<<-r.top()+b.top()<<endl;
		mn = min(-r.top()+b.top(),mn);
		mx = max(-r.top()+b.top(),mx);
		b.pop();
		r.pop();
		
	}
	cout<<mx-mn<<endl;
	
	
	
	
	
	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}