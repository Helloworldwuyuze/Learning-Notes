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
const int N = 5e5 + 10;
const int M = 2e6 + 10;
const int MOD = 1e9 + 7;

int n, m, base[M], ans;
vector<int> g[N], v[N];

int cnt, dfn[N], idx, low[N], st[N], top, bl[N];
vector<int> mem[N];
void Tarjan(int x,int fa){
	st[++top] = x;
	dfn[x] = low[x] = ++idx;
	for(int y:g[x])
		if(!dfn[y]) Tarjan(y,x), low[x] = min(low[x], low[y]);
		else if(y != fa)	low[x] = min(low[x], dfn[y]);
	if(dfn[x] == low[x]){
		++cnt;
		while(st[top+1] != x)	mem[cnt].pb(st[top]), bl[st[top--]] = cnt;
	}
}

int e[N], s[N], V[N], f[N][2];
void dfs(int x,int fa){
	s[x] = e[x];
	// cout<<x<<" "<<s[x]<<endl;
	for(int y:v[x])
		if(y != fa)	dfs(y, x), s[x] += s[y] + 1;
}
void solve(int x,int fa){
	for(int y:v[x])
		if(y != fa){
			solve(y, x);
			f[x][1] = (f[x][0] * f[y][1] %MOD + f[x][1] * (f[y][0]*2+f[y][1]) %MOD) %MOD;
			f[x][0] = f[x][0] * f[y][0]*2 %MOD;
		}
	if(x == 1)	ans += f[1][1];
	else	ans += f[x][1]*base[s[1]-s[x]-1];
	ans %= MOD;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	base[0] = 1;
	for(int i=1;i<=M-10;++i)	base[i] = base[i-1]*2%MOD;
	cin>>n>>m;
	for(int i=1,x,y;i<=m;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	Tarjan(1,0);
	// for(int i=1;i<=cnt;++i,cout<<endl)
		// for(int x:mem[i])	cout<<x<<" ";
	for(int x=1;x<=n;++x)
		for(int y:g[x])
			if(bl[x] != bl[y])	v[bl[x]].pb(bl[y]);
			else	e[bl[x]] ++;
	for(int i=1;i<=cnt;++i)	V[i] = mem[i].size();
	for(int i=1;i<=cnt;++i)	e[i] >>= 1, f[i][0] = base[e[i]], f[i][1] = (base[e[i]+V[i]]-base[e[i]]+MOD)%MOD;
	// for(int i=1;i<=cnt;++i)
	// 	cout<<e[i]<<" "<<V[i]<<" "<<s[i]<<" "<<f[i][0]<<" "<<f[i][1]<<endl;
	dfs(1, 0);
	// for(int i=1;i<=cnt;++i)
	// 	cout<<e[i]<<" "<<V[i]<<" "<<s[i]<<" "<<f[i][0]<<" "<<f[i][1]<<endl;
	solve(1, 0);
	// for(int i=1;i<=cnt;++i)
	// 	cout<<e[i]<<" "<<V[i]<<" "<<s[i]<<" "<<f[i][0]<<" "<<f[i][1]<<endl;
	cout<<ans<<endl;
	return 0;
}