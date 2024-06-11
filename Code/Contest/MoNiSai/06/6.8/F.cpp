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
const int N = 1e6 + 10;
const int M = 1e6 + 10;

int n, dep[N], mx, ans[N];
vector<int> g[N];

int ls[N*21], rs[N*21], maxx[N*21], id[N*21], root[N], idx;
void push_up(int p){
	if(maxx[ls[p]]>=maxx[rs[p]])	id[p]=id[ls[p]], maxx[p]=maxx[ls[p]];
	else	id[p]=id[rs[p]], maxx[p]=maxx[rs[p]];
}
void update(int &p,int l,int r,int x,int k){
	if(!p)	p=++idx;
	if(l==r){ maxx[p]=max(maxx[p], k); id[p]=x; return ;}
	int mid=l+r>>1;
	if(x<=mid)	update(ls[p], l, mid, x, k);
	else	update(rs[p], mid+1, r, x, k);
	push_up(p);
}
PII query(int p,int l,int r,int left, int right){
	if(left<=l&&r<=right)	return mk(maxx[p], id[p]);
	int mid=l+r>>1;
	PII lson, rson;
	if(left<=mid)	lson = query(ls[p], l, mid, left, right);
	if(right>mid)	rson = query(rs[p], mid+1, r, left,right);
	if(lson.fi>=rson.fi)	return lson;
	else	return rson;
}
int merge(int p,int q,int l,int r){
	if(!p||!q)	return p+q;
	if(l==r){ maxx[p]+=maxx[q]; return p;}
	int mid=l+r>>1;
	ls[p] = merge(ls[p], ls[q], l, mid), rs[p] = merge(rs[p], rs[q], mid+1, r);
	push_up(p); return p;
}

void init(int x,int fa){
	dep[x]=dep[fa]+1; mx=max(mx, dep[x]);
	for(int y:g[x])
		if(y!=fa)	init(y,x);
}
void dfs(int x,int fa){
	update(root[x], 1, mx, dep[x], 1);
	// cout<<"###"<<x<<"###"<<endl;
	// for(int i=1;i<=idx;++i)
	// 	cout<<i<<" "<<ls[i]<<" "<<rs[i]<<" "<<maxx[i]<<" "<<id[i]<<endl;
	for(int y:g[x]){
		if(y==fa)	continue;
		dfs(y,x);
		root[x] = merge(root[x], root[y], 1, mx);
	}
	ans[x] = id[root[x]] - dep[x];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	init(1,0), dfs(1,0);
	for(int i=1;i<=n;++i)	cout<<ans[i]<<endl;
	return 0;
}