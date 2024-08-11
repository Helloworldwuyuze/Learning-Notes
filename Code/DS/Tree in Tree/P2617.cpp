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
const int M = 1e6 + 10;

int n, a[N], b[N<<1], m, cnt;
struct opt{
	char type;
	int l, r, k;
}op[N];

int root[N], s[N<<7], ls[N<<7], rs[N<<7], idx;
void update(int &p,int l,int r,int x,int k){
	if(!p)	p = ++idx;
	s[p] += k;
	if(l == r)	return ;
	int mid = l+r>>1;
	if(x <= mid)	update(ls[p], l, mid, x, k);
	else	update(rs[p], mid+1, r, x, k);
}

#define lowbit(x) (x&-x)
void modify(int x,int v,int k){
	for(int i=x;i<=n;i+=lowbit(i))
		update(root[i], 1, cnt, v, k);
}
int n1, n2, t1[N], t2[N];
int kth(int l,int r,int k){
	if(l == r)	return l;
	int sum = 0;
	for(int i=1;i<=n1;++i)	sum -= s[ls[t1[i]]];
	for(int i=1;i<=n2;++i)	sum += s[ls[t2[i]]];
	int mid = l+r>>1;
	if(sum < k){
		for(int i=1;i<=n1;++i)	t1[i] = rs[t1[i]];
		for(int i=1;i<=n2;++i)	t2[i] = rs[t2[i]];
		return kth(mid+1, r, k - sum);
	}else{
		for(int i=1;i<=n1;++i)	t1[i] = ls[t1[i]];
		for(int i=1;i<=n2;++i)	t2[i] = ls[t2[i]];
		return kth(l, mid, k);
	}
}
void init(int l,int r,int k){
	n1 = n2 = 0;
	for(int i=r;i;i-=lowbit(i))	t2[++n2] = root[i];
	for(int i=l-1;i;i-=lowbit(i))	t1[++n1] = root[i];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)	cin>>a[i], b[++cnt] = a[i];
	for(int i=1;i<=m;++i){
		cin>>op[i].type;
		if(op[i].type == 'C'){
			cin>>op[i].l>>op[i].k;
			b[++cnt] = op[i].k;
		}else	cin>>op[i].l>>op[i].r>>op[i].k;
	}
	sort(b+1, b+1+cnt);
	cnt = unique(b+1, b+1+cnt) - b - 1;
	for(int i=1;i<=n;++i)	a[i] = lower_bound(b+1, b+1+cnt, a[i]) - b;
	for(int i=1;i<=m;++i)
		if(op[i].type == 'C')	op[i].k = lower_bound(b+1, b+1+cnt, op[i].k) - b;
	for(int i=1;i<=n;++i)	modify(i, a[i], 1);
	for(int i=1;i<=m;++i){
		if(op[i].type == 'C'){
			modify(op[i].l, a[op[i].l], -1);
			a[op[i].l] = op[i].k;
			modify(op[i].l, a[op[i].l], 1);
		}else	init(op[i].l, op[i].r, op[i].k), cout<<b[kth(1, cnt, op[i].k)]<<endl;
	}
	return 0;
}