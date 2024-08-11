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
const int MOD = 998244353;

int n, h[N], l[N], r[N], f[N], s = 1, b[N], m;
int root[N], ls[N<<5], rs[N<<5], sum[N<<5], idx;

int ksm(int x,int m){
	int ans = 1;
	for(; m; m>>=1, x = x*x%MOD) if(m&1) ans = ans*x%MOD;
	return ans;
}

void update(int &p,int q,int l,int r,int x,int k){
	p = ++idx;
	tie(ls[p], rs[p], sum[p]) = tie(ls[q], rs[q], sum[q]);
	if(l == r)	return (void)(sum[p] = (sum[p] + k)%MOD);
	int mid = l+r>>1;
	if(x <= mid)	update(ls[p], ls[q], l, mid, x, k);
	else	update(rs[p], rs[q], mid+1, r, x, k);
	sum[p] = (sum[ls[p]] + sum[rs[p]])%MOD;
}
int query(int p,int l,int r,int left,int right){
	if(!p)	return 0;
	if(left<=l && r<=right)	return sum[p];
	int mid = l+r>>1, res = 0;
	if(left <= mid)	res += query(ls[p], l, mid, left, right);
	if(right > mid)	res += query(rs[p], mid+1, r, left, right);
	return res;
}



signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>h[i], b[i] = h[i];
	sort(b+1, b+1+n), m = unique(b+1, b+1+n) - b - 1;
	for(int i=1;i<=n;++i)	h[i] = lower_bound(b+1, b+1+m, h[i]) - b;
	for(int i=2;i<=n;++i)	cin>>l[i]>>r[i], s = s*(r[i] - l[i] + 1)%MOD;
	f[1] = 1;
	update(root[1], root[0], 1, n, h[1], f[1]);
	for(int i=2;i<=n;++i){
		f[i] = ksm(r[i] - l[i] + 1, MOD-2) * ((query(root[r[i]], 1, n, 1, h[i]) - query(root[l[i]-1], 1, n, 1, h[i]) + MOD)%MOD)%MOD;
		update(root[i], root[i-1], 1, n, h[i], f[i]);
	}
	int ans = 0;
	for(int i=1;i<=n;++i)	ans = (ans + f[i] * s % MOD) % MOD;
	cout<<ans<<endl;
	return 0;
}