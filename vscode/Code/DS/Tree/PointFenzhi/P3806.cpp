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
const int N = 1e4 + 10;
const int M = 1e7 + 10;

int n,q[N],m;
vector<PII> g[N];
bool ans[N];

int sum,maxx[N],siz[N],root;
bool vis[N];
void calsiz(int x,int fa){
    siz[x]=1; maxx[x]=0;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(y==fa||vis[y])   continue;
        calsiz(y,x);
        siz[x]+=siz[y]; maxx[x]=max(maxx[x],siz[y]);
    }
    maxx[x]=max(maxx[x],sum-siz[x]);
    if(maxx[x]<maxx[root])  root=x;
}

bitset<M> f;
vector<int> t,mem;
int dis[N];
void caldis(int x,int fa){
    if(dis[x]>=M)   return ;
    t.pb(x);
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(y==fa||vis[y])   continue;
        dis[y]=dis[x]+z;
        caldis(y,x);
    }
}

void dfz(int x){
    vis[x]=true;
    f[0]=true, mem.pb(0);
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(vis[y])  continue;
        t.clear();
        dis[y]=z; caldis(y,x);
        for(int j=1;j<=m;++j)
            for(int k=0;k<t.size();++k)
                if(dis[t[k]]<=q[j]&&q[j]-dis[t[k]]<M)   ans[j]|=f[q[j]-dis[t[k]]];
        for(int k=0;k<t.size();++k)
            if(dis[t[k]]<M) f[dis[t[k]]]=true, mem.pb(dis[t[k]]);
    }
    for(int i=0;i<mem.size();++i)
        f[mem[i]]=false;
    mem.clear();
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(vis[y])  continue;
        maxx[root=0]=INF, sum=siz[y];
        calsiz(y,root), calsiz(root,-1);
        dfz(root);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1,x,y,z;i<n;++i)  cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
    for(int i=1;i<=m;++i)   cin>>q[i];
    maxx[root=0]=INF, sum=n;
    calsiz(1,-1); calsiz(root,-1);
    dfz(root);
    for(int i=1;i<=m;++i)
        if(ans[i])  cout<<"AYE"<<endl;
        else    cout<<"NAY"<<endl;
    return 0;
}

