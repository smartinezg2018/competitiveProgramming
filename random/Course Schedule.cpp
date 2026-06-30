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

    ll n,ques; cin>>n>>ques;
    vector<bool> leaves(n+1,true),visited(n+1,false);
    map<ll,vector<ll>> mp;
    forn(i,ques){
        ll a,b; cin>>a>>b;
        leaves[a] = false;
        mp[b].pb(a);
    }

    vll ans;
    queue<ll> q;

    for(int i = 1;i<=n;i++)
        if(leaves[i]) q.push(i);

    while(!q.empty()){
        ll a = q.front();
        q.pop();
        visited[a] = true;
        ans.pb(a);
        for(ll neigh : mp[a]){
            if(visited[neigh]) continue;
            q.push(neigh);
            visited[neigh] = true;
        }
    }
    reverse(all(ans));
    

    if(sz(ans)<n){
        cout<<"IMPOSSIBLE"<<el;
        return;
    }

    forn(i,sz(ans)) cout<<ans[i]<<" ";
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
