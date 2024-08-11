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
const int N = 2e5 + 10;
const int M = 1e6 + 10;

int n, m;
vector<int> g[N];
int dfn[N], low[N], idx, cnt, st[N], top, val[N], tot;
vector<int> scc[N], v[N];

void Tarjan(int x){
	low[x] = dfn[x] = ++idx; ++tot;
	st[++top] = x;
	for(int y:g[x])
		if(!dfn[y]){
			Tarjan(y);
			low[x] = min(low[x], low[y]);
			if(low[y] == dfn[x]){
				scc[++cnt].pb(x);
				while(st[top+1] != y)	scc[cnt].pb(st[top--]);
				for(int z:scc[cnt])
					v[cnt+n].pb(z), v[z].pb(cnt+n), val[z] = -1;
				val[cnt+n] = scc[cnt].size();
			}
		}else	low[x] = min(low[x], dfn[y]);
}

int siz[N], ans;

void dfs(int x,int fa){
	siz[x] = (x<=n);
	for(int y:v[x]){
		if(y == fa)	continue;
		dfs(y, x);
		ans += 2 * val[x] * siz[x] * siz[y];
		siz[x] += siz[y];
	}
	ans += 2 * val[x] * siz[x] * (tot - siz[x]);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1,x,y;i<=m;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	for(int i=1;i<=n;++i)
		if(!dfn[i]){
			tot = 0;
			Tarjan(i);
			dfs(i, 0);
		}
	cout<<ans<<endl;
	return 0;
}