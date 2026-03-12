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

int lcs(vector<ll> &s1, vector<ll> &s2, int n, int m) {
    if(n == 0 || m == 0)
        return 0;
    if(s1[n] == s2[m])
        return 1 + lcs(s1,s2,n-1,m-1);
    return max(lcs(s1,s2,n,m-1),lcs(s1,s2,n-1,m));
}

int lcsRec(string &s1, string &s2, int m, int n, vector<vector<int>> &memo) {
    if (m == 0 || n == 0)
        return 0;
    if (memo[m][n] != -1)
        return memo[m][n];
    if (s1[m - 1] == s2[n - 1])
        return memo[m][n] = 1 + lcsRec(s1, s2, m - 1, n - 1, memo);
    return memo[m][n] = max(lcsRec(s1, s2, m, n - 1, memo), lcsRec(s1, s2, m - 1, n, memo));
}

void solve(){
    int n,m; cin>>n>>m;
    vll a(n),b(m);
    forn(i,n) cin>>a[i];
    forn(i,m) cin>>b[i];

    vector<vector<ll>> dp(n+1,vector<ll>(m+1));
    for(int i = 1; i<=n;i++){
        for(int j = 1 ; j<=m;j++){
            dp[i][j] = max({dp[i-1][j-1]+(a[i-1]==b[j-1]?1:0),dp[i-1][j],dp[i][j-1]});
        }
    }
    cout<<dp[n][m]<<el;

    int i = n, j = m;
    vll ans;

    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            ans.push_back(a[i-1]);
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(all(ans));

    forn(i,sz(ans)) cout<<ans[i]<<" ";
    cout<<el;


    

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

