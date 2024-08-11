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

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 2e5 + 10;

int n, t, m;
vector<int> g[N];
int siz[N], son[N], top[N], fa[N][20], dep[N], dfn[N], rk[N], idx;
bool tag[N];

int b[N];
#define lowbit(x) (x&-x)
void update(int x,int k){ for(int i=x;i<=n;i+=lowbit(i))    b[i]+=k;}
int query(int x){ int ans = 0; for(int i=x;i;i-=lowbit(i))  ans+=b[i]; return ans;}

void dfs1(int x,int fat){
	fa[x][0] = fat; siz[x] = 1, dep[x] = dep[fat] + 1;
	for(int i=1;i<=t;++i)	fa[x][i] = fa[fa[x][i-1]][i-1];
	for(int y:g[x])
		if(y!=fat){
			dfs1(y, x);
			siz[x] += siz[y];
			if(siz[y]>siz[son[x]])	son[x] = y;
		}
}
void dfs2(int x,int tp){
	top[x] = tp, dfn[x] = ++idx, rk[idx] = x;
	if(son[x])	dfs2(son[x], tp);
	for(int y:g[x])
		if(y!=fa[x][0]&&y!=son[x])	dfs2(y, y);
}
int que(int x,int y){
	// cout<<"QUEFRONT::"<<x<<" "<<y<<endl;
	int ans = 0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])	swap(x,y);
		ans += query(dfn[x]) - query(dfn[top[x]]-1);
		x=fa[top[x]][0];
	}
	if(dep[x] < dep[y])	swap(x,y);
	// cout<<"QUE::"<<x<<" "<<y<<endl;
	return ans + query(dfn[x]) - query(dfn[y]-1);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m; t=log(n)/log(2);
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	dfs1(1,0), dfs2(1,1);
	// for(int i=1;i<=n;++i)
	// 	cout<<i<<" "<<dfn[i]<<" "<<top[i]<<endl;
	update(dfn[1], 1); tag[1] = true;
	while(m--){
		char op; int x;
		cin>>op>>x;
		if(op=='C')	update(dfn[x], 1), tag[x] = true;
		else{
			int xx = x, s = que(xx, 1);
			// cout<<s<<" ";
			if(tag[x]){ cout<<x<<endl; continue;}
			for(int i=t;i>=0;--i)
				if(fa[xx][i] && que(fa[xx][i], 1) == s)	xx = fa[xx][i];
			cout<<xx<<endl;
		}
	}
	return 0;
}