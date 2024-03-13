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
    for(int i=1;i<=n;++i)
        for(int j=m;j>=w[i];--j)
            f[j]=max(f[j],f[j-w[i]]+v[i]);
    cout<<f[m]<<endl;
    return 0;
}