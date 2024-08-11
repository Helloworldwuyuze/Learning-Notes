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
#define endl '\n'

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n,m,q,k;
vector<int> g[N];
vector<int> t[N], tr[N];
set<int> flag[N];

int belong[N], siz[N], cnt, dfn[N], low[N], idx;
bool inst[N];
int st[N], top;
vector<int> scc[N];
void Tarjan(int x){
	dfn[x]=low[x]=++idx;
	st[++top]=x, inst[x]=true;
	for(int y:g[x])
		if(!dfn[y])	Tarjan(y), low[x]=min(low[x],low[y]);
		else if(inst[y])	low[x]=min(low[x],dfn[y]);
	if(low[x]==dfn[x]){
		++cnt; int t;
		do{
			t=st[top--];
			belong[t]=cnt, ++siz[cnt], inst[t]=false;
			scc[cnt].pb(t);
		}while(t!=x);
	}
}
int du[N], pre[N], root;
queue<int> Q;
void topo(){
	for(int i=1;i<=cnt;++i)
		if(du[i]==0)	pre[i]=siz[i], root=i, Q.push(i);
	while(!Q.empty()){
		int x=Q.front(); Q.pop();
		for(int y:t[x])
			if(--du[y]==0)	pre[y]=pre[x]+siz[y], Q.push(y), tr[x].pb(y);
	}
}

namespace cut{
	int son[N],siz[N],fa[N],dep[N],top[N],dfn[N],idx=0;
	void dfs1(int x,int fat){
		fa[x]=fat; siz[x]=1, dep[x]=dep[fat]+1;
		for(int y:tr[x])
			if(y!=fat){
				dfs1(y,x);
				siz[x]+=siz[y];
				if(siz[son[x]]<siz[y])	son[x]=y;
			}
	}
	void dfs2(int x,int tp){
		top[x]=tp, dfn[x]=++idx;
		if(son[x])	dfs2(son[x],tp);
		for(int y:tr[x])
			if(y!=fa[x]&&y!=son[x])	dfs2(y,y);
	}
	int lca(int x,int y){
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]])	swap(x,y);
			x=fa[top[x]];
		}
		return dep[x]<dep[y]?x:y;
	}
}

int pnt[10], S, T, u1, u2, v1, v2;
namespace Virtree{
	vector<PII> vir[N];
	bool cmp(int x,int y){ return cut::dfn[x]<cut::dfn[y];}
	void build(){
		st[top=1]=S;
		sort(pnt+1,pnt+3+k*2,cmp);
		for(int i=1;i<=2+k*2;++i){
			if(pnt[i]==S)	continue;
			int lca=cut::lca(pnt[i],st[top]);
			if(lca!=st[top]){
				while(cut::dfn[st[top-1]]>cut::dfn[lca])
					vir[st[top-1]].pb(mk(st[top],pre[st[top]]-pre[st[top-1]]-siz[st[top-1]]));
				if(cut::dfn[st[top-1]]<cut::dfn[lca])
					vir[lca].pb(mk(st[top],pre[st[top]]-pre[lca]-siz[st[top]])), st[top]=lca;
				else	vir[lca].pb(mk(st[top],pre[st[top]]-pre[lca]-siz[st[top]])), --top;
			}
			st[++top]=pnt[i];
		}
		while(top>1)	vir[st[top-1]].pb(mk(st[top], pre[st[top-1]]-pre[st[top]]-siz[st[top-1]]));
	}
}

int dis[N][2];
void bfs(int s,bool f){
	Q.push(s); dis[s][f]=0;
	while(!Q.empty()){
		int x=Q.front(); Q.pop();
		for(auto y:Virtree::vir[x]){
			
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>q>>k;
	for(int i=1,x,y;i<=m;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	for(int i=1;i<=n;++i)
		if(!dfn[i])	Tarjan(i);
	for(int i=1;i<=cnt;++i)
		for(int x:scc[i])
			for(int y:g[x])
				if(i!=belong[y]&&flag[i].find(belong[y])==flag[i].end())
					flag[i].insert(belong[y]), ++du[belong[y]], t[i].pb(belong[y]);
	for(int i=1;i<=q;++i){
		cin>>S>>T; pnt[1]=S, pnt[2]=T;
		if(k==1)	cin>>u1>>v1, pnt[3]=u1, pnt[4]=v1;
		if(k==2)	cin>>u1>>v1>>u2>>v2, pnt[3]=u1, pnt[4]=v1, pnt[5]=u2, pnt[6]=v2;
		Virtree::build();
		bfs(S,0), bfs(T,1);
	}
	return 0;
}