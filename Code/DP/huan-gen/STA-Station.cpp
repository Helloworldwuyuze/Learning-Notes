#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>

#include<bitset>
#include<set>

#include<deque>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>

#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define DBG cerr << __LINE__ << ' ' << __FUNCTION__ << endl

#define DRE default_random_engine
#define UID uniform_int_distribution
#define y0 Y0
#define y1 Y1

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10;
const int M = 1e6 + 10;

int n,f[N],dp[N],siz[N];
vector<int> g[N];

void dfs(int x,int fa,int dep){
    f[x]=0; siz[x]=1;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(y==fa)   continue;
        dfs(y,x,dep+1);
        siz[x]+=siz[y], f[x]+=f[y]+siz[y];
    }
}
void _dfs(int x,int fa){
    if(x!=1){
        dp[x]=dp[fa]+n-2*siz[x];
    }else   dp[x]=f[x];
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(y==fa)   continue;
        _dfs(y,x);
    }
}
// Helloworldwuyuze
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1,x,y;i<n;++i)    cin>>x>>y, g[y].pb(x), g[x].pb(y);
    dfs(1,0,0); _dfs(1,0);
    int maxx=0;
    for(int i=1;i<=n;++i)   maxx=max(maxx,dp[i]);
    for(int i=1;i<=n;++i)
        if(dp[i]==maxx){ cout<<i<<endl; break;}
    return 0;
}