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
// #define endl '\n'

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 3e2 + 10;
const int MOD = 1e9 + 7;

int n,q,m,k,r;
int a[N], s[N], f[N][M];
vector<int> g[N];

namespace BIT{
	int b[N];
	#define lowbit(x) (x&-x)
	void update(int x,int k){ for(int i=x;i<=n;i+=lowbit(i))	b[i]+=k;}
	int query(int x){ int ans=0; for(int i=x;i;i-=lowbit(i))	ans+=b[i]; return ans;}
	#undef lowbit
}

namespace cut{
	int dfn[N], rk[N], top[N], siz[N], son[N], dep[N], fa[N], idx;
	void dfs1(int x,int fat){
		fa[x] = fat, siz[x] = 1, dep[x] = dep[fat]+1;
		for(int y:g[x]){
			if(y==fat)	continue;
			dfs1(y,x);
			siz[x]+=siz[y];
			if(siz[y]>siz[son[x]])	son[x]=y;
		}
	}
	void dfs2(int x,int tp){
		top[x] = tp, dfn[x] = ++idx, rk[idx] = x;
		if(son[x])	dfs2(son[x], tp);
		for(int y:g[x])
			if(y!=son[x] && y!=fa[x])	dfs2(y, y);
	}
	int query(int x,int y){
		int ans = 0;
		while(top[x] != top[y]){
			if(dep[top[x]]<dep[top[y]])	swap(x,y);
			// cout<<x<<" "<<y<<" "<<top[x]<<endl;
			ans += BIT::query(dfn[x]) - BIT::query(dfn[top[x]]-1);
			x = fa[top[x]];
		}
		if(dep[x]<dep[y])	swap(x,y);
		// cout<<x<<" "<<y<<endl;
		return ans + BIT::query(dfn[x]) - BIT::query(dfn[y]-1);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>q;
	for(int i=2, x, y; i<=n; ++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	cut::dfs1(1, 0), cut::dfs2(1, 1);
	while(q--){
		cin>>k>>m>>r;
		for(int i=1;i<=k;++i)	cin>>a[i], BIT::update(cut::dfn[a[i]], 1);
		for(int i=1;i<=k;++i)	s[i] = cut::query(a[i], r) - 1;
		// for(int i=1;i<=k;++i)	cout<<s[i]<<" ";
		// cout<<endl;
		sort(s+1, s+1+k);
		f[1][1] = 1;
		for(int i = 2; i<=k; ++i)
			for(int j = 1, _end = min(i, m); j<=_end; ++j)
				f[i][j] = (max(j-s[i], 0ll) * f[i-1][j] % MOD + f[i-1][j-1]) % MOD;
		int ans = 0;
		for(int i=1;i<=m;++i)	ans = (ans + f[k][i]) % MOD;
		cout<<ans<<endl;
		for(int i=1;i<=k;++i)	BIT::update(cut::dfn[a[i]], -1);
	}
	return 0;
}