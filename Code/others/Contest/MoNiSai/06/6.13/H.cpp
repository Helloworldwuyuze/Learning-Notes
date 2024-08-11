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
const int N = 3e5 + 10;
const int M = 1e6 + 10;

int n,m;
vector<PII> g[N];
struct route{
	int u, v, len;
	bool operator <(const route &other) const { return len > other.len;}
}r[N];

namespace seg{
	int maxx[N<<2], tag[N<<2];
	void push_down(int p){
		if(!tag[p])	return ;
		tag[p<<1] = max(tag[p<<1], tag[p]), tag[p<<1|1] = max(tag[p<<1|1], tag[p]);
		maxx[p<<1] = max(maxx[p<<1], tag[p]), maxx[p<<1|1] = max(maxx[p<<1|1], tag[p]);
		tag[p] = 0;
	}
	void push_up(int p){ maxx[p] = max(maxx[p<<1], maxx[p<<1|1]);}
	void update(int p,int l,int r,int left,int right,int k){
		if(left<=l&&r<=right){ maxx[p] = max(maxx[p], k), tag[p] = max(tag[p], k); return ;}
		int mid = l+r>>1;
		push_down(p);
		if(left<=mid)	update(p<<1, l, mid, left, right, k);
		if(right>mid)	update(p<<1|1, mid+1, r, left, right, k);
		push_up(p);
	}
	int query(int p,int l,int r,int x){
		if(l==r)	return maxx[p];
		push_down(p);
		int mid = l+r>>1;
		if(x<=mid)	return query(p<<1, l, mid, x);
		else	return query(p<<1|1, mid+1, r, x);
	}
}

vector<PII> range;
namespace cut{
	int dfn[N], rk[N], idx, siz[N], son[N], fa[N], dep[N], top[N], dis[N];
	void dfs1(int x,int fat){
		fa[x] = fat, dep[x] = dep[fat] + 1, siz[x] = 1;
		for(PII y:g[x]){
			if(y.fi==fat)	continue;
			dis[y.fi] = dis[x] + y.se;
			dfs1(y.fi, x);
			siz[x] += siz[y.fi];
			if(siz[y.fi]>siz[son[x]])	son[x] = y.fi;
		}
	}
	void dfs2(int x,int tp){
		top[x] = tp, dfn[x] = ++idx, rk[idx] = x;
		if(son[x])	dfs2(son[x], tp);
		for(PII y:g[x])
			if(!dfn[y.fi])	dfs2(y.fi, y.fi);
	}
	int LCA(int x,int y){
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]])	swap(x,y);
			x = fa[top[x]];
		}
		return dep[x]<dep[y]?x:y;
	}
	void ModifyMax(route r){
		range.clear();
		int x = r.u, y = r.v, z = r.len;
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]])	swap(x,y);
			range.pb(mk(dfn[top[x]], dfn[x]));
			x = fa[top[x]];
		}
		if(dep[x]<dep[y])	swap(x,y);
		if(x!=y)	range.pb(mk(dfn[son[y]], dfn[x]));
		sort(range.begin(), range.end());
		for(int i = 0; i<range.size(); ++i){
			if(i == 0)
				if(range[i].fi!=1)	seg::update(1, 1, n, 1, range[i].fi - 1, z);
			if(i>0&&range[i].fi!=range[i-1].se+1)	seg::update(1, 1, n, range[i-1].se+1, range[i].fi-1, z);
			if(i == range.size() - 1)
				if(range[i].se!=n)	seg::update(1, 1, n, range[i].se + 1, n, z);
		}
	}
}

int solve(){
	sort(r + 1, r + 1 + m);
	int ans = r[1].len;
	route x = r[1];
	int l = cut::LCA(x.u, x.v);
	while(x.u != l){
		int len = cut::dis[x.u] - cut::dis[cut::fa[x.u]];
		ans = min(ans, max(x.len - len, seg::query(1, 1, n, cut::dfn[x.u])));
		x.u = cut::fa[x.u];
	}
	while(x.v != l){
		int len = cut::dis[x.v] - cut::dis[cut::fa[x.v]];
		ans = min(ans, max(x.len - len, seg::query(1, 1, n, cut::dfn[x.v])));
		x.v = cut::fa[x.v];
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1,x,y,z;i<n;++i)	cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
	cut::dfs1(1, 0), cut::dfs2(1, 1);
	for(int i=1;i<=m;++i){
		cin>>r[i].u>>r[i].v;
		int l = cut::LCA(r[i].u, r[i].v);
		r[i].len = cut::dis[r[i].u] + cut::dis[r[i].v] - 2 * cut::dis[l];
		cut::ModifyMax(r[i]);
		// cout<<r[i].u<<" "<<r[i].v<<" "<<r[i].len<<endl;
	}
	cout<<solve()<<endl;
	return 0;
}