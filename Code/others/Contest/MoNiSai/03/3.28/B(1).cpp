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
typedef pair<int,bool> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;

int n,m,f[N];
bool siz[N], t[N];
vector<int> g[N];

namespace d{
    int p1,p2,dep[N];
    void dfs1(int x,int fa){
        dep[x]=dep[fa]+1;
        if(dep[x]>dep[p1])  p1=x;
        for(int i=0;i<g[x].size();++i){
            int y=g[x][i];
            if(y==fa)   continue;
            dfs1(y,x);
        }
    }
    void dfs2(int x,int fa){
        dep[x]=dep[fa]+1;
        if(dep[x]>dep[p2])  p1=x;
        for(int i=0;i<g[x].size();++i){
            int y=g[x][i];
            if(y==fa)   continue;
            dfs1(y,x);
        }
    }
    void getd(){
        dfs1(1,0);
        memset(dep,0,sizeof(dep));
        dfs2(p1,0);
    }
}

namespace tc{
    int siz[N],son[N],dep[N],top[N],fa[N];
    void dfs1(int x,int fat){
        fa[x]=fat, dep[x]=dep[fat]+1, siz[x]=1;
        for(int i=0;i<g[x].size();++i){
            int y=g[x][i];
            if(y==fat)   continue;
            dfs1(y,x);
            siz[x]+=siz[y];
            if(siz[y]>siz[son[x]])  son[x]=y;
        }
    }
    void dfs2(int x,int tp){
        top[x]=tp;
        if(son[x])  dfs2(son[x],tp);
        for(int i=0;i<g[x].size();++i){
            int y=g[x][i];
            if(y==son[x]||y==fa[x]) continue;
            dfs2(y,y);
        }
    }
    int lca(int x,int y){
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]]) swap(x,y);
            x=fa[top[x]];
        }
        if(dep[x]>dep[y])   swap(x,y);
        return x;
    }
    int dis(int x,int y){return dep[x]+dep[y]-2*dep[lca(x,y)];}
}

void dfs1(int x,int fa){
    siz[x]=t[x];
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(y==fa)   continue;
        dfs1(y,x);
        siz[x]|=siz[y];
        f[x]+=f[y]+2*siz[y];
    }
    // if(f[x])    F[x]=f[x]-maxx[x]+dep[x];
}



signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1,x,y;i<n;++i)    cin>>x>>y, g[x].pb(y), g[y].pb(x);
    for(int i=1,x;i<=m;++i) cin>>x, t[x]=true;
    dfs1(1,0);
    int ans=f[1]-tc::dis(d::p1,d::p2);
    for(int i=1;i<=n;++i){
        if(ans==f[1]-max(tc::dis(i,d::p1),tc::dis(i,d::p2))){
            cout<<i<<" "<<ans<<endl;
            return 0;
        }
    }
    return 0;
}