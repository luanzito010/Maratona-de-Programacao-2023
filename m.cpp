#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e2 + 10;

int n,m[maxn][maxn],mark[maxn][maxn],d[maxn][maxn];

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++){
            cin >> m[i][j];
            d[i][j] = m[i][j];
        }
    
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++){
                int nd = d[i][k] + d[k][j];
                if(nd == d[i][j] && k != i && k != j) mark[i][j] = mark[j][i] = 1;
                d[i][j] = min(d[i][j],nd);
            }
    
    int r = 0;
    bool ok = 1;
    
    for(int i = 1;i <= n;i++)
        for(int j = i + 1;j <= n;j++)
            if(d[i][j] < m[i][j]){
                ok = 0;
                break;
            }
            else if(d[i][j] == m[i][j])
                r += mark[i][j];
                  
    
    cout << (ok ? r : -1);
    
    return 0;
}
