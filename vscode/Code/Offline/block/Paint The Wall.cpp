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
const int N = 1e5 + 10;
const int BLOCK = 100 + 10;
const int M = 1e6 + 10;

int n, m, a[N], b[N<<2], tot;
map<int, int> ma[BLOCK];
int blk[N], l[BLOCK], r[BLOCK], cnt, nn, tag[BLOCK];
struct opt{
	int op, l, r, x;
}op[N];

namespace seg{
	int ls[N*20], rs[N*20], maxx[N*20], root[BLOCK], idx = 0;
	void update(int &p,int l,int r,int x,int k){
		if(!p)	p = ++idx;
		if(l == r){	maxx[p] += k; return ;}
		int mid = l+r>>1;
		if(x<=mid)	update(ls[p], l, mid, x, k);
		else	update(rs[p], mid+1, r, x, k);
		maxx[p] = max(maxx[ls[p]], maxx[rs[p]]);
	}
	int query(int p,int l,int r,int x){
		if(!p)	return 0;
		if(l == r)	return maxx[p];
		int mid = l+r>>1;
		if(x<=mid)	return query(ls[p], l, mid, x);
		else	return query(rs[p], mid+1, r, x);
	}
	void clear(int p,int l,int r){
		if(!p)	return ;
		int mid = l+r>>1;
		clear(ls[p], l, mid), clear(rs[p], mid+1, r);
		maxx[p] = ls[p] = rs[p] = 0;
	}
}

void calc(int x){
	ma[x].clear();
	for(int i=l[x];i<=r[x];++i)
		++ma[x][a[i]];
}
void push_down(int x){
	if(tag[x] == -1)	return ;
	ma[x].clear();
	for(int i=l[x];i<=r[x];++i)
		a[i] = tag[x], ++ma[x][tag[x]];
	tag[x] = -1;
}

void init(){
	nn = 1000;
	for(int i=1;i<=n;++i){
		blk[i] = (i-1)/nn+1;
		l[blk[i]] = (blk[i]-1)*nn+1;
		r[blk[i]] = min(blk[i]*nn, n);
	}
	cnt = blk[n];
	for(int i=1;i<=cnt;++i)	calc(i);
}
void update(int left,int right,int x){
	int bl = blk[left], br = blk[right];
	if(bl == br){
		push_down(bl);
		for(int i=left;i<=right;++i)	a[i] = x;
		calc(bl);
		return ;
	}
	push_down(bl), push_down(br);
	for(int i=left;i<=r[bl];++i)	a[i] = x;
	for(int i=l[br];i<=right;++i)	a[i] = x;
	calc(bl), calc(br);
	for(int i=bl+1;i<br;++i)	tag[i] = x;
}
int query(int left,int right,int x){
	int bl = blk[left], br = blk[right], ans = 0;
	if(bl == br){
		push_down(bl);
		for(int i=left;i<=right;++i)	ans += a[i] == x;
		return ans;
	}
	push_down(bl), push_down(br);
	for(int i=left;i<=r[bl];++i)	ans += a[i] == x;
	for(int i=l[br];i<=right;++i)	ans += a[i] == x;
	for(int i=bl+1;i<br;++i)
		if(tag[i] != -1)	ans += (r[i]-l[i]+1)*(tag[i]==x);
		else	ans += ma[i][x];
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while(cin>>n>>m){
		memset(tag, -1, sizeof(tag));
		tot = 0;
		for(int i=1;i<=n;++i)	cin>>a[i], b[++tot] = a[i];
		init();
		for(int i=1;i<=m;++i)	cin>>op[i].op>>op[i].l>>op[i].r>>op[i].x, b[++tot]=op[i].x;
		sort(b+1, b+1+tot);
		tot = unique(b+1, b+1+tot) - b - 1;
		for(int i=1;i<=n;++i)	a[i] = lower_bound(b+1, b+1+tot, a[i]) - b;
		for(int i=1;i<=m;++i)	op[i].x = lower_bound(b+1, b+1+tot, op[i].x) - b;
		for(int i=1;i<=m;++i){
			++op[i].l, ++op[i].r;
			if(op[i].op==1)	update(op[i].l, op[i].r, op[i].x);
			else	cout<<query(op[i].l, op[i].r, op[i].x)<<endl;
		}
	}
	return 0;
}