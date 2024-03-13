#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
const int M = 1e2 + 10;

#define int long long
const int MOD = 1e9 + 7;
char c[N][N];
int n,m,f[N][N];

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%s", c[i]+1);
    f[1][1]=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(c[i][j]!='#'&&!(i==1&&j==1))    f[i][j]=(f[i-1][j]+f[i][j-1])%MOD;
    cout<<f[n][m]<<endl;
    return 0;
}