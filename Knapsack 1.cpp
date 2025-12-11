#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;
typedef array<int,2> v2;


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

ostream& operator<<(ostream& os, const ii& pa) { // DEBUGGING
return os << "("<< pa.fi << ", " << pa.se << ")";
}

void solve(){
	ll n,c; cin>>n>>c;
	vll w(n);
	vll v(n);
	forn(i,n){	
		cin>>w[i];
		cin>>v[i]; 
	}
	vector<vll> ans(n,vll(c+1));
	
	forn(i,n){
		ll book = w[i];
		for(ll j = book;j<=c;j++){
			ans[i][j] = v[i];
		}
	}
	

	for1(i,n-1){
		ll book = w[i];
		for1(j,c){
			ans[i][j] = max(ans[i-1][j],(j-book>0? ans[i-1][j-book]:0)+ans[i][j]);
			
		}
	}
	// forn(i,n){
		// forn(j,c+1)
			// cout<<ans[i][j]<<"  ";
		// cout<<endl;
	// }
	cout<<ans[n-1][c]<<endl;
	

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    // ll t; cin>>t;
    // while(t--)
    solve();
    return 0;
}
