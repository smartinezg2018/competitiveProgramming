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

string to_bit(ll n){
    string s = "";
    while(n>0){
        if(n%2!=0) s.pb('1');
        else s.pb('0');
        n/=2;
    }
    reverse(all(s));
    return s;
}

void solve(){
    ll n;
    cin>>n;
    string x = to_bit(n);

    int z=0,o=0;
    forn(i,x.size()){
        if(x[i]=='1') o++;
        else z++;
    }

    if(o==x.size() || o == 1){
        cout<<-1<<el;
        return;
    }

    string y = x;
    reverse(all(y));
    y.pop_back();
    
    forn(i,y.size()){
        if(y[i]=='0'){
            y[i]='1';
            break;
        }
    }
    
    ll acum = 0;
    forn(i,y.size()){
        if(y[i] == '1') acum+= (1<<i);
    }


    cout<<acum<<el;



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
