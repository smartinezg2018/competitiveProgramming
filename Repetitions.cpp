#include<bits/stdc++.h>
#include <climits> //LLONG_MAX
#define mod 1000000007
using namespace std;
using ll = long long;
int INT_max = numeric_limits<int>::max();
priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
int inf  = 1e9;
 
void solve(){
	string s; cin>>s;
	ll count =1;
	ll mx = 0 ;
	for(int i = 0; i <s.size()-1;i++){
		if(s[i]!=s[i+1]){
			mx =max(count,mx);
			count =1;		
		}
		else count++;
	}
	cout<<max(mx,count)<<endl;

	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}