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
	queue<char> q;
	q.push('T');
	q.push('A');
	q.push('P');
	for(char c:s){
		if(c==q.front())q.pop();
	}
	if(q.empty()) cout<<"S"<<endl;
	else cout<<"N"<<endl;
	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}