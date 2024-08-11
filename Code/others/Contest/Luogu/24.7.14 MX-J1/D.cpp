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
const int N = 2e5 + 10;
const int M = 1e6 + 10;
const int MAXN = 1e9;

int n, m, k;
struct redseg{
	int l, r, val;
}rs[N];
struct blueseg{
	int l, r;
}bs[N];
int b[N<<2], cnt, flag[N], f[N], pre[N];

int sum[N<<5], lson[N<<5], rson[N<<5], idx, root;
void update(int &p,int l,int r,int left,int right,int k){
	if(!p)	p = ++idx;
	if(left<=l&&r<=right)	return (void)(sum[p] += (r-l+1) * k);
	int mid = l+r>>1;
	if(left<=mid)	update(lson[p], l, mid, left, right, k);
	if(right>mid)	update(rson[p], mid+1, r, left, right, k);
	sum[p] = sum[p<<1] + sum[p<<1|1];
}
int query(int p,int l,int r,int left,int right){
	if(!p)	return 0;
	if(left<=l && r<=right)	return sum[p];
	int mid = l+r>>1, res = 0;
	if(left <= mid)	res += query(lson[p], l, mid, left, right);
	if(right > mid)	res += query(rson[p], mid+1, r, left, right);
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)	cin>>rs[i].l>>rs[i].r>>rs[i].val, b[++cnt] = rs[i].l, b[++cnt] = rs[i].r;
	for(int i=1;i<=m;++i)	cin>>bs[i].l>>bs[i].r, b[++cnt] = bs[i].l, b[++cnt] = bs[i].r;
	sort(b+1, b+1+cnt);
	cnt = unique(b+1, b+1+cnt) - b - 1;
	for(int i=1;i<=n;++i){
		update(root, 1, MAXN, rs[i].l, rs[i].r, 1);
		rs[i].l = lower_bound(b+1, b+1+cnt, rs[i].l) - b;
		rs[i].r = lower_bound(b+1, b+1+cnt, rs[i].r) - b;
		// cout<<rs[i].l<<" "<<rs[i].r<<endl;
	}
	for(int i=1;i<=m;++i){
		bs[i].l = lower_bound(b+1, b+1+cnt, bs[i].l) - b;
		bs[i].r = lower_bound(b+1, b+1+cnt, bs[i].r) - b;
	}
	for(int i=1;i<=n;++i)
		for(int j=rs[i].l;j<=rs[i].r;++j)	flag[j] = i;
	for(int i=1;i<=m;++i){
		for(int j=1;j<i;++j){
			if(flag[bs[i].l] == flag[bs[j].r])	continue;
			f[i] = max(f[i], f[j]);
		}
		f[i] += query(root, 1, MAXN, b[bs[i].l], b[bs[i].r]);
		cout<<f[i]<<endl;
	}
	int maxx = 0;
	for(int i=1;i<=m;++i)	maxx = max(maxx, f[i]);
	cout<<maxx<<endl;
	return 0;
}