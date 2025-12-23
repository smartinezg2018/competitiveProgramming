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
    int n,total = 0; 
    cin>>n;
    queue<int> z;
    vector<int> v(n),o;
    forn(i,n){
        cin>>v[i];
        total += v[i];
        if(v[i]>0)
            o.pb(i+1);
        else
            z.push(i+1);     
    } 

    if(total-(o.size()-1) < z.size() || v[0] == 0){
        cout<<-1<<endl;
        return;
    }

    cout<<z.size()+o.size()-1<<el;

    for(int i = 0; i < o.size()-1;i++){
        cout<<o[i]<<" "<<o[i+1]<<el;
        v[o[i]-1]--;
    }

    for(int i = 0; i < o.size() && !z.empty();i++){
        int temp = v[o[i]-1];
        while(temp-- && !z.empty()){
            cout<<o[i]<<" "<<z.front()<<el;
            z.pop();
        }
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
