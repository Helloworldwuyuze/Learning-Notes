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
int siz[N], son[N], top[N], fa[N], dep[N], dfn[N], rk[N], idx;

namespace seg{
	int sum[N<<2], tag[N<<2];
	void push_up(int p){ sum[p] = sum[p<<1] + sum[p<<1|1];}
	void push_down(int p, int l, int r){
		if(!tag[p])	return ;
		int mid = l+r>>1;
		tag[p<<1] += tag[p], tag[p<<1|1] += tag[p];
		sum[p<<1] += tag[p] * (mid-l+1), sum[p<<1|1] += tag[p] * (r-mid);
		tag[p]=0;
	}
	void update(int p,int l,int r,int left,int right,int k){
		if(left<=l&&r<=right){ tag[p]+=k, sum[p]+=k*(r-l+1); return ;}
		push_down(p, l, r);
		int mid = l+r>>1;
		if(left<=mid)	update(p<<1, l, mid, left, right, k);
		if(right>mid)	update(p<<1|1, mid+1, r, left, right, k);
		push_up(p);
	}
	int query(int p,int l,int r,int left,int right){
		if(left<=l&&r<=right)	return sum[p];
		push_down(p, l, r);
		int mid = l+r>>1, res = 0;
		if(left<=mid)	res += query(p<<1, l, mid, left, right);
		if(right>mid)	res += query(p<<1|1, mid+1, r, left, right);
		return res;
	}
}

void dfs1(int x,int fat){
	fa[x] = fat; siz[x] = 1, dep[x] = dep[fat] + 1;
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
		if(y!=fa[x]&&y!=son[x])	dfs2(y, y);
}
void modify(int x,int y,int k){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		// cout<<dfn[top[x]]<<" "<<dfn[x]<<endl;
		seg::update(1, 1, n, dfn[top[x]], dfn[x], k);
		x = fa[top[x]];
	}
	if(dep[x]<dep[y])	swap(x,y);
	// cout<<dfn[y]<<" "<<dfn[x]<<endl;
	seg::update(1, 1, n, dfn[y], dfn[x], k);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n; t=log(n)/log(2);
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, ++x, ++y, g[x].pb(y), g[y].pb(x);
	dfs1(1,0), dfs2(1,1);
	// for(int i=1;i<=n;++i)
	// 	cout<<i<<" "<<dfn[i]<<" "<<siz[i]<<" "<<top[i]<<endl;
	cin>>m;
	while(m--){
		char op; int x, y, z;
		cin>>op>>x; ++x;
		if(op=='A')	cin>>y>>z, ++y, modify(x, y, z);
		else	cout<<seg::query(1, 1, n, dfn[x], dfn[x] + siz[x] - 1)<<endl;
		// for(int i=1;i<=n<<1;++i)
		// 	cout<<i<<" "<<seg::sum[i]<<" "<<seg::tag[i]<<endl;
	}
	return 0;
}