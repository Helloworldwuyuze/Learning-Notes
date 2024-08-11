#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>
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

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e6 + 10;
const int M = 1e6 + 10;

int n;
vector<int> g[N];
int q,k,a[N];
vector<PII> vir[N];

namespace cut{
	int dfn[N], siz[N], dep[N], son[N], top[N], fa[N], idx;
	void dfs(int x,int fat){
		fa[x]=fat, dep[x]=dep[fat]+1, siz[x]=1;
		for(int y:g[x])
			if(y!=fat){
				dfs(y,x);
				siz[x]+=siz[y];
				if(siz[son[x]]<siz[y])	son[x]=y;
			}
	}
	void _dfs(int x,int tp){
		top[x]=tp, dfn[x]=++idx;
		if(son[x])	_dfs(son[x],tp);
		for(int y:g[x])
			if(y!=son[x]&&y!=fa[x])	_dfs(y,y);
	}
	int lca(int x,int y){
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]])	swap(x,y);
			x=fa[top[x]];
		}
		return dep[x]<dep[y]?x:y;
	}
	int dis(int x,int y){
		int l=lca(x,y);
		return dep[x]+dep[y]-2*dep[l];
	}
}

bool cmp(int x,int y){
	return cut::dfn[x] < cut::dfn[y];
}
void add(int x,int y){
	int z=cut::dis(x,y);
	vir[x].pb(mk(y,z)), vir[y].pb(mk(x,z));
}
int st[N], top, minn[N], dis[N], f[N], siz[N], maxx, mn, id;
bool tag[N];

void dfs1(int x,int fat){
	siz[x]=tag[x]; minn[x]=tag[x]?0:INF;
	if(tag[x]&&dis[x]>maxx)	maxx=dis[x], id=x;
	for(PII p:vir[x]){
		int y=p.fi, z=p.se;
		if(y==fat)	continue;
		dis[y]=dis[x]+z;
		dfs1(y,x);
		if(siz[x])	mn=min(mn,minn[x]+minn[y]+z);
		minn[x]=min(minn[x],minn[y]+z); siz[x]+=siz[y];
		f[x]+=f[y]+z*siz[y];
	}
}
void dfs2(int x,int fat){
	for(PII p:vir[x]){
		int y=p.fi, z=p.se;
		if(y==fat)	continue;
		f[y]=f[x]+(k-siz[y])*z-siz[y]*z;
		dfs2(y,x);
	}
}
void dfs3(int x,int fat){
	// cout<<x<<" "<<fat<<" "<<tag[x]<<" "<<dis[x]<<" "<<f[x]<<endl;
	if(dis[x]>maxx&&tag[x])	maxx=dis[x];
	for(PII p:vir[x])
		if(p.fi!=fat)	dis[p.fi]=dis[x]+p.se, dfs3(p.fi, x);
}
void init(int x,int fat){
	for(PII y:vir[x])
		if(y.fi!=fat)	init(y.fi, x);
	dis[x]=0; f[x]=0, siz[x]=tag[x]=0, minn[x]=INF;
	vir[x].clear();
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	memset(minn,0x3f,sizeof(minn));
	cin>>n;
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	cut::dfs(1,0), cut::_dfs(1,1);
	cin>>q;
	while(q--){
		cin>>k;
		for(int i=1;i<=k;++i)	cin>>a[i], tag[a[i]]=true;
		sort(a+1,a+1+k,cmp);
		st[top=1]=1;
		for(int i=1;i<=k;++i){
			if(a[i]==1)	continue;
			int lca=cut::lca(st[top],a[i]);
			// cout<<st[top]<<" "<<a[i]<<" "<<cut::top[st[top]]<<" "<<cut::top[a[i]]<<" "<<lca<<endl;
			if(lca!=st[top]){
				while(cut::dfn[st[top-1]]>cut::dfn[lca])	add(st[top-1],st[top]), --top;
				if(cut::dfn[st[top-1]]<cut::dfn[lca])	add(lca,st[top]), st[top]=lca;
				else	add(lca,st[top]), --top;
			}
			st[++top]=a[i];
			// for(int i=1;i<=top;++i)	cout<<st[i]<<" ";
			// cout<<endl;
		}
		while(top>1)	add(st[top-1],st[top]), --top;
		mn=INF; dis[1]=maxx=0; dfs1(1,0);
		// for(int i=1;i<=n;++i){
		// 	cout<<"###"<<i<<" "<<f[i]<<"###"<<endl;
		// 	for(PII y:vir[i])	cout<<y.fi<<" "<<y.se<<" "<<f[y.fi]<<endl;
		// }
		dfs2(1,0); dis[id]=maxx=0; dfs3(id,0);
		int sum=0;
		for(int i=1;i<=k;++i)	sum+=f[a[i]];
		cout<<sum/2<<" "<<mn<<" "<<maxx<<endl;
		init(1,0);
	}
	return 0;
}