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

int T, n, m, q, t;
vector<int> g[N], v[N];
int tot, a[N];

int dfn[N], low[N], idx, cnt, st[N], top, dep[N], rk[N];
int fa[N][20], dis[N];
void Tarjan(int x){
	dfn[x] = low[x] = ++idx;
	st[++top] = x;
	for(int y:g[x])
		if(!dfn[y]){
			Tarjan(y);
			low[x] = min(low[x], low[y]);
			if(low[y] == dfn[x]){
				v[(++cnt)+n].pb(x), v[x].pb(cnt+n);
				while(st[top+1] != y)	v[st[top]].pb(cnt+n), v[cnt+n].pb(st[top--]);
			}
		}else	low[x] = min(low[x], dfn[y]);
}
void dfs(int x,int fat){
	dfn[x] = ++idx, rk[idx] = x, dep[x] = dep[fat]+1;
	fa[x][0] = fat; dis[x] = dis[fat] + (fat>n);
	for(int i=1;i<=t;++i)
		fa[x][i] = fa[fa[x][i-1]][i-1];
	for(int y:v[x])
		if(y!=fat)	dfs(y, x);
}

bool cmp(int x,int y){
	return dfn[x] < dfn[y];
}
int LCA(int x,int y){
	if(dep[x] < dep[y])	swap(x,y);
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
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1,x,y;i<=m;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
		Tarjan(1); t = log(n+cnt)/log(2);
		// for(int i=1;i<=cnt+n;++i,cout<<endl)
		// 	for(int j:v[i])	cout<<j<<" ";
		idx = 0; dfs(1, 0);
		// for(int i=1;i<=cnt+n;++i)
		// 	cout<<dfn[i]<<" "<<dep[i]<<" "<<fa[i][0]<<" "<<dis[i]<<endl;
		cin>>q;
		while(q--){
			cin>>tot;
			for(int i=1;i<=tot;++i)	cin>>a[i];
			int ans = 0;
			sort(a+1, a+1+tot, cmp);
			for(int i=1;i<=tot;++i){
				int x = a[i], y = a[i%tot+1];
				int l = LCA(x, y);
				ans += dis[x] + dis[y] - 2*dis[l];
				// cout<<x<<" "<<y<<" "<<l<<" "<<ans<<endl;
			}
			cout<<ans/2+(LCA(a[1],a[tot])<=n)-tot<<endl;
		}
		for(int i=1;i<=cnt+n;++i)	v[i].clear();
		for(int i=1;i<=n;++i)	g[i].clear();
		for(int i=1;i<=n;++i)	st[i] = 0;
		for(int i=1;i<=cnt+n;++i){
			dis[i] = dfn[i] = low[i] = rk[i] = dep[i] = 0;
			for(int j=0;j<=t;++j)	fa[i][j] = 0;
		}
		idx = top = cnt = tot = 0;
	}
	return 0;
}