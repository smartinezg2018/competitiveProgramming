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

void solve(){
// conclusiones que hay que tener en cuenta
// los 0s no afectan la salida, la cantidad de 1s es lo que define
// cuando es tie? cuando ambos son pares o ambos son impares
// se sabe que si sale uno y entra otro la condicion sigue siendo la misma
// luego, vemos como se comportarian los datos
// si voy perdiendo quiero hacer algun switch, pero claro
// ahí me pregunto, cuantos switch necesito
// y como me aseguro que el otro ya no puede hacer
// ahi me doy cuenta que siempre que alguno tenga switch
// puede decidir si sigue como va o cambia
// por lo que controla quien gana
// así se llega a la conclusion que el ultimo que tenga switch
// es quien decide quien gana
// ya que decide las condiciones de ambos

	int n; cin>>n;
	vector<int> a(n),m(n);
	int aone = 0,mone = 0;
	forn(i,n){
		 cin>>a[i];
		 if(a[i]==1)aone++;
	}
	forn(i,n) {
		cin>>m[i];
		if(m[i]==1)mone++;
	}
	
	if((mone%2 == 0 && aone%2 == 0)||(mone%2 != 0 && aone%2 != 0)){
		cout<<"Tie"<<endl;
		return;
	}
	
	forn(i,n){
		if(a[n-1-i]!=m[n-1-i]){
			if((n-i)%2!=0)
				cout<<"Ajisai"<<endl;
			else 
				cout<<"Mai"<<endl;
			return;
		}
	}
	
	
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