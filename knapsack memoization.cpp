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


ll recursive(vector<v2> v, int index,ll weight,vector<vector<ll>>& memoization){
    if(weight == 0 || index == v.size()) return 0;
    if(weight<v[index][0]){
        if(index == v.size()-1) return 0;
        return (memoization[index+1][weight]>=0?memoization[index+1][weight]:recursive(v,index+1,weight,memoization));
    }
    else{
        if(index == v.size()-1) return v[index][1];
        ll mx = 0;
        mx = (memoization[index+1][weight-v[index][0]]>=0?
            v[index][1]+memoization[index+1][weight-v[index][0]]:
            v[index][1]+recursive(v,index+1,weight-v[index][0],memoization));
        mx = max(mx,
            (memoization[index+1][weight]>=0?
            memoization[index+1][weight]:
            recursive(v,index+1,weight,memoization))
        );
        memoization[index][weight] = mx;
        return mx;
    }
}

void solve(){
    int n,w; cin>>n>>w;
    vector<v2> v(n);
    forn(i,n) cin>>v[i][0]>>v[i][1];
    vector<vector<ll>> memoization(n,vector<ll> (w+1,-1));
    cout<<recursive(v,0,w, memoization);


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
