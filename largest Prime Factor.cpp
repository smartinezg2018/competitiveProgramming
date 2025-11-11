#include<bits/stdc++.h>
#include <climits> //LLONG_MAX
#define mod 1000000007
using namespace std;
using ll = long long;
int INT_max = numeric_limits<int>::max();
priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
int inf  = 1e9;


int largestPrimeFactor(int n) {
    // code here
    int mx = 1;
    if(n%2==0)
        mx = 2;
        
    while(n%2==0 && n > 0)
        n/=2;
    
// Solo se guardan los números primos.
// Los números compuestos (como 4, 6, 8, 9, etc.) 
// no se vuelven a considerar, 
// porque sus factores ya fueron incluidos.

    for(int i = 3; i*i<n;i+=2){
        if(n%i==0)
            mx = i;
        while(n%i==0 && n>0){
            n/=i;
        }
        
    }
    if(n>2) return n;
    return mx;
    
}
 
void solve(){
	int n; cin>>n;
	cout<<largestPrimeFactor(5);
	
}
 
int main(){
	// int t; cin>>t;
	// while(t--) 
	solve();
	return 0;
}