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
  
void solve(){
    ll n,m; cin>>n>>m;
    vector<vector<array<ll,2>>> mp(n+1);
    forn(i,m){
        ll a,b,c; cin>>a>>b>>c;
        mp[a].pb({c,b});
    }
 
    vector<ll> distances(n+1,1e18);
    priority_queue<array<ll,2>,vector<array<ll,2>>,greater<array<ll,2>>> pq;
    distances[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        ll dis = pq.top()[0];
        ll node = pq.top()[1];
        pq.pop();
        if(dis>distances[node]) continue;
        for(array<ll,2> neig:mp[node]){
            if(dis+neig[0]>=distances[neig[1]]) continue;
            pq.push({dis+neig[0],neig[1]});
            distances[neig[1]] = dis+neig[0];
        }
    }
    forn(i,n){
        cout<<distances[i+1]<<" ";
    }
    cout<<el;
    
 
 
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