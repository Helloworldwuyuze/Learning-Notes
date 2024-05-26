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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 3e5 + 10;
const int M = 1e6 + 10;

int n, t;
vector<int> g[N];
vector<PII> vir[N];
int q, k, a[N], b[N];
int siz[N], son[N], Top[N], dfn[N], fa[N][20], dep[N], idx;
void dfs0(int x,int fat){
	fa[x][0]=fat, siz[x]=1, dep[x]=dep[fat]+1;
	for(int i=1;i<=t;++i)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int y:g[x])
		if(y!=fat){
			dfs0(y,x);
			siz[x]+=siz[y];
			if(siz[son[x]]<siz[y])	son[x]=y;
		}
}
void dfs1(int x,int tp){
	Top[x]=tp; dfn[x]=++idx;
	if(son[x])	dfs1(son[x],tp);
	for(int y:g[x])
		if(y!=fa[x][0]&&y!=son[x])	dfs1(y,y);
}
int lca(int x,int y){
	while(Top[x]!=Top[y]){
		if(dep[Top[x]]<dep[Top[y]])	swap(x,y);
		x=fa[Top[x]][0];
	}
	return dep[x]<dep[y]?x:y;
}
int dis(int x,int y){ return dep[x]+dep[y]-2*dep[lca(x,y)]; }

bool cmp(int x,int y){ return dfn[x]<dfn[y];}
int st[N], top=0,f[N],minn[N],id[N];
bool tag[N];

void cal(int x,int y){
	int mid=y, p=y;
	for(int i=t;i>=0;--i)
		if(dep[fa[p][i]]>dep[x])	p=fa[p][i];
	f[id[x]]-=siz[p];
	// cout<<"cal "<<f[id[x]]<<" "<<id[x]<<" "<<p<<" "<<siz[p]<<endl;
	for(int i=t;i>=0;--i){
		int l=dep[y]-dep[fa[mid][i]]+minn[y], r=dep[fa[mid][i]]-dep[x]+minn[x];
		if(dep[fa[mid][i]]>dep[x]&&(l<r||(l==r&&id[y]<id[x])))	mid=fa[mid][i];
	}
	// if(!(dis(x,y)&1)&&id[y]>id[x])	mid=fa[mid][0];
	f[id[y]]+=siz[mid]-siz[y], f[id[x]]+=siz[p]-siz[mid];
	// cout<<x<<" "<<y<<" "<<id[y]<<" "<<siz[mid]-siz[id[y]]<<" "<<id[x]<<" "<<siz[p]-siz[mid]<<" "<<p<<" "<<mid<<" "<<f[id[x]]<<endl;
}
void dfs2(int x){
	minn[x]=INF;
	for(PII y:vir[x]){
		dfs2(y.fi);
		if(minn[y.fi]+y.se<minn[x])	minn[x]=minn[y.fi]+y.se, id[x]=id[y.fi];
		else if(minn[y.fi]+y.se==minn[x])	id[x]=min(id[x],id[y.fi]);
		// cout<<"DFS2"<<x<<" "<<y.fi<<" "<<minn[x]<<" "<<id[x]<<" "<<tag[x]<<endl;
	}
	if(tag[x])	id[x]=x, minn[x]=0;
}
void dfs3(int x){
	// cout<<"###"<<x<<"###"<<endl;
	// for(int i=1;i<=n;++i)	cout<<f[i]<<" ";
	// cout<<endl;
	for(PII y:vir[x]){
		if(minn[x]+y.se<minn[y.fi])	minn[y.fi]=minn[x]+y.se, id[y.fi]=id[x];
		else if(minn[x]+y.se==minn[y.fi])	id[y.fi]=min(id[y.fi],id[x]);
		cal(x,y.fi);
		dfs3(y.fi);
	}
	f[id[x]]+=siz[x];
}

void init(int x){
	for(PII y:vir[x])	init(y.fi);
	f[x]=0; vir[x].clear(); tag[x]=false; id[x]=0, minn[x]=INF;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n; t=log(n)/log(2)+1;
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	dfs0(1,0); dfs1(1,1);
	// for(int i=1;i<=n;++i)	cout<<siz[i]<<" ";
	// cout<<endl;
	cin>>q;
	while(q--){
		cin>>k;
		for(int i=1;i<=k;++i)	cin>>a[i], b[i]=a[i], tag[a[i]]=true;
		sort(a+1,a+1+k,cmp);
		st[top=1]=1;
		for(int i=1;i<=k;++i){
			if(a[i]==1)	continue;
			int l=lca(st[top],a[i]);
			// cout<<a[i]<<" "<<st[top]<<" "<<l<<endl;
			if(l!=st[top]){
				while(dfn[st[top-1]]>dfn[l])	vir[st[top-1]].pb(mk(st[top],dis(st[top],st[top-1]))), --top;
				if(dfn[st[top-1]]<dfn[l])	vir[l].pb(mk(st[top],dis(l,st[top]))), st[top]=l;
				else	vir[l].pb(mk(st[top], dis(st[top],l))), --top;
			}
			st[++top]=a[i];
		}
		while(top>1)	vir[st[top-1]].pb(mk(st[top],dis(st[top],st[top-1]))), --top;
		// for(int x=1;x<=n;++x){
			// cout<<"###"<<x<<" "<<siz[x]<<"###"<<endl;
			// for(PII y:vir[x])	cout<<y.fi<<" "<<y.se<<endl;
		// }
		dfs2(1);
		// for(int i=1;i<=n;++i)	cout<<id[i]<<endl;
		dfs3(1);
		// for(int x=1;x<=n;++x)	cout<<f[x]<<" ";
		// cout<<endl;
		for(int i=1;i<=k;++i)	cout<<f[b[i]]<<" ";
		cout<<endl;
		init(1);
	}
	return 0;
}