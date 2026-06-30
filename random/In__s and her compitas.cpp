#include<bits/stdc++.h>
#include <climits> //LLONG_MAX
#define mod 1000000007
using namespace std;
using ll = long long;
int INT_max = numeric_limits<int>::max();
priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
int inf  = 1e9;
 
 
void solve(){
	int n,m,x,y;
	cin>>n>>m;
	vector<int> gold(n+1);
	vector<int> opt(n);
	while(m--){
		cin>>x>>y;
		int k = 0;
		for(int i = 0; i < n;i++) {
			cin>>opt[i];
			if(opt[i]==1)k++;
		}
		
		if((x/(k+1))>=y) {
			k++;
			gold[n]+= (x/k);
		}
		else gold[n]+= y;
		
		for(int i = 0; i < n;i++){
			if(opt[i] ==1)
				gold[i]+= x/k;
			else
				gold[i] += y;
		}
		
	}
	for(int i = 0; i < n;i++) {
		cout<<gold[i]<<" ";
	}
	cout<<gold[n]<<endl;
	
	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}