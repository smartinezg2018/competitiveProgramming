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


void to_bit(vector<ll> &v, vector<vll> &pre){
    forn(j,sz(v)){
        forn(i,30){
            if(v[j]%2!=0)pre[i][j] = 1;
            else pre[i][j] = 0;
            v[j]/=2;
        }
    }

    forn(i,30){
        partial_sum(pre[i].begin(),pre[i].end(),pre[i].begin());
    }

}

ll binary(ll l, ll r,vector<vll> &pre){
    ll acum = 0;
     
    forn(i,30){
        if(r-l+1 == (pre[i][r] - (l==0? 0 :pre[i][l-1]))) acum+=(1<<i);
    }
    
    return acum;
}

void solve(){
    ll n; cin>>n;
    vll arr(n);
    forn(i,n) cin>>arr[i];
    vector<vll> pre(30,vll(n));
    to_bit(arr,pre);

    ll qs; cin>>qs;
    forn(i,qs){
        ll l,k; cin>>l>>k;
        l--;
        ll base = l;
        ll r = n-1;
        
        if(binary(base,base,pre)<k){
            cout<<-1<<' ';
            continue;
        }
        
        while(l<=r){
            ll mid = (l+r)/2;
            if(binary(base,mid,pre)>=k){
                l = mid + 1;
            }
            else{
                r = mid-1;
            }
        }
        cout<<r+1<<' ';
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
