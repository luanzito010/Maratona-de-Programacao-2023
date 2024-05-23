#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 1;

int n,c[maxn],resp[maxn];
vector<int> g[maxn];
multiset<int> s;

void dfs(int u,int p) {
    int ant = 0;
    auto x = s.lower_bound(c[u]);
    if(x != s.end()) {
        ant = *x;
        s.erase(x);
    }
    
    s.insert(c[u]);
    
    resp[u] = (int) s.size();

    for(auto v : g[u])
        if(v != p)
            dfs(v,u);

    s.erase(s.find(c[u]));
    
    if(ant) s.insert(ant);

}

int main()
{
    cin >> n;

    for(int i = 2,x; i <= n; i++) {
        cin >> x;
        g[x].push_back(i);
        g[i].push_back(x);
    }

    for(int i = 1; i <= n; i++)
        cin >> c[i];
    
    dfs(1,0);

    for(int i = 2; i <= n; i++)
        cout << resp[i] << " ";

    return 0;
}
