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
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n;
vector<int> g[N], vir[N];
int q, k, a[N];

namespace cut{
	int dfn[N], siz[N], top[N], dep[N], fa[N], son[N], idx;
	void dfs1(int x,int fat){
		fa[x]=fat, dep[x]=dep[fat]+1, siz[x]=1;
		for(int y:g[x])
			if(y!=fat){
				dfs1(y,x);
				siz[x]+=siz[y];
				if(siz[son[x]]<siz[y])	son[x]=y;
			}
	}
	void dfs2(int x,int tp){
		// cout<<x<<endl;
		top[x]=tp; dfn[x]=++idx;
		if(son[x])	dfs2(son[x],tp);
		for(int y:g[x])
			if(y!=fa[x]&&y!=son[x])	dfs2(y,y);
	}
	int lca(int x,int y){
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]])	swap(x,y);
			x=fa[top[x]];
		}
		return dep[x]<dep[y]?x:y;
	}
	int dis(int x,int y){ return dep[x]+dep[y]-2*dep[lca(x,y)];}
}

int st[N], top, f[N];
bool cmp(int x,int y){ return cut::dfn[x]<cut::dfn[y];}
bool vis[N], tag[N];
vector<int> v, l;

void dfs(int x,int fat){
	// cout<<x<<endl;
	v.pb(x); vis[x]=tag[x];
	int son=0;
	for(int y:vir[x]){
		if(y==fat)	continue;
		dfs(y,x);
		f[x]+=f[y]; son+=vis[y];
		if(tag[x]&&tag[y])	++f[x];
	}
	if(son>=2)	++f[x];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	cut::dfs1(1,0); cut::dfs2(1,1);
	cin>>q;
	while(q--){
		cin>>k;
		for(int i=1;i<=k;++i)	cin>>a[i], tag[a[i]]=true;
		sort(a+1,a+1+k,cmp);
		st[top=1]=1;
		for(int i=1;i<=k;++i){
			if(a[i]==1)	continue;
			int lca=cut::lca(st[top],a[i]);
			if(lca!=st[top]){
				while(cut::dfn[st[top-1]]>cut::dfn[lca])	vir[st[top-1]].pb(st[top]), vir[st[top]].pb(st[top-1]), --top;
				if(cut::dfn[st[top-1]]<lca)	vir[lca].pb(st[top]), vir[st[top]].pb(lca), st[top]=lca;
				else	vir[lca].pb(st[top]), vir[st[top]].pb(lca), --top;
			}
			st[++top]=a[i];
		}
		while(top>1)	vir[st[top-1]].pb(st[top]), vir[st[top]].pb(st[top-1]), --top;
		// for(int x=1;x<=n;++x,cout<<endl)
		// 	for(int y:vir[x])	cout<<y<<" ";
		dfs(1,0);
		// for(int i=1;i<=n;++i)	cout<<f[i]<<" ";
		// cout<<endl;
		bool flag=false;
		for(int x=1;x<=k;++x){
			for(int y:vir[x])
				if(tag[x]&&tag[y]&&cut::dis(x,y)==1){ flag=true; break;}
			if(flag)	break;
		}
		if(flag)	cout<<-1<<endl;
		else	cout<<f[1]<<endl;
		for(int x:v)	f[x]=vis[x]=tag[x]=false, vir[x].clear();
		v.clear();
	}
	return 0;
}