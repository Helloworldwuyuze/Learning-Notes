#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;

int n,h[N],f[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)   cin>>h[i];
    f[1]=0, f[2]=abs(h[1]-h[2]);
    for(int i=3;i<=n;++i)   f[i]=min(f[i-1]+abs(h[i-1]-h[i]),f[i-2]+abs(h[i-2]-h[i]));
    cout<<f[n]<<endl;
    return 0;
}