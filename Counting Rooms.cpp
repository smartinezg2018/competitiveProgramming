#include<bits/stdc++.h>
#include <climits> //LLONG_MAX
#define mod 1000000007
using namespace std;
using ll = long long;
int INT_max = numeric_limits<int>::max();
priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
int inf  = 1e9;

// array[]
 
void solve(){
	int y,x; cin>>y>>x;
	vector<vector<char>> v(y,vector<char> (x));
	vector<vector<bool>> visited(y,vector<bool> (x,false));
	for(int  i = 0; i <y;i++)
		for(int j = 0; j <x; j++)
			cin>>v[i][j];
	
	for(int  i = 0; i <y;i++){
		for(int j = 0; j <x; j++){
			if(visited[i][j] ||  v[i][j] == '#') continue;
			// dfs
		}
		
	}
	

	

	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}