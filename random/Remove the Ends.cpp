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
    ll n; cin>>n;
    vector<ll> v(n),b;
    forn(i,n) cin>>v[i];
    if(n==1){
        cout<<abs(v[0])<<el;
        return;
    }
    
    int j = 0;
    int i = 1;
    ll acum = v[0];
    while(i<n){
        if((acum<0 && v[i]>=0)||(acum>=0 && v[i]<0)){
            b.pb(acum);
            acum = 0;
        }
        acum += v[i];
        i++;
    }
    b.pb(acum);
    
    
    for(int i = (b[b.size()-1]< 0? b.size()-3:b.size()-4);i>=0;i-=2){
        // b[i] += b[i-2];
        b[i] += b[i+2]; 
    }
    for(int i = (b[0]>=0 ? 2:3);i<b.size();i+=2){
        // b[i] += b[i-2];
        b[i] += b[i-2]; 
    }
    // forn(i,b.size()){
    //     cout<<b[i]<<" ";
    // }
    // cout<<el;
    
    ll mx = 0;
    for(int i = (b[0]>=0? 0:1);i<b.size()-1;i+=2){
        mx = max(mx,abs(b[i])+abs(b[i+1]));
    }
    mx = max(mx,abs(b[b.size()-1]));
    mx = max(mx,abs(b[0]));


    cout<<mx<<el;



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
