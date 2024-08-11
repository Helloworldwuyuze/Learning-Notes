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
typedef unsigned int ui;
const int N = 5e5 + 10;
const int M = 1e6 + 10;

ui seed;
int n, q, fa[N][20], root, x, lst, k, dep[N], top[N], mx[N], son[N], t;
long long ans;
vector<int> g[N], fd[N], sd[N];

ui get(ui x){
	x ^= x << 13; x ^= x >> 17; x ^= x << 5;
	return seed = x; 
}

void dfs1(int x){
	dep[x] = dep[fa[x][0]] + 1, mx[x] = 1;
	for(int i=1;i<=t;++i)
		fa[x][i] = fa[fa[x][i-1]][i-1];
	for(int y:g[x]){
		if(y==fa[x][0])	continue;
		dfs1(y);
		if(mx[y]>mx[son[x]])	son[x] = y;
	}
	mx[x] = mx[son[x]] + 1;
}
void dfs2(int x, int tp){
	top[x] = tp;
	if(x==tp){
		for(int i = 1, xx = x; i<=mx[x]; ++i, xx = fa[xx][0]) fd[x].pb(xx);
		for(int i = 1, xx = x; i<=mx[x]; ++i, xx = son[xx])	sd[x].pb(xx);
	}
	if(son[x])	dfs2(son[x], tp);
	for(int y:g[x])
		if(y!=fa[x][0]&&y!=son[x])	dfs2(y, y);
}
int query(int x,int k){
	if(k==0)	return x;
	int tt = log(k) / log(2);
	x = fa[x][tt], k -= (1<<tt);
	int up = dep[x] - dep[top[x]];
	x = top[x], k-=up;
	if(k<0)	return sd[x][-k];
	else	return fd[x][k];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>q>>seed; t = log(n) / log(2);
	for(int i=1; i<=n; ++i){
		cin>>fa[i][0];
		if(fa[i][0]==0)	root = i;
		g[i].pb(fa[i][0]), g[fa[i][0]].pb(i);
	}
	dfs1(root), dfs2(root, root);
	for(int i=1; i<=q; ++i){
		int x = (get(seed) ^ lst) % n + 1, k = (get(seed) ^ lst) % dep[x];
		lst = query(x, k);
		ans ^= 1ll * i * lst;
	}
	cout<<ans<<endl;
	return 0;
}