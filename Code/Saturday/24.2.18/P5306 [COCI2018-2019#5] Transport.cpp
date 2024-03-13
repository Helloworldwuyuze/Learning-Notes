#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<unordered_map>

#include<bitset>
#include<set>

#include<deque>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>
#include<random>

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
const int M = 5e6;

int n,a[N],w[N],maxx[N],sum,root,dis[N],f[N],ans;
vector<PII> g[N];
bool vis[N];

void calsiz(int x,int fa){
	siz[x]=1, maxx[x]=0;
	for(PII y:g[x])
		if(y.fi!=fa&&!vis[y.fi]){
			calsiz(y.fi,x);
			siz[x]+=siz[y.fi], maxx[x]=max(maxx[x],siz[y.fi]);
		}
	maxx[x]=max(maxx[x],sum-siz[x]);
	if(maxx[x]<maxx[root])	root=x;
}

void caldis(int x,int fa){
	for(PII y:g[x])
		if(!vis[y.fi]&&y.fi!=fa)	dis[y.fi]=dis[x]+y.se,w[x]=a[x]+w[fa],caldis(x,fa);
}
int su[N],sd[N],cnt1,cnt2,u[N],d[N],cntu,cntd;
void up(int x,int fa,int pre){
	if(w[x]-dis[x]>=pre)	su[++cnt1]=w[x]-dis[x];
	for(PII y:g[x])
		if(!vis[y.fi]&&y.fi!=fa)	up(y.fi,x,max(pre,w[x]-dis[x]));
}
void down(int x,int fa){
	if(fa!=-1)	sd[++cnt2]=w[fa]-dis[x];
	for(PII y:g[x])
		if(!vis[y.fi]&&y.fi!=pre)	down(y.fi,x)
}

void dfz(int x,int fa){
	vis[x]=true;
	int res=0;
	for(PII y:g[x]){
		if(y.fi!=fa&&!vis[y.fi]){
			dis[y.fi]=y.se; f[y.fi]=x; w[x]=a[x];
			caldis(y.fi,x); cnt1=cnt2=0;
			up(y.fi,x,0), down(y.fi,x);
			sort(su+1,su+1+cnt1); sort(sd+1,sd+1+cnt2);
			sd[cnt+1]=INF;
			for(int i=1,j=cnt1+1;i<=cnt2;++i){
				while(sd[j-1]+su[i]>=0&&j)	--j;
				res+=(cnt1-j+1);
			}
			for(int i=1;i<=cnt1;++i)	u[++cntu]=su[i];
			for(int i=1;i<=cnt2;++i)	d[++cntd]=sd[i];
		}
		sort(u+1,u+1+cntu), sort(d+1,d+1+cntd);
		for(int i=1,j=u+1;i<=cntd;++i){
			while(d[j-1]+u[i]>=0&&j)	--j;
			ans+=(cntu-j+1);
		}
		ans-=res;
	}
	for(PII y:g[x]){
		if(y.fi!=fa&&!vis[y.fi]){
			root=0, maxx[root]=INF, sum=siz[y.fi];
			
		}
	}
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)	cin>>a[i];
    for(int i=1,x,y,z;i<n;++i)	cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
    root=0, maxx[root]=INF, sum=n;
    calsiz(1,-1), calsiz(root,-1);
    dfz(root,-1);
    return 0;
}


