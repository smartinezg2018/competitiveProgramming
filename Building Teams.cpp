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
    ll n,queries; cin>>n>>queries;
    map<ll,vector<ll>> mp;
    forn(i,queries){
        ll o,d; cin>>o>>d;
        mp[o].pb(d);
        mp[d].pb(o);
    }
    vector<ll> team(n+1,-1);

    queue<ll> total;
    forn(i,n)
        total.push(i+1);

    while(!total.empty()){

        while(team[total.front()] != -1) total.pop();

        queue<ll> q;
        q.push(total.front());
        ll level = false;
        while(!q.empty()){
            ll k = q.size();
            forn(i,k){
                if(team[q.front()] != -1){
                    if(team[q.front()] != level){
                        cout<<"IMPOSSIBLE"<<el;
                        return;
                    }
                    else{
                        q.pop();
                        continue;
                    }
                }

                team[q.front()] = level;
                
                for(ll neigh:mp[q.front()]){
                    q.push(neigh);
                }
                    
                
                q.pop();
            }
            level ^= 1;
        }
        
    }
    forn(i,n){
        cout<<team[i+1]+1<<" ";
    }
    
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
