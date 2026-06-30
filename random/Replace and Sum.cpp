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
    ll n,q; cin>>n>>q;
    vector<int> a(n),b(n);
    forn(i,n) cin>>a[i];
    forn(i,n) cin>>b[i];

    vector<v2> qu(q);
    forn(i,q) {cin>>qu[i][0]>>qu[i][1];qu[i][1]--;qu[i][0]--;}

    a[n-1] = max(a[n-1],b[n-1]);

    for(int i = n-2;i>=0;i--){
        a[i] = max(max(a[i],b[i]),a[i+1]);
    }

    partial_sum(all(a),a.begin());

    forn(i,q){
        // d(qu[i][0]);
        cout<<a[qu[i][1]]-(qu[i][0] == 0? 0: a[qu[i][0]-1])<<" ";
    }
    cout<<el;




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
