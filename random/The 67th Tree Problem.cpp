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
    ll e,o,n;
    cin>>e>>o;
    n = e+o;

    vll v(n);
    forn(i,n-1){
        v[i+1] = i;
    }

    if(n%2!=0){
        if(o < (n+1)/2){
            cout<<"NO"<<el;
            return;
        }

        for(int i = 0; i < ((n/2) - e)*2; ++i){
            v[n-i-1] = 0;
        }
    }

    else{
        if(e > n/2 || e < 1){
            cout<<"NO"<<el;
            return;
        }

        for(int i = 0;  i< ((n/2) - e)*2; i++){
            v[n-i-1] = 0;
        }

    }
    cout<<"YES"<<el;

    forn(i,n-1){
        cout<<v[i+1]+1<<" "<<i+2<<el;
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