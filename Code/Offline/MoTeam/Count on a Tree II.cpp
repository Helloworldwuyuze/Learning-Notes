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
// #define endl '\n'

#define pi acos(-1)
#define eps (1e-8)
#define null nullptr

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef unsigned int ui;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n, m, a[N], x[N], y[N], nn, sum, ans[N], b[N], col[N];
bool appear[N];
struct node{
	int l, r, id, x, y;
	bool operator <(const node &other) const{
		if(l/nn == other.l/nn)  return (l/nn%2)?r>other.r:r<other.r;
		return l/nn < other.l/nn;
	}
}range[N];
vector<int> g[N];
int fa[N][20], st[N], top, t, in[N], out[N], dep[N];

void dfs(int x,int fat){
	fa[x][0] = fat; st[++top] = x, in[x] = top;
	dep[x] = dep[fat] + 1;
	for(int i=1;i<=t;++i)   fa[x][i] = fa[fa[x][i-1]][i-1];
	for(int y:g[x])
		if(y!=fat)  dfs(y, x);
	st[++top] = x, out[x] = top;
}

void add(int x){
	if(appear[x] ^= 1)	sum += ((++col[a[x]]) == 1);
	else	sum -= ((--col[a[x]]) == 0);
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
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m; nn = sqrt(2*n), t = log2(n)+0.5;
	for(int i=1;i<=n;++i)   cin>>a[i], b[i] = a[i];
	sort(b+1, b+1+n);
	int cnt = unique(b+1, b+1+n) - b - 1;
	for(int i=1;i<=n;++i)   a[i] = lower_bound(b+1, b+1+cnt, a[i]) - b;
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	dfs(1, 0);
	for(int i=1;i<=m;++i){
		cin>>x[i]>>y[i];
		if(in[x[i]] > in[y[i]])	swap(x[i], y[i]);
		if(out[x[i]] >= out[y[i]])	range[i] = node{ in[x[i]], in[y[i]], i, x[i], y[i]};
		else	range[i] = node{ out[x[i]], in[y[i]], i, x[i], y[i]};
	}
	// for(int i=1;i<=m;++i)
	// 	cout<<range[i].id<<" "<<range[i].l<<" "<<range[i].r<<endl;
	sort(range+1, range+1+m);
	int l = 1, r = 0;
	for(int i=1;i<=m;++i){
		while(r<range[i].r)	add(st[++r]);
		while(l>range[i].l)	add(st[--l]);
		while(r>range[i].r)	add(st[r--]);
		while(l<range[i].l)	add(st[l++]);
		int lca = LCA(range[i].x, range[i].y);
		// cout<<range[i].id<<" "<<range[i].x<<" "<<range[i].y<<" "<<range[i].l<<" "<<range[i].r<<" "<<l<<" "<<r<<" "<<sum<<" "<<lca<<" "<<(col[a[lca]]==0)<<endl;
		// for(int i=1;i<=n<<1;++i)	cout<<appear[i]<<" ";
		// cout<<endl;
		if(lca != range[i].x && lca != range[i].y)	ans[range[i].id] = sum + (col[a[lca]] == 0);
		else	ans[range[i].id] = sum;
	}
	for(int i=1;i<=m;++i)	cout<<ans[i]<<endl;
	return 0;
}//