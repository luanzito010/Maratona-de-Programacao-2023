#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;

int n,v[maxn],pos[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    for(int i = 1;i <= n;i++){
        cin >> v[i];
        pos[v[i]] = i;
    }
    
    int c = 1;
    
    for(int i = 2;i <= n;i++)
        if(pos[i] < pos[i - 1])
            c++;
    
    int r = (int) log2(c);
    if(1 << r != c) r++;
    
    cout << r;

    return 0;
}
