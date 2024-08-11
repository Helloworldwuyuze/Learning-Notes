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

int n,m,f[N],siz[N],maxx[N],dep[N],mx[N],h[N],F[N];
bool t[N];
vector<int> g[N],son[N],pmaxx[N],pmx[N],smaxx[N],smx[N];
int type[N];

void dfs1(int x,int fa){
    dep[x]=dep[fa]+1;
    siz[x]=t[x]; maxx[x]=t[x]?dep[x]:0;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(y==fa)   continue;
        son[x].pb(y); dfs1(y,x);
        siz[x]+=siz[y], f[x]+=f[y]+2*(bool)(siz[y]);
        if(maxx[y]>=maxx[x])    mx[x]=maxx[x],maxx[x]=maxx[y];
        else if(maxx[y]>mx[x])  mx[x]=maxx[y];
    }
    if(f[x])    F[x]=f[x]-maxx[x]+dep[x];
    int lst1=0,lst2=0;
    pmaxx[x].pb(0), pmx[x].pb(0); smaxx[x].pb(0), smx[x].pb(0);
    for(int i=1;i<son[x].size();++i){
        pmaxx[x].pb(max(lst1,maxx[son[x][i-1]]));
        pmx[x].pb(max(lst2,mx[son[x][i-1]]));
        lst1=pmaxx[x].back(), lst2=pmx[x].back();
        smaxx[x].pb(0), smx[x].pb(0);
    }
    lst1=0,lst2=0;
    for(int i=son[x].size()-2;i>=0;--i){
        smaxx[x][i]=max(lst1,maxx[son[x][i+1]]);
        smx[x][i]=max(lst2,mx[son[x][i+1]]);
        lst1=smaxx[x].back(), lst2=smx[x].back();
    }
    // cout<<x<<" "<<f[x]<<" "<<F[x]<<endl;
}
void dfs2(int x,int fa){
    cout<<x<<" "<<type[x]<<" "<<h[x]<<" "<<maxx[x]<<endl;
    for(int i=0;i<son[x].size();++i){
        int y=son[x][i];
        // if(maxx[y]==maxx[x]-1)  maxx[x]=max(maxx[y],mx[x]+1), mx[x]=max(min(maxx[y],mx[x]+1),mx[y]), type[y]=1;
        // else if(maxx[y]==mx[x]-1)   maxx[y]=maxx[x]+1, mx[y]=max(mx[y],max(pmx[x][i],smx[x][i])), type[y]=2;
        // else    maxx[y]=max(maxx[y],maxx[x]+1), mx[y]=max(mx[x]+1,mx[y]), type[y]=3;
        maxx[y]=max(maxx[y],max(pmaxx[x][i],smaxx[x][i])+1);
        // cout<<y<<" "<<pmaxx[x][i]<<" "<<smaxx[x][i]<<endl;
        if(siz[y])  h[y]=h[x]-maxx[y]+maxx[x];
        else    h[y]=h[x]+1;
        dfs2(y,x);
    }
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n>>m;
    // memset(maxx,-1,sizeof(maxx));
    // memset(mx,-1,sizeof(mx));
    for(int i=1,x,y;i<n;++i)    cin>>x>>y, g[x].pb(y), g[y].pb(x);
    for(int i=1,x;i<=m;++i) cin>>x, t[x]=true;
    dep[0]=-1;
    dfs1(1,0);
    for(int i=1;i<=n;++i)   maxx[i]-=dep[i]*(bool)(siz[i]), mx[i]-=dep[i]*(siz[i]>1);
    cout<<endl;
    h[1]=F[1];
    dfs2(1,0);
    for(int i=1;i<=n;++i)   cout<<h[i]<<" ";
    cout<<endl;
    int minn=INF;
    for(int i=1;i<=n;++i)   minn=min(minn,h[i]);
    for(int i=1;i<=n;++i){
        if(h[i]==minn){
            cout<<i<<endl<<h[i]<<endl;
            return 0;
        }
    }
    return 0;
}