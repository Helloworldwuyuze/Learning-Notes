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
const int N = 1e4 + 10;
const int M = 5e4 + 10;

int n,m,q,x,y,z,fa[N];
vector<PII> g[N];
PIII e[M];
int root[N],tot,a[N];
bool vis[N];
int siz[N],son[N],top[N],dep[N],rk[N],dfn[N],f[N],idx;

int find(int x){ return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}
void dfs1(int x,int fat){
	siz[x]=1, f[x]=fat, dep[x]=dep[fat]+1; vis[x]=true;
	for(PII y:g[x]){
		if(y.fi==fat)	continue;
		dfs1(y.fi,x);
		siz[x]+=siz[y.fi];
		if(siz[y.fi]>siz[son[x]])	son[x]=y.fi;
	}
}
void dfs2(int x,int tp){
	top[x]=tp, dfn[x]=++idx; rk[dfn[x]]=x;
	if(son[x])	dfs2(son[x],tp);
	for(PII y:g[x]){
		if(y.fi==f[x]||y.fi==son[x])	continue;
		dfs2(y.fi,y.fi);
	}
}

struct node{
	int left,right,minn;
}t[N<<2];
void push_up(int p){ t[p].minn=min(t[p<<1].minn,t[p<<1|1].minn);}
void build(int p,int left,int right){
	t[p].left=left, t[p].right=right;
	if(left==right){ t[p].minn=a[rk[left]]; return ;}
	int mid=left+right>>1;
	build(p<<1,left,mid), build(p<<1|1,mid+1,right);
	push_up(p);
}
int query(int p,int left,int right){
	if(left<=t[p].left&&t[p].right<=right)	return t[p].minn;
	int mid=t[p].left+t[p].right>>1;
	int res=INF;
	if(left<=mid)	res=min(res,query(p<<1,left,right));
	if(right>mid)	res=min(res,query(p<<1|1,left,right));
	return res;
}
int LCA(int x,int y){
	int ans=INF;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])	swap(x,y);
		ans=min(ans,query(1,dfn[top[x]],dfn[x]));
		x=f[top[x]];
	}
	if(dep[x]<dep[y])	swap(x,y);
	return min(ans,query(1,dfn[y]+1,dfn[x]));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i)	cin>>x>>y>>z, e[i]=mk(z,mk(x,y));
	sort(e+1,e+1+m);
	for(int i=1;i<=n;++i)	fa[i]=i;
	for(int i=m;i;--i){
		x=e[i].se.fi, y=e[i].se.se;
		int fx=find(x), fy=find(y);
		if(fx==fy)	continue;
		g[x].pb(mk(y,e[i].fi)), g[y].pb(mk(x,e[i].fi)), fa[fx]=fy;
		// cout<<x<<" "<<y<<endl;
	}
	for(int i=1;i<=n;++i)
		if(!vis[i])	root[++tot]=i, dfs1(root[tot],0), dfs2(root[tot],root[tot]);
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;++i)
		for(PII j:g[i])
			if(j.fi!=f[i])	a[j.fi]=j.se;
	for(int i=1;i<=tot;++i)	a[root[i]]=INF;
	build(1,1,n);
	// cout<<tot<<" "<<root[1]<<endl;
	// for(int i=1;i<=n;++i)	cout<<i<<" "<<dfn[i]<<" "<<siz[i]<<" "<<a[dfn[i]]<<" "<<f[i]<<endl;
	cin>>q;
	while(q--){
		cin>>x>>y;
		if(find(x)!=find(y)){
			cout<<-1<<endl;
			continue;
		}cout<<LCA(x,y)<<endl;
	}
	return 0;
}