#include <bits/stdc++.h>
#define int long long int

using namespace std;
using pii = pair<int,int>;

struct pt{
    int x,y,id;
    
    pt operator -(const pt &a){ return {x - a.x,y - a.y}; }
    int operator /(const pt &a){ return {x * a.y - y * a.x}; }
    bool operator <(const pt &a){
        if(x != a.x) return x < a.x;
        return y < a.y;
    }
    bool operator ==(const pt &a){
        if(x != a.x) return x != a.x;
        else if(y != a.y) return y != a.y;
        else return id != a.id;
    }
    
};

int n;
set<int> r;
vector<pt> v,u,l,c;

int32_t main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    
    for(int i = 1;i <= n;i++){
        int x,y;
        cin >> x >> y;
        v.push_back({x,y,i});
    }
    
    sort(v.begin(),v.end());
    
    int it1 = 0,it2 = 0;
    
    for(int i = 0;i < n;i++){
        
        while(it1 > 1 && (v[i] - u[it1 - 2]) / (u[it1 - 1] - u[it1 - 2]) < 0){
            u.pop_back();
            it1--;
        }
        
        u.push_back(v[i]);
        it1++;
        
        while(it2 > 1 && (v[i] - l[it2 - 2]) / (l[it2 - 1] - l[it2 - 2]) > 0){
            l.pop_back();
            it2--;
        }
        
        l.push_back(v[i]);
        it2++;
        
    }
    
    for(int i = 0;i < it1;i++)
        c.push_back(u[i]);
    
    for(int i = 0;i < it2;i++)
        c.push_back(l[i]);
        
    for(auto [x,y,i] : c)
        r.insert(i);
    
    for(auto i : r)
        cout << i << " ";
    
    return 0;
}
