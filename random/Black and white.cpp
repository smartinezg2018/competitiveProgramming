#include<bits/stdc++.h>
#include <climits> //LLONG_MAX
#define mod 1000000007
using namespace std;
using ll = long long;
int INT_max = numeric_limits<int>::max();
priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
int inf  = 1e9;
 
 
void solve(){
	int n;
	cin>>n;
	vector<vector<char>> v(n,vector<char>(n));
	for(int y = 0; y<n;y++){
		for(int x = 0; x<n;x++){
			cin>>v[y][x];
			// cout<<v[y][x]<<endl;
		}
	}
	int count = 0;
	for(vector<char> level:v){
		for(int i = 0; i <n-1;i++){
			if(level[i]=='N'&&level[i+1]=='N'){
				count++;
				i++;
			}
		}
	}
	cout<<count;
	
	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}