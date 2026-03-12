// #include <bits/stdc++.h>

// #define fi first
// #define se second
// #define forn(i,n) for(int i=0; i< (int)n; ++i)
// #define for1(i,n) for(int i=1; i<= (int)n; ++i)
// #define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
// #define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
// #define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
// #define pb push_back
// #define el '\n'
// #define d(x) cout<< #x<< " " << x<<el
// #define ri(n) scanf("%d",&n)
// #define sz(v) int(v.size())
// #define all(v) v.begin(),v.end()

// using namespace std;

// typedef long long ll;
// typedef double ld;
// typedef pair<int,int> ii;
// typedef pair<ll,ll> pll;
// typedef tuple<int, int, int> iii;
// typedef vector<int> vi;
// typedef vector<ii> vii;
// typedef vector<ll> vll;
// typedef vector<ld> vd;
// typedef array<ll,2> v2;


// const int inf = 1e9;
// const int nax = 1e5+200;
// const ld pi = acos(-1);
// const ld eps= 1e-9;
// const ll mod = 1e9+7;

// int dr[] = {1,-1,0, 0,1,-1,-1, 1};
// int dc[] = {0, 0,1,-1,1, 1,-1,-1};

// ostream& operator<<(ostream& os, const ii& pa) { // DEBUGGING
// return os << "("<< pa.fi << ", " << pa.se << ")";
// }

// string to_bits(ll n){
//     string s = "";
//     while(n>0){
//         if(n%2!=0) s.pb('1');
//         else s.pb('0');
//         n/=2;
//     }
//     while(sz(s)<32) s.pb('0');
//     // reverse(all(s));
//     return s;
// }
// void solve(){
//     ll n; cin>>n;
//     vll v(n);
//     forn(i,n) cin>>v[i];
//     vector<string> ans;
//     forn(i,n){
//         ans.pb(to_bits(v[i]));
//     }

//     ll acum = 0;
//     for(int j = 0; j<32;j++){
//         int z = 0,o = 0;
//         for(int i = 0; i<n;i++){
//         // cout<<ans[i]<<el;
//             if(ans[i][j]=='0') z++;
//             else o++;
//         }
//         if(o%2!=0 && z%2!=0){
//             cout<<-1<<el;
//             return;
//         }
//         if(o%2==0) continue;
//         else acum += (1<<j);
//     }
//     cout<<acum<<el;


// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);
//     cout << setprecision(20)<< fixed;
//     ll t; cin>>t;
//     while(t--)
//     solve();
//     return 0;
// }

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

string to_bits(ll n){
    string s = "";
    while(n>0){
        if(n%2!=0) s.pb('1');
        else s.pb('0');
        n/=2;
    }
    while(sz(s)<32) s.pb('0');
    // reverse(all(s));
    return s;
}
void solve(){

    // podermos sacar como "factor comun el x"
    // esto se hace haciendo (ai ^...^ an)^(x^...^x)
    // entonces si es numero impar de numeros
    // podemos sacar el mismo numero que tenemos al hacer xor
    // ya quue poner un numero impar de xors nos da el mismo numero
    // asi al repetir el xor final nos da 0
    // al ser par tenemos mas casos,
    // al repetir par el numero 1 conseguimos el 0
    // con el 0 conseguimos igual el 0
    // todo nos da 0, por lo que la base tiene que ser 0, si no no existe
    
    ll n; cin>>n;
    vll v(n);
    forn(i,n) cin>>v[i];
    ll base = 0;
    forn(i,n) base^=v[i];
    if(n%2==0) {
        if(base == 0) cout << 0;
        else cout << -1;
    }
    else cout << base;
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
