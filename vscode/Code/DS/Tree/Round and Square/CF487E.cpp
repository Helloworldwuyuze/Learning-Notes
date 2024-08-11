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
const int N = 2e5 + 10;
const int M = 1e6 + 10;

int n, m, q, x, y;
int a[N];
vector<int> g[N], v[N], scc[N];
int dfn[N], low[N], idx, cnt, st[N], top, val[N];
char op;
multiset<int> sc[N];

void Tarjan(int x){
	dfn[x] = low[x] = ++idx;
	st[++top] = x;
	for(int y:g[x])
		if(!dfn[y]){
			Tarjan(y);
			low[x] = min(low[x], low[y]);
			if(low[y] == dfn[x]){
				scc[++cnt].pb(x);
				while(st[top+1] != y)	scc[cnt].pb(st[top--]);
				val[cnt+n] = INF;
				for(int z:scc[cnt])
					val[z] = a[z], v[cnt+n].pb(z), v[z].pb(cnt+n);
			}
		}else	low[x] = min(low[x], dfn[y]);
}

namespace seg{
	int minn[N<<2];
	void update(int p,int l,int r,int x,int k){
		if(l == r)	return (void)(minn[p] = k);
		int mid = l+r>>1;
		if(x<=mid)	update(p<<1, l, mid, x, k);
		else	update(p<<1|1, mid+1, r, x, k);
		minn[p] = min(minn[p<<1], minn[p<<1|1]);
	}
	int query(int p,int l,int r,int left,int right){
		// cerr<<p<<" "<<l<<" "<<r<<" "<<left<<" "<<right<<endl;
		if(left<=l&&r<=right)	return minn[p];
		int mid = l+r>>1, res = INF;
		if(left<=mid)	res = min(res, query(p<<1, l, mid, left, right));
		if(right>mid)	res = min(res, query(p<<1|1, mid+1, r, left, right));
		return res;
	}
}

namespace cut{
	int dfn[N], rk[N], top[N], siz[N], dep[N], fa[N], son[N], idx;
	void dfs1(int x,int fat){
		fa[x] = fat, siz[x] = 1, dep[x] = dep[fat]+1;
		for(int y:v[x])
			if(y!=fat){
				dfs1(y, x);
				siz[x] += siz[y];
				if(x>n)	sc[x-n].insert(val[y]);
				if(siz[son[x]] < siz[y])	son[x] = y;
			}
	}
	void dfs2(int x,int tp){
		top[x] = tp; dfn[x] = ++idx, rk[idx] = x;
		if(son[x])	dfs2(son[x], tp);
		for(int y:v[x])
			if(y!=son[x] && y!=fa[x])	dfs2(y, y);
	}
	int query(int x,int y){
		int ans = INF;
		while(top[x] != top[y]){
			if(dep[top[x]] < dep[top[y]])	swap(x,y);
			ans = min(ans, seg::query(1, 1, cnt+n, dfn[top[x]], dfn[x]));
			x = fa[top[x]];
		}
		if(dep[x] > dep[y])	swap(x, y);
		ans = min(ans, seg::query(1, 1, cnt+n, dfn[x], dfn[y]));
		if(x > n)	ans = min(ans, val[fa[x]]);
		return ans;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;++i)	cin>>a[i];
	for(int i=1,x,y;i<=m;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	Tarjan(1);
	// for(int i=1;i<=cnt;++i,cout<<endl)
	// 	for(int j:scc[i])	cout<<j<<" ";
	cut::dfs1(1, 0), cut::dfs2(1, 1);
	// for(int i=1;i<=n+cnt;++i)
		// cout<<i<<" "<<cut::dfn[i]<<" "<<cut::dep[i]<<" "<<cut::son[i]<<" "<<cut::top[i]<<endl;
	for(int i=1;i<=cnt;++i)	val[i+n] = *sc[i].begin();
	for(int i=1;i<=cnt+n;++i)	seg::update(1, 1, cnt+n, cut::dfn[i], val[i]);
		// for(int i=1;i<=n+cnt;++i)
		// 	cout<<val[i]<<" ";
		// cout<<endl;
	while(q--){
		cin>>op>>x>>y;
		if(op=='C'){
			if(cut::fa[x]){
				int fa = cut::fa[x] - n;
				sc[fa].erase(val[x]), sc[fa].insert(y);
				val[fa+n] = *sc[fa].begin();
				seg::update(1, 1, cnt+n, cut::dfn[fa+n], val[fa+n]);
			}
			val[x] = y;
			seg::update(1, 1, cnt+n, cut::dfn[x], val[x]);
		}else	cout<<cut::query(x, y)<<endl;
		// cout<<"######"<<endl;
		// for(int i=1;i<=(n+cnt)<<1;++i)	cout<<seg::minn[i]<<" ";
		// cout<<endl;
		// for(int x:sc[1])	cout<<x<<" ";
		// cout<<endl;
		// for(int i=1;i<=n+cnt;++i)
			// cout<<val[i]<<" ";
		// cout<<endl;
	}
	return 0;
}