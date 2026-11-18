#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define print(x) cout << " " << x << el

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;
typedef array<ll, 2> v2;

const int inf = 1e9;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;
const ll mod = 1e9 + 7;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

ostream &operator<<(ostream &os, const ii &pa)
{ // DEBUGGING
    return os << "(" << pa.fi << ", " << pa.se << ")";
}

map<int, vi> mp;
vector<int> father;
vector<bool> visited;
vector<int> ans;
ll n, m;

bool in(int f, int s)
{
    return find(all(mp[f]), s) != mp[f].end();
}

void dfs(int f)
{
    visited[f] = true;
    if (!ans.empty())
        return;
    for (int s : mp[f])
    {
        if (visited[s] && father[f] != s && father[f] != 0 && ans.empty())
        {
            ans.pb(s);
            ans.pb(f);

            // cout << s << " ";
            // cout << f << " ";

            int cur = father[f];
            while (!in(cur, s))
            {
                if (in(cur, s))
                    break;
                // cout << cur << " ";
                ans.pb(cur);
                cur = father[cur];
            }
            ans.pb(cur);
            // cout << cur << " ";
            ans.pb(s);
            // cout << s << el;
            return;
        }

        if (visited[s])
            continue;

        father[s] = f;
        dfs(s);
    }
}

void solve()
{
    cin >> n >> m;
    visited.assign(n + 1, false);
    father.assign(n + 1, 0);

    int a, b;
    forn(i, m)
    {
        cin >> a >> b;
        mp[a].pb(b);
        mp[b].pb(a);
    }

    for (auto [h, v] : mp)
    {
        if (!ans.empty())
            break;
        if (visited[h])
            continue;
        dfs(h);
    }

    if (ans.empty())
    {
        cout << "IMPOSSIBLE" << el;
        return;
    }
    cout << ans.size() << el;
    forn(i, ans.size())
    {
        cout << ans[i] << " ";
    }

    // cout << visited.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(20) << fixed;
    // ll t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}