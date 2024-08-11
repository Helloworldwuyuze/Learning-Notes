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
#define endl '\n'

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

int n, dep[N], mx[N], fa[N], son[N];
vector<int> v[N];
long long *f[N], *g[N], p[N<<2], *o = p, ans;

void dfs(int x,int fat){
	dep[x] = dep[fat] + 1, mx[x] = 1, fa[x] = fat;
	for(int y:v[x])
		if(y!=fat){
			dfs(y, x);
			if(mx[y]>mx[son[x]])	son[x] = y;
		}
	mx[x] = mx[son[x]] + 1;
}
void solve(int x){
	if(son[x])	f[son[x]] = f[x] + 1, g[son[x]] = g[x] - 1, solve(son[x]);
	f[x][0] = 1, ans += g[x][0];
	for(int y:v[x])
		if(y!=son[x]&&y!=fa[x]){
			f[y] = o, o += mx[y]<<1, g[y] = o, o += mx[y]<<1;
			solve(y);
			for(int i=0;i<mx[y];++i){
				if(i)	ans += f[x][i-1] * g[y][i];
				ans += f[y][i] * g[x][i+1];
			}
			for(int i=0;i<mx[y];++i){
				g[x][i+1] += f[x][i+1] * f[y][i];
				if(i)	g[x][i-1] += g[y][i];
				f[x][i+1] += f[y][i];
			}
		}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i = 1, x, y ; i<n; ++i)	cin>>x>>y, v[x].pb(y), v[y].pb(x);
	dfs(1, 0); f[1] = o, o += mx[1]<<1, g[1] = o, o += mx[1]<<1;
	solve(1);
	cout<<ans<<endl;
	return 0;
}