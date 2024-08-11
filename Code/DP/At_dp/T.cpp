#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N = 3e3 + 10;
const int M = 5e6 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n,f[N][N],s[N][N];
char c[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=2;i<=n;++i)   cin>>c[i], s[1][i]=1;
    f[1][1]=s[1][1]=1;
    for(int i=2;i<=n;++i){
        for(int j=1;j<=i;++j){
            if(c[i]=='<') f[i][j]=s[i-1][j-1];
            else    f[i][j]=(s[i-1][i-1]-s[i-1][j-1]+MOD)%MOD;
            s[i][j]=(s[i][j-1]+f[i][j])%MOD;
        }
    }
    cout<<s[n][n]<<endl;
    return 0;
}