#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 1e2 + 10;

#define int long long
int n,f[N],w[M],v[M],m;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)   cin>>w[i]>>v[i];
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for(int i=1;i<=n;++i)
        for(int j=N-10;j>=v[i];--j)
            f[j]=min(f[j],f[j-v[i]]+w[i]);
    for(int i=N-10;i>=0;--i)
        if(f[i]<=m){ cout<<i<<endl; break;}
    return 0;
}