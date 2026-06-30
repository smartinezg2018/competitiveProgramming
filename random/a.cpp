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

ll func(vector<vector<ll>> &v){
    ll ans;
    ll b1 = 0,b2 = 0,b3  = 0;
    
    vector<ll> mn(3);
    mn[0] = v[0][0];
    mn[1] = v[1][0]; 
    mn[2] = v[2][0]; 

    sort(all(mn));

    for(ll i: v[0]) b1 += i;
    for(ll i: v[1]) b2 += i;
    for(ll i: v[2]) b3 += i;

    ans = max(b1 + b2 + b3 - 2*mn[0] - 2*mn[1], b1 + b2 + b3 - 2*min({b1, b3, b2}));
    return ans;

}

void solve(){
    ll a,b,c; cin>>a>>b>>c;

    vector<vector<ll>> v(3);

    v[0].assign(a,0);
    v[1].assign(b,0);
    v[2].assign(c,0);


    forn(i,a) cin>>v[0][i];
    forn(i,b) cin>>v[1][i];
    forn(i,c) cin>>v[2][i];

    sort(all(v[0]));
    sort(all(v[1]));
    sort(all(v[2]));


    cout<<func(v)<<el;




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
