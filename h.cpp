#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fr first
#define sc second

using namespace std;
using tii = tuple<int,int,int>;

struct pq{
    int c,r,best;
};

bool operator <(const pq &a,const pq &b){
    
    if(a.c != b.c) return a.c < b.c;
    else if(a.r != b.r) return a.r > b.r;
    else return a.best > b.best;
    
}

int n,s;
vector<tii> v;
priority_queue<pq> f;

int32_t main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> s;
    
    for(int i = 1;i <= n;i++){
        int l,r,c;
        cin >> l >> r >> c;
        v.pb({l,r,c});
    }
    
    sort(v.begin(),v.end());
    
    int resp = 0;
    int best_at = 0;
    int best_last = 0;
    
    for(auto [l,r,c] : v){
        int cost = (r - l + 1) * s - c;
        best_at = cost;
        
        while(!f.empty() && f.top().r < l){
            best_last = max(best_last,f.top().best);
            f.pop();
        }
        
        best_at = max(best_at,cost + best_last);
        
        if(!f.empty())
            best_at = max(best_at,f.top().c + s * r - c);
        
        f.push({best_at - s * r,r,best_at});    
        resp = max(resp,best_at);
    }
    
    cout << resp;
    
    return 0;
}
