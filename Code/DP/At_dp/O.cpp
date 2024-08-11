#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N = 21 + 10;
const int M = 5e6 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n,f[M];
bool ma[N][N];

int pop_cnt(int x){
    int cnt=0;
    while(x)    cnt+=x%2, x>>=1;
    return cnt;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)   cin>>ma[i][j];
    f[0]=1;
    for(int i=0;i<=(1<<n)-1;++i){
        int cnt=pop_cnt(i);
        for(int j=1;j<=n;++j)
            if((i&(1<<j-1))==0&&ma[cnt+1][j])   f[i|(1<<j-1)]=(f[i|(1<<j-1)]+f[i])%MOD;
    }
    cout<<f[(1<<n)-1]<<endl;
    return 0;
}