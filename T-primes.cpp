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
    ll n,limit = 1e6;
    cin>>n;
    vector<ll> v(n);
    for(ll i = 0; i < n;i++)
        cin>>v[i];

    
    vector<bool> primes(limit+1,true);
    primes[0] = false;
    primes[1] = false;
    
    for (ll i = 2; i <= limit; i++){
        if(!primes[i])
            continue;
        for(ll j = i*i; j <= limit;j+=i){
            primes[j] = false;
        }
    }

    set<ll> s;

    for(ll i = 0; i < limit+1;i++){
        if(primes[i]) s.insert(i*i);
    }

    forn(i,n){
        if(s.find(v[i])==s.end()) 
            cout<<"NO"<<el;
        else 
            cout<<"YES"<<el;
    }



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
    