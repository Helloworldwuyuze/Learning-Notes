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
const int MAXH = 30;

int n, q, v[N], dfn[N], fa[N][23], t, dep[N], idx, siz[N], rk[N];
vector<int> g[N];

struct TRIE{
	int t[N<<5][2], w[N<<5], idx = 0, root[N];
	void update(int x,int y,int val){
		root[x] = ++idx;
		int p = root[x], q = root[y];
		for(int i=MAXH;i>=0;--i){
			int c = (val>>i)&1;
			t[p][c] = ++idx, t[p][!c] = t[q][!c], w[p] = w[q] + 1;
			p = t[p][c], q = t[q][c];
		}
		w[p] = w[q] + 1;
	}
	int query(int u,int v,int lca, int fa,int val){
		int p = root[u], q = root[v], o = root[lca], r = root[fa], ans = 0;
		for(int i=MAXH;i>=0;--i){
			int c = (val>>i)&1;
			if(w[t[p][!c]] + w[t[q][!c]] - w[t[o][!c]] - w[t[r][!c]] > 0)
				ans += (1<<i), p = t[p][!c], q = t[q][!c], o = t[o][!c], r = t[r][!c];
			else	p = t[p][c], q = t[q][c], o = t[o][c], r = t[r][c];
		}
		return ans;
	}
}t1, t2;

void dfs(int x,int fat){
	fa[x][0] = fat, dfn[x] = ++idx, dep[x] = dep[fat] + 1, siz[x] = 1, rk[idx] = x;
	for(int i=1;i<=t;++i)	fa[x][i] = fa[fa[x][i-1]][i-1];
	t2.update(x, fat, v[x]);
	for(int y:g[x])
		if(y != fat)	dfs(y, x), siz[x] += siz[y];	
}
int lca(int x,int y){
	if(dep[x] < dep[y])	swap(x, y);
	for(int i=t;i>=0;--i)
		if(dep[fa[x][i]] >= dep[y])	x = fa[x][i];
	if(x == y)	return x;
	for(int i=t;i>=0;--i)
		if(fa[x][i] != fa[y][i])	x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>q; t = log(n)/log(2);
	for(int i=1;i<=n;++i)	cin>>v[i];
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	dfs(1, 0);
	for(int i=1;i<=n;++i)	t1.update(i, i-1, v[rk[i]]);
	for(int i=1;i<=q;++i){
		int op, x, y, z;
		cin>>op;
		if(op == 1)	cin>>x>>z, cout<<t1.query(dfn[x]+siz[x]-1, 0, dfn[x]-1, 0, z)<<endl;
		else{
			cin>>x>>y>>z;
			int l = lca(x, y);
			cout<<t2.query(x, y, l, fa[l][0], z)<<endl;
		}
	}
	return 0;
}