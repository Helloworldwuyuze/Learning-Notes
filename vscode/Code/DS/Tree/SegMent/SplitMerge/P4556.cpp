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
#define null nullptr

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;

int n, m, t, M;
vector<int> g[N];
int fa[N][20], x[N], y[N], z[N], root[N], idx, maxx[N<<5], ls[N<<5], rs[N<<5], id[N<<5], dep[N];
int ans[N];

void push_up(int p){
	maxx[p] = max(maxx[ls[p]], maxx[rs[p]]);
	id[p] = maxx[ls[p]] >= maxx[rs[p]] ? id[ls[p]] : id[rs[p]];
}
void update(int &p, int l, int r, int x, int k){
	if(!p)  p = ++idx;
	// cout<<"UPDATE::"<<" "<<p<<" "<<l<<" "<<r<<" "<<x<<" "<<k<<endl;
	if(l==r)	return (void)(maxx[p] += k, id[p] = l);
	int mid = l+r>>1;
	if(x<=mid)	update(ls[p], l, mid, x, k);
	else	update(rs[p], mid+1, r, x, k);
	push_up(p);
}
int merge(int p, int q, int l, int r){
	if(!p || !q)	return p+q;
	if(l==r)	return maxx[p] += maxx[q], p;
	int mid = l+r>>1;
	ls[p] = merge(ls[p], ls[q], l, mid), rs[p] = merge(rs[p], rs[q], mid+1, r);
	return push_up(p), p;
}

void dfs(int x, int fat){
	fa[x][0] = fat; dep[x] = dep[fat] + 1;
	for(int i=1;i<=t;++i)
		fa[x][i] = fa[fa[x][i-1]][i-1];
	for(int y:g[x])
		if(y!=fa[x][0])	dfs(y, x);
}
int LCA(int x,int y){
	if(dep[x]<dep[y])	swap(x,y);
	for(int i=t;i>=0;--i)
		if(dep[fa[x][i]]>=dep[y])	x = fa[x][i];
	if(x==y)	return x;
	for(int i=t;i>=0;--i)
		if(fa[x][i] != fa[y][i])	x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
void solve(int x){
	for(int y:g[x])
		if(y!=fa[x][0])	solve(y), root[x] = merge(root[x], root[y], 1, M);
	ans[x] = maxx[root[x]] ? id[root[x]] : 0;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m; t=log(n)/log(2);
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	dfs(1, 0);
	for(int i=1;i<=m;++i)	cin>>x[i]>>y[i]>>z[i], M = max(M, z[i]);
	for(int i=1;i<=m;++i){
		int l = LCA(x[i], y[i]);
		update(root[x[i]], 1, M, z[i], 1), update(root[y[i]], 1, M, z[i], 1);
		update(root[l], 1, M, z[i], -1), update(root[fa[l][0]], 1, M, z[i], -1);
		// cout<<endl<<"###"<<i<<"###"<<endl;
		// for(int i=1;i<=n;++i)	cout<<root[i]<<" ";
		// cout<<endl;
		// for(int i=1;i<=idx;++i)
		// 	cout<<i<<" "<<maxx[i]<<" "<<id[i]<<" "<<ls[i]<<" "<<rs[i]<<endl;
	}
	solve(1);
	for(int i=1;i<=n;++i)
		cout<<ans[i]<<endl;
	return 0;
}