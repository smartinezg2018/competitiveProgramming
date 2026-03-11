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

void solve(){
    int n; cin>>n;

    vector<deque<ll>> v(n);
    ll input ,m;
    for(int i = 0; i <n;i++){
        cin>>m;
        while(m--){
            cin>>input;
            v[i].push_front(input);
        }
    }


    set<ll> s;
    
    forn(i,n){
        sort(all(v));
        if(v[0].front()==inf+1000) break;
        while(!v[0].empty()){
            if(s.find(v[0].front())!=s.end()) {v[0].pop_front();continue;}
            cout<<v[0].front()<<" ";
            s.insert(v[0].front());
            v[0].pop_front();
        }

        v[0].push_front(inf+1000);

        forn(j,n){
            while(s.find(v[j].front())!=s.end()){
                v[j].pop_front();
            }
            if(v[j].empty()) v[j].pb(inf+1000);
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
