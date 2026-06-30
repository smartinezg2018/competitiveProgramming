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
	int n,q;
	cin>>n>>q;
	vi v(n);
	forn(i,n)
		cin>>v[i];
	vector<v2> que(q);
	forn(i,q){
		cin>>que[i][0]>>que[i][1];
		que[i][0]--;
		que[i][1]--;
	}
	
	vi pre1 = v;
	partial_sum(all(pre1),pre1.begin());
	
	vi pre2(n);
	for1(i,n-1){
		if(v[i]==v[i-1]) 
			pre2[i] = 1;
	}

	partial_sum(all(pre2),pre2.begin());
	
	for(auto [l, r]: que){
		int ones = pre1[r]-(l-1>=0? pre1[l-1]:0);
		if(ones%3!=0 || (r-l+1)%3!=0){
			cout<<-1<<endl;
			continue;
		}
		bool repeat = (pre2[r]-(l-1>=0? pre2[l]:0))>0;
		cout<<((r-l+1)/3)+(!repeat)<<endl;
		
	}
	
	
		
		

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    ll t; cin>>t;
    while(t--)
    solve();
    return 0;
}
