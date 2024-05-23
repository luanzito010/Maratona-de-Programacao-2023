#include <bits/stdc++.h>

using namespace std;

const int maxn=1e6+10;

int n,k,maior,x,qtd,dp[maxn];

int digit(string s){
    int t=0;
    for(auto i:s)
        t+=i-'0';
    return t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n>>k;
    
    for(int i=1;i<=n;i++){
        cin>>x;
        dp[x]++;
        maior=max(maior,x);
    }

    for(int i=maior;i>=0;i--){
        dp[i-digit(to_string(i))]+=dp[i];
        if(dp[i]) qtd+=dp[i];
        if(qtd>=k){ 
            cout<<digit(to_string(i))<<"\n";
            return 0;
        }
    }
    
    cout<<0;

    return 0;
}
