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
const int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

vector<int> g[N];
int n,k,c[N],siz[N],f[N][26],fa[N],dep[N],dp[N][26];

void dfs1(int x,int fat){
    fa[x]=fat; dep[x]=dep[fat]+1; siz[x]=1;
    for(int i=0, xx=x;i<=k&&xx;++i, xx=fa[xx])
        f[xx][dep[x]-dep[xx]]+=c[x];
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(y==fat)  continue;
        dfs1(y,x);
        siz[x]+=siz[y];
    }
}
void dfs2(int x){
    dp[x][0]=c[x]; dp[x][1]=f[x][1]+c[fa[x]]+c[x]*(x!=1);
    if(x!=1)    for(int i=2;i<=k;++i)   dp[x][i]=dp[fa[x]][i-1]+f[x][i]+f[x][i-1];
    else    for(int i=2;i<=k;++i)   dp[x][i]=f[x][i];
    if(x==1)    for(int i=1;i<=k;++i)   dp[x][i]+=dp[x][i-1];
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(y==fa[x])    continue;
        dfs2(y);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>k;
    for(int i=1,x,y;i<n;++i)    cin>>x>>y, g[x].pb(y), g[y].pb(x);
    for(int i=1;i<=n;++i)   cin>>c[i];
    dfs1(1,0);
    dfs2(1);
    // for(int i=1;i<=n;++i,cout<<endl)
    //     for(int j=0;j<=k;++j)   cout<<f[i][j]<<" ";
    // for(int i=1;i<=n;++i,cout<<endl)
    //     for(int j=0;j<=k;++j)   cout<<dp[i][j]<<" ";
    for(int i=1;i<=n;++i)   cout<<dp[i][k]<<endl;
    return 0;
}