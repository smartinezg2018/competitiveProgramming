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
    ll n;
    cin>>n;
    vll v(n), premn(n),posmn(n),premx(n),posmx(n);
    map<int,array<ll,2>> ind;

    forn(i,n) {
        cin>>v[i];
        if(ind[v[i]][0]!=0){
            ind[v[i]][1] = i+1;
            continue;
        }
        ind[v[i]][0] = i+1;
    }


    if(n<=2){
        cout<<"NO"<<el;
        return;

    }
    
    premn[0] = v[0];
    posmn[n-1] = v[n-1];
    premx[0] = v[n-1];
    posmx[n-1] = v[0];

    for(int  i = 1;i<n;i++) {
        premn[i] = min(v[i],premn[i-1]);
        posmn[n-1-i] = min(v[n-1-i],posmn[n-i]);
        premx[i] = max(v[i],premx[i-1]);
        posmx[n-1-i] = max(v[n-1-i],posmx[n-i]);
    }
    
    for(int i = 1; i < n-1;i++){
        if(posmn[i] == v[i] || premn[i] == v[i]) continue;
        cout<<3<<el;
        cout<<ind[premn[i]][0]<<" "<<i+1<<" "<<(ind[posmn[i]][1] == 0? ind[posmn[i]][0]:ind[posmn[i]][1])<<el;
        return;

    }
    for(int i = 1; i < n-1;i++){
        if(posmx[i] == v[i] || premx[i] == v[i]) continue;
        cout<<3<<el;
        cout<<ind[premx[i]][0]<<" "<<i+1<<" "<<(ind[posmx[i]][1] == 0? ind[posmx[i]][0]:ind[posmx[i]][1])<<el;
        return;

    }
    cout<<0<<el;
    
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