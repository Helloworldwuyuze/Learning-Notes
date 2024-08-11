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
const int N = 1e5 + 10;
const int M = 1e6 + 10;
const int MAXN = (1ull<<63)-1;

struct opt{
	int l, r, c, type, ans, id;
}op[N], p[N], q[N];

int n, m, idx, ans[N], mx;

int s[N<<2], tag[N<<2];
void push_down(int p,int l,int r){
	if(!tag[p])	return ;
	int mid = l+r>>1;
	tag[p<<1] += tag[p], tag[p<<1|1] += tag[p];
	s[p<<1] += tag[p] * (mid-l+1), s[p<<1|1] += tag[p] * (r-mid);
	tag[p] = 0;
}
void update(int p,int l,int r,int left,int right,int k){
	if(left <= l && r <= right)	return (void)(tag[p] += k, s[p] += (r-l+1)*k);
	int mid = l+r>>1;
	push_down(p,l,r);
	if(left <= mid)	update(p<<1, l, mid, left, right, k);
	if(right > mid)	update(p<<1|1, mid+1, r, left, right, k);
	s[p] = s[p<<1] + s[p<<1|1];
}
int query(int p,int l,int r,int left,int right){
	if(left <= l && r <= right)	return s[p];
	int mid = l+r>>1, res = 0;
	push_down(p,l,r);
	if(left <= mid)	res += query(p<<1, l, mid, left, right);
	if(right > mid)	res += query(p<<1|1, mid+1, r, left, right);
	return res;
}

void solve(int L,int R,int l,int r){
	if(R<L)	return ;
	// cout<<"###"<<L<<" "<<R<<" "<<l<<" "<<r<<"###"<<endl;
	// for(int i=L;i<=R;++i)	cout<<op[i].type<<" "<<op[i].l<<" "<<op[i].r<<" "<<op[i].c<<endl;
	if(l == r){
		for(int i=L;i<=R;++i)
			if(op[i].type == 2)	ans[op[i].id] = l;
		return ;
	}
	int mid = l+r>>1;
	int cntp = 0, cntq = 0;
	for(int i=L;i<=R;++i)
		if(op[i].type == 1){
			if(op[i].c+n+1 <= mid)	p[++cntp] = op[i];
			else	q[++cntq] = op[i], update(1, 1, n*2+1, op[i].l, op[i].r, 1);
		}else{
			int tmp = query(1, 1, n*2+1, op[i].l, op[i].r);
			// cout<<"QRY! "<<op[i].l<<" "<<op[i].r<<" "<<op[i].c<<" "<<op[i].id<<" "<<tmp<<endl;
			if(tmp < op[i].c)	op[i].c -= tmp, p[++cntp] = op[i];
			else	q[++cntq] = op[i];
		}
	for(int i=1;i<=cntq;++i)
		if(q[i].type == 1)	update(1, 1, n*2+1, q[i].l, q[i].r, -1);
	for(int i=1;i<=cntp;++i)	op[i+L-1] = p[i];
	for(int i=1;i<=cntq;++i)	op[i+L+cntp-1] = q[i];
	solve(L, L+cntp-1, l, mid), solve(L+cntp, R, mid+1, r);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>op[i].type>>op[i].l>>op[i].r>>op[i].c;
		if(op[i].type == 2)	op[i].id = ++idx;
		mx = max(mx, op[i].c);
	}
	solve(1, m, 1, n*2+1);
	for(int i=1;i<=idx;++i)	cout<<ans[i]-n-1<<endl;
	return 0;
}