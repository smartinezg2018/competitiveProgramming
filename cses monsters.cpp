#include <bits/stdc++.h>

#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define el '\n'

using namespace std;

// D U R L  (d^1 es la dirección inversa)
// const int dr[] = {1,-1,0, 0};
// const int dc[] = {0, 0,1,-1};
// const char DIR[] = "DURL";

// void solve(){
//     int n, m; cin >> n >> m;
//     vector<string> g(n);
//     forn(i,n) cin >> g[i];

//     int N = n*m, start = -1;
//     vector<int> dm(N, -1), da(N, -1), q(N);
//     vector<char> how(N, -1);

//     // BFS multi-fuente desde todos los monstruos
//     int head = 0, tail = 0;
//     forn(i,n) forn(j,m){
//         if(g[i][j] == 'M'){ dm[i*m+j] = 0; q[tail++] = i*m+j; }
//         else if(g[i][j] == 'A') start = i*m+j;
//     }
//     while(head < tail){
//         int u = q[head++], r = u/m, c = u%m;
//         forn(d,4){
//             int nr = r+dr[d], nc = c+dc[d];
//             if(nr<0 || nr>=n || nc<0 || nc>=m || g[nr][nc]=='#') continue;
//             int v = nr*m+nc;
//             if(dm[v] != -1) continue;
//             dm[v] = dm[u]+1;
//             q[tail++] = v;
//         }
//     }

//     // BFS desde A: solo entra a celdas donde llega estrictamente antes que un monstruo
//     head = tail = 0;
//     q[tail++] = start; da[start] = 0;
//     int found = -1;
//     while(head < tail){
//         int u = q[head++], r = u/m, c = u%m;
//         if(r==0 || r==n-1 || c==0 || c==m-1){ found = u; break; }
//         forn(d,4){
//             int nr = r+dr[d], nc = c+dc[d];
//             if(g[nr][nc]=='#') continue; // u no está en borde => vecino en rango
//             int v = nr*m+nc;
//             if(da[v] != -1) continue;
//             if(dm[v] != -1 && dm[v] <= da[u]+1) continue;
//             da[v] = da[u]+1;
//             how[v] = d;
//             q[tail++] = v;
//         }
//     }

//     if(found == -1){ cout << "NO" << el; return; }

//     string s;
//     for(int u = found; u != start; ){
//         int d = how[u];
//         s += DIR[d];
//         u -= dr[d]*m + dc[d];
//     }
//     reverse(s.begin(), s.end());
//     cout << "YES" << el << s.size() << el << s << el;
// }
vector<int> dr = {1,-1, 0, 0};
vector<int> dc = {0, 0, 1,-1};
string directions = "DURL";
int inf = 1e5+200;
void solve(){
    int n,m,start,solution = -1;
    cin>>n>>m;
    vector<string> v(n);
    forn(i,n) cin>>v[i];
    vector<int> how(n*m);

    vector<int> dm(n*m,inf),da(n*m,-1);
    queue<int> q;
    forn(i,n)
        forn(j,m) 
            if(v[i][j] == 'M') {q.push(i*m+j);dm[i*m+j] = 0;}
            else if(v[i][j] == 'A') start = i*m+j;

            // int np = nr*m+nc;

    if(start/m ==0 ||start/m ==n-1 ||start%m ==0||start%m ==m-1){
        cout<<"YES"<<el<<0<<el;
        return;
    }

    while(!q.empty()){
        int o = q.front();q.pop();
        forn(d,4){
            int nr = (o/m) + dr[d],nc = (o%m) + dc[d];
            int np = (nr*(m))+nc;
            if(nr<0 || nr>=n || nc<0||nc>=m||v[nr][nc] == '#' ||dm[np]!=inf) continue;
            // cout<<np<<el;
            dm[np] = dm[o]+1;
            q.push(np);
        }
    }
    // forn(i,n){
    //     forn(j,m)cout<<dm[i*m+j];
    //     cout<<el;

    // }
    // return;

    q.push(start);
    da[start] = 0;
    while(!q.empty()){
        int o = q.front();q.pop();
        
        forn(d,4){
            int nr = (o/m) + dr[d],nc = (o%m) + dc[d];
            int np = nr*m+nc;
            // cout<<np<<el;

            if(nr<0 || nr>=n || nc<0||nc>=m||v[nr][nc] == '#'||da[np]!=-1||da[o]+1 >=dm[np]) continue;

            if(nr == 0 || nr == n-1 || nc == 0||nc == m-1){
                solution = np;
                how[np] = d;
                while(!q.empty()) q.pop();
                break;
            }

            q.push(np);
            how[np] = d;
            da[np] = da[o]+1;
        }
    }
    // forn(i,n){
    //     forn(j,m)cout<<da[i*m+j];
    //     cout<<el;

    // }
    // return;
    if(solution == -1){
        cout<<"NO"<<el;
        return;
    }
    string ans = "";
    // cout<<how[solution];
    // return;
    for(int temp = solution; temp != start;){
        ans += directions[how[temp]];
        temp = ((temp/m)-dr[how[temp]]) * m + (temp%m)-dc[how[temp]];

    }
    reverse(ans.begin(),ans.end());
    cout<<"YES"<<el<<ans.size()<<el<<ans<<el;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
