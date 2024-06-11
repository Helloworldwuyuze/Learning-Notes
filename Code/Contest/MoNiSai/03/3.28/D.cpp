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
const int N = 4e4 + 10;
const int M = 2e4;
const int MOD = 1e9 + 7;

int n,k,ans;
vector<PII> g[N];

#define lowbit(x) (x&-x)
struct Seg{
    int b[M];
    void update(int x,int y){ for(int i=x;i<=k;i+=lowbit(i))    b[i]+=y;}
    int query(int x){ int ans=0; for(int i=x;i;i-=lowbit(i))    ans+=b[i]; return ans;}
};

int sum,maxx[N],root,siz[N];
bool vis[N];
void calsiz(int x,int fa){
    siz[x]=1, maxx[x]=0;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi;
        if(y==fa||vis[y])   continue;
        calsiz(y,x);
        siz[x]+=siz[y], maxx[x]=max(maxx[x],siz[y]);
    }
    maxx[x]=max(maxx[x],sum-siz[x]);
    if(maxx[x]<maxx[root])  root=x;
}
Seg t;
vector<int> tmp;
void caldis(int x,int fa,int dis){
    // cout<<x<<" "<<fa<<" "<<dis<<endl;
    if(dis>k)   return ;
    tmp.pb(dis);
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(vis[y]||y==fa)   continue;
        caldis(y,x,dis+z);
    }
}
vector<int> v;
void dfz(int x){
    vis[x]=true;
    // cout<<"###"<<x<<"###"<<endl;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(vis[y])  continue;
        // cout<<"##"<<y<<" "<<z<<"##"<<endl;
        tmp.clear(); caldis(y,x,z);
        for(int j=0;j<tmp.size();++j)
            if(k!=tmp[j])   ans+=t.query(k-tmp[j]);
        for(int j=0;j<tmp.size();++j)
            t.update(tmp[j],1), v.pb(tmp[j]);
    }
    ans+=v.size();
    for(int i=0;i<v.size();++i)
        t.update(v[i],-1);
    v.clear();
    // cout<<ans<<endl;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi;
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
    for(int i=1,x,y,z;i<n;++i)  cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
    cin>>k;
    sum=n, maxx[root=0]=INF;
    calsiz(1,-1), calsiz(root,-1);
    dfz(root);
    cout<<ans<<endl;
	return 0;
}