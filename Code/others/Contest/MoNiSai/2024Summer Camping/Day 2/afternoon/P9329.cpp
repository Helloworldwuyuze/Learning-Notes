#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>

#include<bitset>
#include<set>

#include<deque>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>

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
const int N = 1e5 + 10;
const int M = 1e6 + 10;
const int MAXN = 1e9+1;

int n, m, q, t;
vector<PII> g[N];
vector<int> chk[N];

int root[N], ls[N<<5], rs[N<<5], sum[N<<5], cnt[N<<5], idx;
void update(int &p,int q,int l,int r,int x){
	p = ++idx, ls[p] = ls[q], rs[p] = rs[q], sum[p] = sum[q], cnt[p] = cnt[q];
	if(l == r)	return (void)(++cnt[p], sum[p] += x);
	int mid = l+r>>1;
	if(x <= mid)	update(ls[p], ls[q], l, mid, x);
	else	update(rs[p], rs[q], mid+1, r, x);
	sum[p] = sum[ls[p]] + sum[rs[p]], cnt[p] = cnt[ls[p]] + cnt[rs[p]]; 
}
int query(int u,int v,int fa,int l,int r,int k){
	int lcnt = cnt[ls[u]] + cnt[ls[v]] - 2*cnt[ls[fa]];
	int lsum = sum[ls[u]] + sum[ls[v]] - 2*sum[ls[fa]];
//	cout<<"QUERY! "<<u<<" "<<v<<" "<<fa<<" "<<l<<" "<<r<<" "<<k<<" "<<cnt[ls[fa]]<<" "<<sum[ls[fa]]<<endl;
	if(l == r)	return k*l;
	int mid = l+r>>1;
	if(lcnt >= k)	return query(ls[u], ls[v], ls[fa], l, mid, k);
	else	return query(rs[u], rs[v], rs[fa], mid+1, r, k-lcnt) + lsum;
}

int fa[N][20], dep[N];
void dfs(int x,int fat){
	fa[x][0] = fat, dep[x] = dep[fat] + 1;
	for(int i=1;i<=t;++i)
		fa[x][i] = fa[fa[x][i-1]][i-1];
	for(int i=0;i<g[x].size();++i){
		int y = g[x][i].fi, z = g[x][i].se;
		if(y == fat)	continue;
		int lst = x;
		for(int v:chk[z])	update(root[y], root[lst], 1, MAXN, v), lst = y;
		if(!chk[z].size())	root[y] = root[x];
		dfs(y, x);
	}
}

int LCA(int x,int y){
	if(dep[x] < dep[y])	swap(x, y);
	for(int i=t;i>=0;--i)
		if(dep[fa[x][i]] >= dep[y])	x = fa[x][i];
	if(x == y)	return x;
	for(int i=t;i>=0;--i)
		if(fa[x][i] != fa[y][i])	x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

signed main(){
//	freopen("01-01.in","r",stdin);
//	freopen("P9329.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>q; t = log(n)/log(2);
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, g[x].pb(mk(y, i)), g[y].pb(mk(x, i));
	for(int i=1,x,y;i<=m;++i)	cin>>x>>y, chk[x].pb(y);
	dfs(1, 0);
//	for(int i=1;i<=n;++i)
//		cout<<cnt[ls[root[i]]]<<" "<<sum[ls[root[i]]]<<endl;
	while(q--){
		int x, y, u, v;
		cin>>u>>v>>x>>y; int lca = LCA(u, v);
		int tmp = cnt[root[u]] + cnt[root[v]] - 2*cnt[root[lca]];
//		cout<<u<<" "<<v<<" "<<lca<<" "<<tmp<<endl;
		int l = 0, r = tmp;
		while(l<r){
			int mid = l+r+1>>1;
//			cout<<"###"<<mid<<" "<<query(root[u], root[v], root[lca], 1, MAXN, mid)<<"###"<<endl;
			if(query(root[u], root[v], root[lca], 1, MAXN, mid) <= y)	l = mid;
			else	r = mid-1;
		}
//		cout<<l<<endl;
		if(x-(tmp-l)<0)	cout<<-1<<endl;
		else	cout<<x-(tmp-l)<<endl;
	}
	return 0;
}

