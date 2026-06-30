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
#define print(x) cout<<" " << x<<el

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
typedef array<ll,2> v2;


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;
const ll mod = 1e9+7;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

ostream& operator<<(ostream& os, const ii& pa) { // DEBUGGING
return os << "("<< pa.fi << ", " << pa.se << ")";
}

map<pair<int, int>, int> ind;
vector<vector<int>> adj;
vector<int> dp;

void rec(int parpar, int par){
    for(int son : adj[par]){
        if(son == parpar) continue;
        if(ind[{par,son}]<ind[{par,parpar}]) dp[son] = dp[par]+1;
        else dp[son] = dp[par];
        // cout<<son<<el;
        rec(par,son);
    }

}

void solve() {
    ll n; cin>>n;
    dp.assign(n+1,0);
    adj.assign(n+1,vector<int>());
    ind.clear();

    for(int i = 0; i < n-1;i++){
        int a,b;
        cin>>a>>b;

        adj[a].pb(b);
        adj[b].pb(a);

        ind[{a,b}] = i;
        ind[{b,a}] = i;
    }

    ind[{1,0}] = n;
    ind[{0,1}] = n;

    rec(0,1);
    cout<<*max_element(all(dp))<<el;


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
