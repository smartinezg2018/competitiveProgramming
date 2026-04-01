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

void print(map<int,map<int,array<int,2>>>& mp,array<int,2>& B){
    array<int,2> father,cur = B;
    string ans = "";
    while(mp.count(cur[0]) && mp[cur[0]].count(cur[1])){
        father = mp[cur[0]][cur[1]];
        if(cur[0]<father[0]) ans.pb('U');
        else if(cur[1]<father[1]) ans.pb('L');
        else if(cur[1]>father[1]) ans.pb('R');
        else ans.pb('D');
        cur = father;

    }

    cout<<"YES"<<el;
    reverse(all(ans));
    cout<<sz(ans)<<el;
    cout<<ans<<el;

}

void solve(){
    int n,m; cin>>n>>m;
    vector<string> v(n);
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    forn(i,n) cin>>v[i];
    array<int,2> A,B;
    forn(i,n)
        forn(j,m)
            if(v[i][j] == 'A'){
                A[0] = i;
                A[1] = j;
                break;
            }
    queue<array<int,2>> q;
    q.push(A);

    map<int,map<int,array<int,2>>> mp;
    vector<array<int,2>> mov = {{0,1},{0,-1},{1,0},{-1,0}};

    while(!q.empty()){
        array<int,2> a = q.front();
        q.pop();
        
        for(auto [y,x] : mov){
            x += a[1];
            y += a[0];

            if(y>=n || x >=m || y<0 || x < 0 || visited[y][x]) continue;
            if(v[y][x] == 'B'){
                B = {y,x};
                mp[y][x] = a;
                print(mp,B);
                return;
            }
            if(v[y][x] == '.'){
                mp[y][x] = a;
                visited[y][x] = true;
                q.push({y,x});
            }

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
