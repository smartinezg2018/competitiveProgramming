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


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

ostream& operator<<(ostream& os, const ii& pa) { // DEBUGGING
return os << "("<< pa.fi << ", " << pa.se << ")";
}

string to_bit(ll n){
    string s = "";
    while(n>0){
        if(n%2==0){
            s+='0';
        }
        else{
            s+='1';
        }
        n/=2;
    }
    reverse(all(s));
    return s;
}

ll to_decimal(string s){
    ll ans = 0;
    for(int i = 0 ;i <s.size();i++){
        if(s[s.size()-1-i]=='1') ans += (1<<i);
    }
    return ans;
}



void solve(){
    ll a,b;cin>>a>>b;
    string as = to_bit(a),bs = to_bit(b);
    if(as.size()<bs.size()){
        cout<<-1<<endl;
        return;
    }

    while(as.size()>bs.size())
        bs.insert(0,1,'0');

    
    vector<int> v;
    forn(i,as.size()){
        int index = as.size()-1-i;
        if(as[index]=='0'){
            if(bs[index]=='1')
                v.push_back(i);
        }
        else{
            if(bs[index]=='0')
                v.push_back(i);

        }
    }
    // reverse(all(ans));
    // cout<<as<<endl<<bs<<endl;
    cout<<v.size()<<endl;
    if(v.size()==0)return;
    for(int& n:v){
        cout<<(1<<n)<<" ";
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
