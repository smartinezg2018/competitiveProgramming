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

ostream& operator<<(ostream& os, const ii& pa) {
return os << "("<< pa.fi << ", " << pa.se << ")";
}

ll gauss(ll n){
	return n*(n+1)/2;
}
void solve(){
    string v; cin>>v;
    int n = sz(v);

    ll pre = 0, suf = 0;

    ll ans = inf;

    ll four = 0;
    forn(i,n)
        if(v[i] =='4') four++;

    for(int i = 0;i<n;i++){
        if(v[i] == '1' || v[i] == '3'){
            pre++;
        }
    }
    for(int i = 0;i<n;i++){
        ans = min(ans,pre+suf);
        if(v[n-i-1] == '2'){
            suf++;
        }
        else if(v[n-i-1] == '1' || v[n-i-1] == '3'){
            pre--;
        }
        
    }
    ans = min(ans,pre+suf);

    cout<<four+ans<<el;

     

    
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
