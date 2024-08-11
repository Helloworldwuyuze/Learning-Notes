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
const int N = 5e4 + 10;
const int M = 5e2 + 10;
const int MOD = 201314;

int n, m, fa[N];
vector<int> g[N];

struct seg{
	int sum[N<<2], tag[N<<2];
	void push_up(int p){ sum[p] = sum[p<<1] + sum[p<<1|1];}
	void push_down(int p,int l,int r){
		if(!tag[p]) return;
		int mid = l+r>>1;
		tag[p<<1] += tag[p], tag[p<<1|1] += tag[p];
		sum[p<<1] += tag[p] * (mid-l+1), sum[p<<1|1] += tag[p] * (r-mid);
		tag[p]=0;
	}
	void update(int p,int l,int r,int left,int right,int k){
		if(left<=l&&r<=right){ tag[p]+=k, sum[p]+=(r-l+1)*k; return ;}
		int mid = l+r>>1;
		push_down(p,l,r);
		if(left<=mid)	update(p<<1, l, mid, left, right, k);
		if(right>mid)	update(p<<1|1, mid+1, r, left, right, k);
		push_up(p);
	}
	int query(int p,int l,int r,int left,int right){
		if(left<=l&&r<=right)	return sum[p];
		int mid = l+r>>1, res=0;
		push_down(p,l,r);
		if(left<=mid)	res+=query(p<<1, l, mid, left, right);
		if(right>mid)	res+=query(p<<1|1, mid+1, r, left, right);
		return res;
	}
}s;

struct ques{
	int id, l, x, f;
	bool operator <(const ques &other) const{ return l<other.l;}
}q[N<<1];
int cnt;
int ans[N];

namespace cut{
	int dfn[N], rk[N], idx, top[N], siz[N], dep[N], son[N];
	void dfs1(int x){
		siz[x] = 1, dep[x] = dep[fa[x]] + 1;
		for(int y:g[x])
			if(y!=fa[x]){
				dfs1(y);
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
	void update(int x,int y){
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]])	swap(x,y);
			// cout<<"CUT::UPDATE::"<<top[x]<<" "<<x<<endl;
			s.update(1, 1, n, dfn[top[x]], dfn[x], 1);
			x = fa[top[x]];
		}
		if(dep[x]<dep[y])	swap(x,y);
		// cout<<"CUT::UPDATE::"<<y<<" "<<x<<endl;
		s.update(1, 1, n, dfn[y], dfn[x], 1);
	}
	int query(int x,int y){
		int ans=0;
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]])	swap(x,y);
			// cout<<"CUT::QUERY::"<<top[x]<<" "<<x<<" "<<s.query(1, 1, n, dfn[top[x]], dfn[x])<<endl;
			ans += s.query(1, 1, n, dfn[top[x]], dfn[x]);
			x = fa[top[x]];
		}
		if(dep[x]<dep[y])	swap(x,y);
		// cout<<"CUT::QUERY::"<<y<<" "<<x<<" "<<s.query(1, 1, n, dfn[y], dfn[x])<<endl;
		return ans + s.query(1, 1, n, dfn[y], dfn[x]);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=2;i<=n;++i)   cin>>fa[i], ++fa[i], g[i].pb(fa[i]), g[fa[i]].pb(i);
	for(int i=1,l,r,z;i<=m;++i)	cin>>l>>r>>z, ++l, ++r, ++z, q[++cnt] = {i, l-1, z, -1}, q[++cnt] = {i, r, z, 1};
	sort(q+1,q+1+cnt);
	int j=1;
	while(q[j].l==0&&j<=cnt)	++j;
	cut::dfs1(1), cut::dfs2(1,1);
	for(int i=1;i<=n;++i){
		// cout<<"###"<<i<<"###"<<endl;
		cut::update(1, i);
		while(q[j].l==i&&j<=cnt)	ans[q[j].id] += cut::query(1, q[j].x) * q[j].f, ++j;
	}
	for(int i=1;i<=m;++i)	cout<<ans[i]%MOD<<endl;
	return 0;
}