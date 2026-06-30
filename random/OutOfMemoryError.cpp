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
const ll mod = 1e9+7;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

ostream& operator<<(ostream& os, const ii& pa) { // DEBUGGING
return os << "("<< pa.fi << ", " << pa.se << ")";
}

void solve(){
    unsigned long long n,m,h; cin>>n>>m>>h;
    vector<ll> v(n); forn(i,n) cin>>v[i];
    vector<array<ll,2>> opt(m); forn(i,m)cin>>opt[i][0]>>opt[i][1];

    vll temp = v, inspect(n,-1);
    ll last = 0;
    int i = 0;

    for(auto [b,c] : opt){
        if(inspect[b-1]<last) temp[b-1] = v[b-1];
        temp[b-1]+=c;
        inspect[b-1] = i;
        if(temp[b-1]>h){
            last = i;
            temp[b-1] = v[b-1];
        }
        i++;
    }
    for(int i = 0; i <n;i++){
        if(inspect[i]<last){
            cout<<v[i]<<" ";
        }
        else{
            cout<<temp[i]<<" ";
        }
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
