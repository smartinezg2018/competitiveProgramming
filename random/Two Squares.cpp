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
    int n = 4;
    vector<array<float,2>> s1(n),s2(n);
    forn(i,n) cin>>s1[i][0]>>s1[i][1];
    forn(i,n) cin>>s2[i][0]>>s2[i][1];

    sort(all(s1));
    sort(all(s2));

    for(auto [x,y] : s2){
        bool mask = (x>=s1[0][0] && y >= s1[0][1] &&
                    x <= s1[3][0] && y <= s1[3][1]); 
        if(mask){
            cout<<"YES"<<el;
            return;
        }
    }
    array<float,2> mov1 = s2[1];
    array<float,2> mov2 = s2[2];

    // s1.pb({(s1[3][0]-s1[0][0])/2,(s1[3][1]-s1[0][1])/2});
    float xtemp = s1[0][0]+((s1[3][0]-s1[0][0])/2); 
    float ytemp = s1[0][1]+(s1[3][1]-s1[0][1])/2;
    // d(xtemp);
    // d(ytemp);
    if(ytemp-mov1[1] >= abs(xtemp-mov1[0]) && ytemp-mov2[1] <= - abs(xtemp-mov2[0]) ){
        cout<<"YES"<<el;
        return;
    }
    
    for(auto [x,y] : s1){

        
        bool mask = (y-mov1[1] >= abs(x-mov1[0]) && 
                    y-mov2[1] <= - abs(x-mov2[0]) ); 
        
        if(mask){
            cout<<"YES"<<el;
            return;
        }
    }

    cout<<"NO"<<el;




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
