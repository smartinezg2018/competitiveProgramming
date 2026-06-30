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
        int n,w; cin>>n>>w;
        vector<v2> v(n);
        forn(i,n) cin>>v[i][0]>>v[i][1];
        vector<vll> dp(n,vll(w+1,0));

        for(int i = v[0][0];i<=w;i++){
            dp[0][i] = v[0][1];
        }
        for1(i,n-1){
            for1(weight,w){
                if(weight<v[i][0]) dp[i][weight] = dp[i-1][weight];
                else dp[i][weight] = max(dp[i-1][weight-v[i][0]]+v[i][1],dp[i-1][weight]);
            }
        }
        cout<<dp[n-1][w]<<el;

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
