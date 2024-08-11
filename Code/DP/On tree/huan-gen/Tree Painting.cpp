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
const int N = 2e5 + 10;
const int M = 1e6 + 10;

int n,siz[N],f[N];
vector<int> g[N];

void dfs1(int x,int fa){
    siz[x]=f[x]=1;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(y==fa)   continue;
        dfs1(y,x);
        f[x]+=f[y]+siz[y]; siz[x]+=siz[y];
    }
}
void dfs2(int x,int fa){
    if(x!=1)    f[x]=f[fa]+(n-siz[x])-siz[x];
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(y==fa)   continue;
        dfs2(y,x);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1,x,y;i<n;++i)    cin>>x>>y, g[x].pb(y), g[y].pb(x);
    dfs1(1,0); dfs2(1,0);
    int ans=0;
    for(int i=1;i<=n;++i)
        ans=max(ans,f[i]);
    cout<<ans<<endl;
    return 0;
}