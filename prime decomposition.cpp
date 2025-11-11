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
	map<int,int> m;
	
	
	while(n%2==0 && n >0){
		n/=2;
		m[2]++;
	}
	
	cout<<"factor: "<<2<<", "<<m[2]<<endl;
	
	for(int i = 3;i<=n;i+=2){
		while(n%i==0 && n>0){
			n/=i;
			m[i]++;
		}
		cout<<"factor: "<<i<<", "<<m[i]<<endl;
	}
	

	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}