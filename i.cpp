#include <bits/stdc++.h>
#define int long long

using namespace std;

int n,r,pref,m[2];

int32_t main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    
    m[pref & 1]++;
    
    for(int i = 1,x;i <= n;i++){
        cin >> x;
        pref += x;
        r += m[!(pref & 1)];
        m[pref & 1]++;
    }
    
    cout << r;
    
    return 0;
}
