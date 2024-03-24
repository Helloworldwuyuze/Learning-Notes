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
const int N = 2e5 + 10;
const int M = 1e6 + 10;

int n,ans=INF,k;
vector<PII> g[N];

int sum,root,maxx[N],siz[N];
bool vis[N];
void calsiz(int x,int fa){
    maxx[x]=0, siz[x]=1;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(y==fa||vis[y])   continue;
        calsiz(y,x);
        siz[x]+=siz[y], maxx[x]=max(maxx[x],siz[y]);
    }
    maxx[x]=max(maxx[x],sum-siz[x]);
    if(maxx[x]<maxx[root])  root=x;
}

int mindep[M];
int dis[N],dep[N];
vector<int> t,memdep;
void caldis(int x,int fa){
    if(dis[x]>=M)   return ;
    t.pb(x);
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(y==fa||vis[y])   continue;
        dis[y]=dis[x]+z; dep[y]=dep[x]+1;
        caldis(y,x);
    }
}

void dfz(int x){
    vis[x]=true;
    mindep[0]=0, memdep.pb(0);
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(vis[y])  continue;
        dis[y]=z, dep[y]=1;
        t.clear(); caldis(y,x);
        for(int j=0;j<t.size();++j)
            if(dis[t[j]]<=k)    ans=min(ans,mindep[k-dis[t[j]]]+dep[t[j]]);
        for(int j=0;j<t.size();++j)
            mindep[dis[t[j]]]=min(mindep[dis[t[j]]],dep[t[j]]), memdep.pb(dis[t[j]]);
    }
    for(int i=0;i<memdep.size();++i)
        mindep[memdep[i]]=INF;
    memdep.clear();
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(vis[y])   continue;
        sum=siz[y], maxx[root=0]=INF;
        calsiz(y,-1), calsiz(root,-1);
        dfz(root);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>k;
    for(int i=1,x,y,z;i<n;++i)  cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
    sum=n; maxx[root=0]=INF;
    calsiz(1,-1), calsiz(root,-1);
    memset(mindep,0x3f,sizeof(mindep));
    dfz(root);
    if(ans==INF)    cout<<-1<<endl;
    else    cout<<ans<<endl;
    return 0;
}

