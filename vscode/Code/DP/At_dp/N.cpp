#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N = 4e2 + 10;
const int M = 1e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n,a[N],f[N][N],s[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;++i)   cin>>a[i], s[i]=s[i-1]+a[i], f[i][i]=0;
    for(int len=2;len<=n;++len){
        for(int i=1;i+len-1<=n;++i){
            int j=i+len-1;
            for(int k=i;k<j;++k)    f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
        }
    }
    cout<<f[1][n]<<endl;
    return 0;
}