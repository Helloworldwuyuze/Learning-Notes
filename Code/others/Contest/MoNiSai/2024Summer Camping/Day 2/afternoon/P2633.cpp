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
const int MAXN = (1ll<<31)-1;

int n, m, a[N], t, q;
vector<int> g[N];

int root[N], idx, ls[N<<5], rs[N<<5], s[N<<5], fa[N][20], dep[N], lst;

void update(int &p,int q,int l,int r,int x,int k){
	p = ++idx;
	ls[p] = ls[q], rs[p] = rs[q], s[p] = s[q];
	if(l == r)	return (void)(s[p] += k);
	int mid = l+r>>1;
//	cout<<"UPDATE! "<<p<<" "<<q<<" "<<l<<" "<<r<<" "<<x<<" "<<k<<endl;
	if(x<=mid)	update(ls[p], ls[q], l, mid, x, k);
	else	update(rs[p], rs[q], mid+1, r, x, k);
	s[p] = s[ls[p]] + s[rs[p]];
}

int kth(int u,int v,int fa,int ffa,int l,int r,int k){
	int lsum = s[ls[u]] + s[ls[v]] - s[ls[fa]] - s[ls[ffa]];
	if(l == r)	return l;
	int mid = l+r>>1;
//	cout<<"KTH! "<<u<<" "<<v<<" "<<fa<<" "<<ffa<<" "<<l<<" "<<r<<" "<<k<<" "<<mid<<" "<<s[ls[u]]<<" "<<s[ls[v]]<<" "<<s[ls[fa]]<<" "<<s[ls[ffa]]<<" "<<s[ls[u]]<<" "<<s[ls[v]]<<" "<<s[ls[fa]]<<" "<<s[ls[ffa]]<<endl;
	if(lsum >= k)	return kth(ls[u], ls[v], ls[fa], ls[ffa], l, mid, k);
	else	return kth(rs[u], rs[v], rs[fa], rs[ffa], mid+1, r, k-lsum);
}

void dfs(int x,int fat){
	update(root[x], root[fat], 1, MAXN, a[x], 1);
	fa[x][0] = fat, dep[x] = dep[fat]+1;
	for(int i=1;i<=t;++i)
		fa[x][i] = fa[fa[x][i-1]][i-1];
	for(int i=0;i<g[x].size();++i)
		if(g[x][i] != fat)	dfs(g[x][i], x);
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

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m; t = log(n)/log(2);
	for(int i=1;i<=n;++i)	cin>>a[i];
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	dfs(1, 0);
//	for(int i=1;i<=n;++i)	cout<<root[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=idx;++i)
//		cout<<i<<" "<<ls[i]<<" "<<rs[i]<<" "<<s[i]<<endl;
	while(m--){
		int u, v, k;
		cin>>u>>v>>k; u^=lst;
		int l = lca(u, v);
//		cout<<"LCA! "<<l<<endl;
		lst = kth(root[u], root[v], root[l], root[fa[l][0]], 1, MAXN, k);
		cout<<lst<<endl;
	}
	return 0;
}
