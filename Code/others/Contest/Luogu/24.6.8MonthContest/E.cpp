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
const int N = 5e3 + 10;
const int M = 3e5 + 10;

long long n,m,x,w,y;
int fa[M];

namespace SUB1{
	vector<int> g[N];
	int ls[N*N], rs[N*N], root[N], idx;
	int dep[N], mx;
	long long maxx[N*N];
	void push_up(int p){
		maxx[p]=max(maxx[ls[p]], maxx[rs[p]]);
	}
	void update(int &p,int l,int r,int x,int k){
		if(!p)	p=++idx;
		if(l==r){ maxx[p]+=k; return;}
		int mid=l+r>>1;
		if(x<=mid)	update(ls[p], l, mid, x, k);
		else	update(rs[p], mid+1, r, x, k);
		push_up(p);
	}
	void dfs(int x){
		dep[x]=dep[fa[x]]+1, mx=max(mx, dep[x]);
		for(int y:g[x])
			if(y!=fa[x])	dfs(y);
	}
	long long DFS(int x){
		long long ans=maxx[root[x]];
		// cout<<x<<" "<<maxx[root[x]]<<endl;
		for(int y:g[x])
			if(y!=fa[x])	ans+=DFS(y);
		return ans;
	}
}
namespace SUB2{
	#define int long long
	int a[M];
	int maxx[M<<2], tag[M<<2], s[M<<2];
	void push_down(int p,int l,int r){
		if(!tag[p])	return ;
		int mid = l+r>>1;
		maxx[p<<1] = maxx[p<<1|1] = tag[p], s[p<<1] = (mid-l+1)*tag[p], s[p<<1|1] = (r-mid)*tag[p];
		tag[p<<1] = tag[p<<1|1] = tag[p];
		tag[p]=0;
	}
	void push_up(int p){
		maxx[p]=max(maxx[p<<1], maxx[p<<1|1]);
		s[p] = s[p<<1] + s[p<<1|1];
	}
	void update(int p,int l,int r,int left,int right,int k){
		if(left<=l&&r<=right){ s[p] = k*(r-l+1), maxx[p] = tag[p] = k; return ;}
		int mid=l+r>>1;
		push_down(p,l,r);
		if(left<=mid)	update(p<<1, l, mid, left, right, k);
		if(right>mid)	update(p<<1|1, mid+1, r, left, right, k);
		push_up(p);
	}
	int query(int p,int l,int r,int left,int right){
		if(left<=l&&r<=right)	return s[p];
		push_down(p,l,r);
		int mid=l+r>>1, res=0;
		if(left<=mid)	res+=query(p<<1, l, mid, left, right);
		if(right>mid)	res+=query(p<<1|1, mid+1, r, left, right);
		return res;
	}
	int querym(int p,int l,int r,int left, int right){
		if(left<=l&&r<=right)	return maxx[p];
		push_down(p,l,r);
		int mid=l+r>>1, res=0;
		if(left<=mid)	res=max(res, querym(p<<1, l, mid, left, right));
		if(right>mid)	res=max(res, querym(p<<1|1, mid+1, r, left, right));
		return res;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	if(n<=5000&&m<=5000){
		using namespace SUB1;
		for(int i=2;i<=n;++i)	cin>>fa[i], g[fa[i]].pb(i), g[i].pb(fa[i]);
		dfs(1);
		while(m--){
			cin>>x>>w>>y; int xx=x;
			while(x)	update(root[x], dep[x], mx, dep[xx], w), x=fa[x];
			cout<<DFS(y)<<endl;
		}
	}else{
		using namespace SUB2;
		for(int i=2;i<=n;++i)	cin>>fa[i];
		while(m--){
			cin>>x>>w>>y; a[x]+=w;
			int l=1, r=x;
			while(l<r){
				int mid=l+r>>1;
				if(querym(1, 1, n, mid, x)<a[x])	r=mid;
				else	l=mid+1;
			}
			// for(int i=1;i<=n;++i)	cout<<a[i]<<" ";
			// cout<<endl;
			if(querym(1,1,n,x,x)<a[x])	update(1, 1, n, l, x, a[x]);
			cout<<query(1, 1, n, y, n)<<endl;
		}
	}
	return 0;
}