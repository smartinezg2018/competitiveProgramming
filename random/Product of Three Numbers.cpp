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
    ll n,temp;
    cin>>n;
    temp = n;

    ll ans[3] = {1,1,1};
    for(int i = 2;i*i < n;i++){
        if(n%i==0){
            ans[0] = i;
            break;
        }
    }

    n/=ans[0];
    for(int i = ans[0]+1;i*i < n;i++){
        if(n%i==0){
            ans[1] = i;
            break;
        }
    }

    ans[2] = temp/(ans[0]*ans[1]);

    bool mask = ans[0]==1 || ans[1]==1 ||ans[2]==1 || ans[0]==ans[1]||ans[1]==ans[2]||ans[0]==ans[2];

    if(mask){
        cout<<"NO"<<el;
        return;

    }
    cout<<"YES"<<el;

    forn(i,3)
        cout<<ans[i]<<" ";
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
    