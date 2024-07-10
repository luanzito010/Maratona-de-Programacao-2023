#include <bits/stdc++.h>
#define int long long 
#define pb push_back
#define fr first
#define sc second
#define bg begin()
#define ed end()
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define debug(x) cout << x << endl;

using namespace std;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;

const int maxn = 3e2 + 10,inf = 1e9;

int n,m;
vector<pii> edg;
vector<vector<int>> dist(maxn,vector<int>(maxn,inf)),ex[maxn];

void fw(int l,int r,vector<vector<int>> &dist){
    
    for(int k = l;k <= r;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
    
}

void daq(int l,int r,vector<vector<int>> &dist){
   
    if(l == r){ 
        ex[l] = dist;
        return;
    }
    
    vector<vector<int>> aux = dist;    
    int m = (l + r) >> 1;

    fw(l,m,dist);
    daq(m + 1,r,dist);
    fw(m + 1,r,aux);
    daq(l,m,aux);
    
}

void solve(){
    
    cin >> n >> m;
    
    for(int i = 1;i <= m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        edg.pb({u,v});
        dist[u][v] = dist[v][u] = w;
    }
    
    daq(1,n,dist);
    
    for(auto [u,v] : edg){
        int resp = inf;
        for(int i = 1;i <= n;i++)
            if(u != i && v != i)
                resp = min(resp,ex[v][u][i] + ex[u][i][v]);
        cout << (resp == inf ? -1 : resp) << "\n";
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}
