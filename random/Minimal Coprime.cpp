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

void solve(){
    ll n,k; cin>>n>>k;
    string s;
    cin>>s;

    vll z;
    ll ans = 0;


    for(int i = 0;i<n;i++){
        if(s[i] == '1') continue;
        ll j = i;
        while(s[j] == '0')j++;
        if(j==i) continue;
        // d(j-i);
        z.pb(j-i);
        i = j;
    }
    if(z.empty()){
        cout<<0<<el;
        return;
    }
    if(z[0] == n){
        cout<<(n+k)/(k+1)<<el;
        return;
    }

    if(s[0] == '0') ans += z[0]/(k+1);
    if(s[n-1] == '0') ans += z[sz(z)-1]/(k+1);
    
    for(int i = (s[0] == '0'? 1:0);i<(s[n-1] == '0'?sz(z)-1:sz(z));i++){
        ans+= z[i]/(k*2+1);
        // d(z[i]);
    }
    cout<<ans<<el;




    





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
