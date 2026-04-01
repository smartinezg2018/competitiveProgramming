
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
 
 
void print(vll &m,ll base){
    vll ans;
    ans.pb(base);
    while(base!=1){
        ans.pb(m[base]);
        base =  m[base];
    }
 
    ll n = sz(ans);
    cout<<n<<el;
    forn(i,n){
        cout<<ans[n-1-i]<<" ";
    }
    cout<<el;
 
}
 
void solve(){
    ll n,queries; cin>>n>>queries;
    map<ll,vector<ll>> mp;
    forn(i,queries){
        ll o,d; cin>>o>>d;
        mp[o].pb(d);
        mp[d].pb(o);
    }
    vector<bool> visited(n+1,false);
 

    queue<ll> q;
    q.push(1); 
    vector<ll> route(n+1,-1);

    ll count = 0;
 
    while(!q.empty()){
        count++;
        ll k = q.size();
        forn(j,k){
            ll v = q.front();
            q.pop();
            if(visited[v]) continue;
            
            for(ll neigh:mp[v]){
                if(visited[neigh]) 
                    continue;
                if(route[neigh] == -1)
                    route[neigh] = v;
                if(neigh == n){
                    print(route,n);
                    return;
                }
                q.push(neigh);
            }
            visited[v] = true;
            
        }
 
    }
 
    cout<<"IMPOSSIBLE"<<el;
    
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