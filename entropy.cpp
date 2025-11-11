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
	vector<float> v (n);
	for(float& input:v) 
		cin>>input;
	
	float total = 0;
	for(float num:v) 
		total+=num;
	
	total = 10;
	float ans = 0;
	for(int i = 0; i <v.size();i++){
		ans+=(v[i]/total)*log2((v[i]/total));
	}
	ans*=-1;
	cout<<ans;

	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}