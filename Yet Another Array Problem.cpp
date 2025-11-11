#include<bits/stdc++.h>
#include <climits> //LLONG_MAX
#define mod 1000000007
using namespace std;
using ll = long long;
int INT_max = numeric_limits<int>::max();
priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
int inf  = 1e9;
 
 

 
void solve(){
	vector<ll> p = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	ll n; cin>>n;
	vector<ll> v(n);
	for(ll& num :v)
		cin>>num;

	
	for(ll prime : p){
		for(ll num : v){
			if(num%prime){
				cout<<prime<<endl;
				return;
			}
			
		}
		
	}

	cout<<-1<<endl;

	
}
 
int main(){

	int t; cin>>t;
	while(t--) 
	solve();
	return 0;
}