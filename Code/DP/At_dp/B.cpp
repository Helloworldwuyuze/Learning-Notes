#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;

int n,h[N],f[N],k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i)   cin>>h[i];
    memset(f,0x3f,sizeof(f));
    f[1]=0;
    for(int i=2;i<=n;++i)
        for(int j=i-1;j>0&&i-j<=k;--j)
            f[i]=min(f[i],f[j]+abs(h[i]-h[j]));
    cout<<f[n]<<endl;
    return 0;
}