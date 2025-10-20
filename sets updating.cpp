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
	vector<int> v(n);
	for(int i = 0; i <n;i++) cin>>v[i];
	
	set<int> m1 ,m2;
	m1.insert(v[0]);
	
	int count =1;
	for(int i = 1; i <n;i++){
		
		m1.erase(v[i]);
		m2.insert(v[i]);
		
		if(m1.size() == 0){
			count++;
			set<int> temp = m1;
			m1 = m2;
			m2 = temp;
		}
		// cout<<count<<endl;
	}
	cout<<count<<endl;
	
	
	
	
}
 
int main(){
	int t; cin>>t;
	while(t--) 
	solve();
	return 0;
}