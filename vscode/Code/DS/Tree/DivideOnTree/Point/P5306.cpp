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

int n,ans,a[N];
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

int dis[N],w[N];
vector<int> rootup, rootdown, sonup, sondown;
void caldis(int x,int fa,int maxx,int minn){
    // cout<<x<<" "<<fa<<" "<<maxx<<" "<<minn<<" "<<w[x]<<" "<<dis[x]<<endl;
    if(w[x]-dis[x]>=maxx)
        sonup.pb(w[x]-dis[x]);
    sondown.pb(minn);
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(y==fa||vis[y])   continue;
        dis[y]=dis[x]+z, w[y]=w[x]+a[y];
        caldis(y,x,max(maxx,w[x]-dis[x]),min(minn,w[x]-dis[y]));
    }
}

void dfz(int x){
    vis[x]=true;
    rootup.clear(), rootdown.clear();
    dis[x]=0, w[x]=a[x];
    // cout<<"###"<<x<<"###"<<endl;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(vis[y])  continue;
        dis[y]=dis[x]+z, w[y]=w[x]+a[y];
        sonup.clear(), sondown.clear();
        caldis(y,x,w[x]-dis[x],w[x]-dis[y]);
        sort(sonup.begin(),sonup.end());
        sort(sondown.begin(),sondown.end());
        int k=0;
        for(int j=sondown.size()-1;j>=0;--j){
            while(k<sonup.size()&&sonup[k]+sondown[j]-a[x]<0)    ++k;
            ans-=(sonup.size()-k);
        }
        for(int j=0;j<sonup.size();++j) rootup.pb(sonup[j]);
        // cout<<endl;
        for(int j=0;j<sondown.size();++j)   rootdown.pb(sondown[j]);
        // cout<<endl;
        // cout<<ans<<endl;
    }
    // cout<<endl;
    // for(int i=1;i<=n;++i)   cout<<w[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;++i)   cout<<dis[i]<<" ";
    // cout<<endl;
    sort(rootup.begin(), rootup.end());
    sort(rootdown.begin(), rootdown.end());
    int j=0;
    for(int i=rootdown.size()-1;i>=0;--i){
        if(rootdown[i]>=0)  ++ans;
        while(j<rootup.size()&&rootup[j]+rootdown[i]-a[x]<0)  ++j;
        ans+=(rootup.size()-j);
    }
    ans+=rootup.size();
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(vis[y])  continue;
        sum=siz[y], maxx[root=0]=INF;
        calsiz(y,-1), calsiz(root,-1);
        dfz(root);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)   cin>>a[i];
    for(int i=1,x,y,z;i<n;++i)  cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
    sum=n, maxx[root=0]=INF;
    calsiz(1,-1), calsiz(root,-1);
    dfz(root);
    cout<<ans<<endl;
    return 0;
}