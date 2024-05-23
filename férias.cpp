#include<iostream>

using namespace std;
using ll = long long int;

const int maxn=1e5+10;

ll d;
int c,r,resp,cv[maxn],cr[maxn];

int main(){

    cin>>d>>c>>r;

    for(int i=1; i<=c; i++)
        cin>>cv[i];

    for(int i=1; i<=r; i++) {
        cin>>cr[i];
    }

    int at=1,aux=1;

    while(d>=cv[at]&&at<=c||aux<=r) {
        if(d>=cv[at]&&at<=c) {
            d-=cv[at];
            at++;
            resp++;
        }
        else if(aux<=r){
            d+=cr[aux];
            aux++;
            resp++;
        }
        else break;

    }

    cout<<resp
    return 0;
}
  
