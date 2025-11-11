#include<bits/stdc++.h>
#include <climits> //LLONG_MAX
#define mod 1000000007
using namespace std;
using ll = long long;
int INT_max = numeric_limits<int>::max();
priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
int inf  = 1e9;
 
void solve(){
	int n,m;
	vector<int> v(n);
	for(int i =0;i<n;i++) cin>>v[i];
	
	vector<array<int,3>> q;
	
	int l = 0,r =0;
	while(r<n){
		while(r==0) 
			r++;
		if(v[l] == 0)q.push_back({l,r-l,r});
		l=r;	
		
	}
	
	
	


	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}