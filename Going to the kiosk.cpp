#include<bits/stdc++.h>
#include <climits> //LLONG_MAX
#define mod 1000000007
using namespace std;
using ll = long long;
int INT_max = numeric_limits<int>::max();
priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
int inf  = 1e9;
 
 
void solve(){
	int a,b,c;
	cin>>a>>b>>c;
	
	if((b-a)%c==0) cout<<"S"<<endl;
	else cout<<"N"<<endl;
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}