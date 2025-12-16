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
    ll n;
    cin>>n;
    vector<ll> e,o;
    ll temp;
    forn(i,n){
        cin>>temp;
        if(temp%2==0)
            e.push_back(temp);
        else
            o.push_back(temp);
    }

    sort(all(e));
    sort(all(o));
    reverse(all(e));
    reverse(all(o));

    
    if(o.size() == 0){
        forn(i,n)
            cout<<0<<" ";
        cout<<endl;
        return;
    }
    if(e.size() == 0){
        for(int i = 1; i<=n;i++){
            if(i%2==0){
                cout<<0<<" ";
            }
            else{
                cout<<o[0]<<" ";
            }
        }
        cout<<endl;
        return;

    }

    partial_sum(all(e),e.begin());
    
    ll l, acum;
    for1(k,n){
        l = 0;
        acum = 0;
        while(k-l>e.size()+1)
            l+=2;

        if(l >= o.size()){
            cout<<0<<" ";
            continue;
        }
         
        acum += o[0];
        if(k-l-2<e.size() && k-l-2>=0)
            acum+=e[k-l-2];
        cout<<acum<<" ";
    }
    cout<<endl;

    
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
