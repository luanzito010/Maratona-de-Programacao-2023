#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int k;
string s;
vector<char> v[maxn];

int main()
{
    cin >> s >> k;
    
    int n = (int) s.size();
    
    for(int i = 0;i < n;i++)
        v[i % k].push_back(s[i]);
    
    for(int i = 0;i < k;i++)
        sort(v[i].begin(),v[i].end());
        
    for(int i = 0;i < n;i++)
        cout << v[i % k][i / k];

    return 0;
}
