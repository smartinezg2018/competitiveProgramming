#include<bits/stdc++.h>
#include <climits> //LLONG_MAX
#define mod 1000000007
using namespace std;
using ll = long long;
int INT_max = numeric_limits<int>::max();
priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
int inf  = 1e9;
 
// void acum(vector<int>& v,vector<int>& prev,int index){
// 	vector<int>& prox
// 	prev[min(v[0],m)]++;
// 	for(int i =0; i<=m;i++){
// 		if(prev[i]>0){
// 			for(int j =max(1,i-1);j<=min(m,i+1);j++){
// 				prox[j]+=prev[i];
// 			}
// 		}
// 	}
// 	prev = prox;
// }

void solve(){
	int n,m; cin>>n>>m;
	vector<int> v(n);
	for(int i =0; i<n;i++) cin>>v[i];

	vector<array<int,3>> ans;
	int count,j;
	for(int i =0;i<n;i++){
		if(v[i+1]==0){
			count = 0;
			j=i+1;
			while(v[j]==0 && j<n){
				count++;
				j++;
			}
			ans.push_back({i,count,j});
			i=j-1;
		}
	}



	


	
	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}