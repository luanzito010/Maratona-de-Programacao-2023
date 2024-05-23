#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
const ll maxn=3e2+10,inf=1e18+10;

int a,b,c,i,j,k,n,m,dist,u,mark[maxn];
ll d[maxn],mat[maxn][maxn][2];
vector<pair<int,int>>pares,g[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    cin>>n>>m;
    
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            if(i==j) mat[i][j][0]=mat[i][j][1]=0;
            else mat[i][j][0]=mat[i][j][1]=inf;
        }
    
    for(i=1;i<=m;i++){
        cin>>a>>b>>c;
        mat[a][b][0]=mat[b][a][0]=mat[a][b][1]=mat[b][a][1]=c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
        pares.push_back({a,b});
    }
    
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                mat[i][j][1]=min(mat[i][j][1],mat[i][k][1]+mat[k][j][1]);
    
    for(auto [a,b]:pares) {
        if(mat[a][b][1]<mat[a][b][0]) cout<<mat[a][b][1]<<"\n";
        else{
        
        for(int i=1;i<=n;i++)
            d[i]=inf,mark[i]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>f;
        d[a]=0;
        f.push({d[a],a});
        while(!f.empty()){
            dist=f.top().first,u=f.top().second;
            f.pop();
            if(mark[u]) continue;
            mark[u]=1;
            for(auto [v,w]:g[u]){
                if(u==a&&v==b||u==b&&v==a) continue;
                if(d[v]>dist+w){
                    d[v]=dist+w;
                    f.push({d[v],v});
                }
            }
        }
        cout<<(d[b]==inf?-1:d[b])<<"\n";
    }
    }

    return 0;
}
