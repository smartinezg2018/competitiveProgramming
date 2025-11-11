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
	vector<ll> v(n);
	for(ll & num:v) cin>>num;
	
	ll acum = 0;
	for(int i = 1 ;i < n; i++){
		if(v[i]<v[i-1]){
			acum+=v[i-1]-v[i];
			// cout<<v[i-1]-v[i]<<endl;
			v[i] = v[i-1];
		}
	}
	cout<<acum<<endl;

	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}