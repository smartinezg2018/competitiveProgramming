#include<bits/stdc++.h>
#include <climits> //LLONG_MAX
#define mod 1000000007
using namespace std;
using ll = long long;
int INT_max = numeric_limits<int>::max();
priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
int inf  = 1e9;
 
 
void solve(){
	int y,x,k; cin>>y>>x>>k;
	vector<vector<char>> v(y,vector<char>(x));
	vector<vector<char>> ans(y*k,vector<char>(x*k));
	for(int i = 0; i < y;i++)
	for(int j= 0 ; j<x;j++) {cin>>v[i][j];}
	
	
	
	for(int i = 0; i < y;i++){
		for(int j= 0 ; j<x;j++){
			char c = v[i][j];
			
			for(int tempy = k*i;tempy< (k*i)+k;tempy++){
				for(int tempx = k*j;tempx<(k*j)+k;tempx++){
					ans[tempy][tempx] = c;
				}
			}
			
			
		}
	}
	
	for(int i = 0; i < y*k;i++){
		for(int j= 0 ; j<x*k;j++) {
			cout<<ans[i][j];	
		}
		cout<<endl;
	}
	
	
	
	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}