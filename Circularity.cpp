#include<bits/stdc++.h>
#include <climits> //LLONG_MAX
#define mod 1000000007
using namespace std;
using ll = long long;
int INT_max = numeric_limits<int>::max();
priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
int inf  = 1e9;
 
 
void solve(){
	ll n;
	cin>>n;
	vector<ll> v(n*2);
	for(int i = 0; i <n;i++){
		cin>>v[i];
		v[i+n] = v[i]; 
	}
	unordered_map<ll,ll> m;
	
	ll count = n;
	
	for(int i = 0; i<n*2;i++){
		count+=m[i+v[i]]*2;
		if(i<n)
			m[i+v[i]]++;
		
	}
		
	
	cout<<count<<endl;
			
			
	
	
	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}