#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1e2 + 10;
const int M = 1e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n,k,a[N],f[N][M],sum[N][M];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i)   cin>>a[i];
    for(int i=0;i<=k;++i)  
        f[1][i]=(i<=a[1]), sum[1][i]=sum[1][i-1]+f[1][i];
    for(int i=2;i<=n;++i){
        f[i][0]=sum[i][0]=1;
        for(int j=1;j<=k;++j){
            if(j<=a[i]) f[i][j]=sum[i-1][j]%MOD;
            else    f[i][j]=(sum[i-1][j]-sum[i-1][j-a[i]-1]+MOD)%MOD;
            sum[i][j]=(sum[i][j-1]+f[i][j])%MOD;
        }
    }
    cout<<f[n][k]<<endl;
    return 0;
}