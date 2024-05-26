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
const int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10;
const int M = 1e6 + 10;

int n, q;
vector<PII> g[N];
int minn[N], dfn[N], idx, top[N], siz[N], son[N], fa[N], dep[N];
int st[N], tp;
bool require[N];
vector<int> vir[N];

void dfs1(int x,int fat){
	fa[x]=fat; siz[x]=1, dep[x]=dep[fat]+1;
	for(auto y:g[x]){
		int v=y.fi, z=y.se;
		if(v==fat)	continue;
		minn[v]=min(z,minn[x]);
		dfs1(v,x);
		siz[x]+=siz[v];
		if(siz[son[x]]<siz[v])	son[x]=v;
	}
}
void dfs2(int x,int tp){
	top[x]=tp; dfn[x]=++idx;
	if(son[x])	dfs2(son[x],tp);
	for(auto y:g[x])
		if(y.fi!=son[x]&&y.fi!=fa[x])	dfs2(y.fi,y.fi);
}
int callca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])	swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}

int k,h[N];
bool cmp(int x,int y){ return dfn[x]<dfn[y]; }

int dfs3(int x){
	int sum=0, ans;
	for(int y:vir[x])	sum+=dfs3(y);
	if(x==1)	return require[x]=false, vir[x].clear(), sum;
	if(require[x])	ans=minn[x];
	else	ans=min(sum,minn[x]);
	// cout<<require[x]<<" "<<minn[x]<<" "<<x<<" "<<ans<<endl;
	require[x]=false, vir[x].clear();
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1,x,y,z;i<n;++i)	cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
	minn[1]=INF; dfs1(1,0), dfs2(1,1); minn[1]=0;
	cin>>q;
	while(q--){
		cin>>k;
		for(int i=1;i<=k;++i)	cin>>h[i], require[h[i]]=true;
		sort(h+1,h+1+k,cmp);
		tp=0; st[++tp]=1;
		for(int i=1;i<=k;++i){
			if(h[i]==1)	continue;
			int lca=callca(h[i],st[tp]);
			if(lca!=st[tp]){
				while(dfn[st[tp-1]]>dfn[lca])	vir[st[tp-1]].pb(st[tp]), --tp;
				if(dfn[st[tp-1]]<dfn[lca])	vir[lca].pb(st[tp]), st[tp]=lca;
				else	vir[lca].pb(st[tp]), --tp;
			}
			st[++tp]=h[i];
			// for(int i=1;i<=tp;++i)	cout<<st[i]<<" ";
			// cout<<endl;
		}
		while(tp>1)	vir[st[tp-1]].pb(st[tp]), --tp;
		// for(int i=1;i<=n;++i){
			// cout<<"###"<<i<<"###"<<endl;
			// for(int y:vir[i])	cout<<y<<" ";
			// cout<<endl;
		// }
		cout<<dfs3(1)<<endl;
	}
	return 0;
}