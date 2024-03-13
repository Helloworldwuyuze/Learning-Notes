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

vector<PII> g[N];
int f[N],siz[N],n,c[N],s;

void dfs(int x,int fa){
    siz[x]=c[x];
    for(int i=0;i<g[x].size();++i){
        PII y=g[x][i];
        if(y.fi==fa)   continue;
        dfs(y.fi,x);
        siz[x]+=siz[y.fi], f[x]+=f[y.fi]+siz[y.fi]*y.se;
    }
}
void _dfs(int x,int fa,int edge){
    if(x!=1)    f[x]=f[fa]+(s-siz[x])*edge-siz[x]*edge;
    for(int i=0;i<g[x].size();++i){
        PII y=g[x][i];
        if(y.fi==fa)    continue;
        _dfs(y.fi,x,y.se);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)   cin>>c[i], s+=c[i];
    for(int i=1,x,y,z;i<n;++i)   cin>>x>>y>>z,g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
    dfs(1,0); _dfs(1,0,0);
    int minn=INF;
    for(int i=1;i<=n;++i)   minn=min(minn,f[i]);
    cout<<minn<<endl;
    return 0;
}