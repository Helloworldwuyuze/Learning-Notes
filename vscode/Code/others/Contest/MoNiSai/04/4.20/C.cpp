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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 5e5 + 10;
const int MOD = 998244353;

int n,m;
vector<PII> g[N];

struct ques{
    int u,v;
}q[N];

int root, siz[N], maxx[N], sum, fr[N], dis[N], ans=INF;
bool vis[N];

void calsiz(int x,int fa){
    // cout<<x<<" "<<fa<<endl;
    siz[x]=1, maxx[x]=0;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(y==fa||vis[y])   continue;
        calsiz(y,x);
        siz[x]+=siz[y]; maxx[x]=max(maxx[x],siz[y]);
    }
    maxx[x]=max(maxx[x],sum-siz[x]);
    if(maxx[x]<maxx[root])  root=x;
}

void caldis(int x,int fa,int d){
    dis[x]=d; fr[x]=fr[fa];
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(y==fa)  continue;
        caldis(y,x,d+z);
    }
}

void dfz(int x){
    if(vis[x]){
        cout<<ans<<endl;
        exit(0);
    }
    vis[x]=true; dis[x]=0;
    // cout<<"###"<<x<<"###"<<endl;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        fr[x]=y; caldis(y,x,z);
    }
    fr[x]=x;
    int mx=0, lst;
    bool flag=false;
    for(int i=1;i<=m;++i)
        if(dis[q[i].u]+dis[q[i].v]>mx)  lst=i, mx=dis[q[i].u]+dis[q[i].v];
    // for(int i=1;i<=m;++i)   cout<<dis[q[i].u]<<" "<<dis[q[i].v]<<endl;
    // cout<<fr[q[lst].u]<<endl;
    ans=min(ans,mx);
    for(int i=1;i<=m;++i){
        if(dis[q[i].u]+dis[q[i].v]!=mx) continue;
        if(fr[q[i].u]!=fr[q[i].v]||fr[q[i].u]!=fr[q[lst].u]){
            cout<<ans<<endl;
            exit(0);
        }
    }
    maxx[root=0]=INF, sum=siz[fr[q[lst].u]];
    calsiz(fr[q[lst].u], -1), calsiz(root,-1);
    // if(vis[root])   cout<<ans<<endl, exit(0);
    dfz(root);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1,x,y,z;i<n;++i)  cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
    for(int i=1;i<=m;++i)   cin>>q[i].u>>q[i].v;
    // for(int i=1;i<=n;++i,cout<<endl)
    //     for(int j=0;j<g[i].size();++j)
    //         cout<<g[i][j].fi<<" "<<g[i][j].se<<endl;
    maxx[root=0]=INF; sum=n;
    calsiz(1,-1), calsiz(root,-1);
    dfz(root);
	return 0;
}

