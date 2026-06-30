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
	if(n<=3 && n>1){
		cout<<"NO SOLUTION"<<endl;
		return;
	}
	
	for(ll i = 2; i<=n;i+=2){
		cout<<i<<" ";
	}
	for(ll i = 1; i<=n;i+=2){
		cout<<i<<" ";
	}

	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}