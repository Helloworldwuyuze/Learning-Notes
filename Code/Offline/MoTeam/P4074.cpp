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

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 4e5 + 10;
const int M = 1e6 + 10;

int n, m, q, nn, x, y, op, res;
int v[N], w[N], col[N], c[N], ans[N];
vector<int> g[N];
int dep[N], fa[N], top[N], son[N], siz[N], in[N], out[N], st[N], tp;

void dfs1(int x,int fat){
	fa[x] = fat, dep[x] = dep[fat] + 1, siz[x] = 1;
	st[++tp] = x, in[x] = tp;
	for(int y:g[x]){
		if(y == fat)	continue;
		dfs1(y, x);
		siz[x] += siz[y];
		if(siz[y] > siz[son[x]])	son[x] = y;
	}
	st[++tp] = x, out[x] = tp;
}
void dfs2(int x,int tp){
	top[x] = tp;
	if(son[x])	dfs2(son[x], tp);
	for(int y:g[x])
		if(y!=fa[x] && y!=son[x])	dfs2(y, y);
}
inline int LCA(int x,int y){
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]])	swap(x, y);
		x = fa[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}

struct node{
	int l, r, t, x, y, id;
	bool operator <(const node &other) const{
		return l/nn == other.l/nn ? r/nn == other.r/nn ? t<other.t : r/nn<other.r/nn : l/nn<other.l/nn;
	}
}rng[N], chg[N];
bool appear[N];
int cntr, cntc;

inline void add(int x){
	// cout<<x<<" "<<c[x]<<" "<<col[c[x]]<<" "<<appear[x]<<endl;
	if(appear[x] ^= 1)	++col[c[x]], res += w[col[c[x]]] * v[c[x]];
	else	res -= w[col[c[x]]] * v[c[x]], --col[c[x]];
}
inline void upd(int i,int x){
	// cout<<rng[i].l<<" "<<rng[i].r<<" "<<in[chg[x].l]<<" "<<out[chg[x].l]<<" "<<appear[chg[x].l]<<endl;
	if(appear[chg[x].l]){
		res -= w[col[c[chg[x].l]]] * v[c[chg[x].l]], --col[c[chg[x].l]];
		++col[chg[x].r], res += w[col[chg[x].r]] * v[chg[x].r];
	}
	swap(c[chg[x].l], chg[x].r);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>q; nn = pow(n<<1, 0.6666);
	for(int i=1;i<=m;++i)	cin>>v[i];
	for(int i=1;i<=n;++i)	cin>>w[i];
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	for(int i=1;i<=n;++i)	cin>>c[i];
	dfs1(1, 0); dfs2(1, 1);
	for(int i=1;i<=q;++i){
		cin>>op>>x>>y;
		if(op == 0)	++cntc, chg[cntc] = node{x, y, cntc, 0, 0, i};
		else{
			++cntr; rng[cntr].x = x, rng[cntr].y = y, rng[cntr].id = cntr, rng[cntr].t = cntc;
			if(in[x] > in[y])	swap(x, y);
			if(out[x] >= out[y])	rng[cntr].l = in[x], rng[cntr].r = in[y];
			else	rng[cntr].l = out[x], rng[cntr].r = in[y];
		}
	}
	// for(int i=1;i<=n;++i)	cout<<i<<" "<<top[i]<<" "<<fa[i]<<" "<<in[i]<<" "<<out[i]<<endl;
	// for(int i=1;i<=tp;++i)	cout<<st[i]<<" ";
	// cout<<endl;
	sort(rng+1, rng+1+cntr);
	// for(int i=1;i<=cntr;++i)	cout<<i<<" "<<rng[i].id<<" "<<rng[i].l<<" "<<rng[i].r<<" "<<rng[i].x<<" "<<rng[i].y<<" "<<rng[i].t<<endl;
	int l = 1, r = 0, t = 0;
	// cerr<<"QAQ"<<endl;
	for(int i=1;i<=cntr;++i){
		while(r<rng[i].r)	add(st[++r]);
		while(l>rng[i].l)	add(st[--l]);
		while(r>rng[i].r)	add(st[r--]);
		while(l<rng[i].l)	add(st[l++]);
		while(t<rng[i].t)	upd(i, ++t);
		while(t>rng[i].t)	upd(i, t--);
		ans[rng[i].id] = res;
		int lca = LCA(rng[i].x, rng[i].y);
		// cout<<l<<" "<<r<<" "<<t<<" "<<rng[i].x<<" "<<rng[i].y<<" "<<lca<<" "<<res<<endl;
		if(rng[i].x != lca && lca != rng[i].y)	ans[rng[i].id] += w[col[c[lca]]+1] * v[c[lca]];
	}
	for(int i=1;i<=cntr;++i)	cout<<ans[i]<<endl;
	return 0;
}