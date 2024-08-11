#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>

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
#define endl '\n'

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10; 
const int M = 1e6 + 10;

int n, k, a[N<<1], f[N], pre[N], t[N<<1], rest[N<<1], m, g[N];

struct seg1{
	int root[N], idx, mx[N<<5], ls[N<<5], rs[N<<5];
	void update(int &p,int l,int r,int x,int k){
		if(!p)	p = ++idx;
		if(l == r)	return (void)(mx[p] = k);
		int mid = l+r>>1;
		if(x<=mid)	update(ls[p], l ,mid, x, k);
		else	update(rs[p], mid+1, r, x, k);
		mx[p] = max(mx[ls[p]], mx[rs[p]]);
	}
	int query(int p,int l,int r,int left,int right){
		if(!p || right < left)	return 0;
		if(left <= l && r <= right)	return mx[p];
		int mid = l+r>>1, res = 0;
		if(left <= mid)	res = max(res, query(ls[p], l, mid, left, right));
		if(right > mid)	res = max(res, query(rs[p], mid+1, r, left, right));
		return res;
	}
}s;
struct BIT{
	int b[N<<1];
	#define lowbit(x) (x&-x)
	void update(int x,int k){ for(int i=x;i<=m;i+=lowbit(i)) b[i] = max(b[i], k); }
	int query(int x){ int ans = 0; for(int i=x;i;i-=lowbit(i))	ans = max(ans, b[i]); return ans;}
	#undef lowbit
}b;

int maxx[N<<1];

int main(){
//	freopen("amnesia.in","r",stdin);
//	freopen("amnesia.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i)	cin>>a[i], t[i] = a[i], a[i+n+1] = t[i+n+1] = a[i]>k+1?a[i]-k:1;
	++n, a[n] = t[n] = INF-k, a[n*2] = t[n*2] = INF;
	sort(t+1, t+1+2*n);
	m = unique(t+1, t+1+2*n) - t - 1;
	for(int i=1;i<=n<<1;++i)	a[i] = lower_bound(t+1, t+1+m, a[i]) - t;
	for(int i=1;i<=n;++i){
		f[i] = b.query(a[i]-1)+1;
		b.update(a[i], f[i]);
	}
	if(k==0){
		int ans = 0;
		for(int i=1;i<=n;++i)	ans = max(ans, f[i]);
		cout<<ans-1<<endl;
		return 0;
	}
	for(int i=1;i<=n;++i){
		pre[i] = s.query(s.root[f[i]-1], 1, INF, 1, t[a[i]]-k-1);
		if(!pre[i]){
			pre[i] = i;
			for(int j=i-1;j>=max(1, i-k-1);--j){
				if(min(t[a[i]]-t[a[j]]-1,i-j-1) > min(t[a[i]]-t[a[pre[i]]]-1, i-pre[i]-1)
				&& f[j] == f[i]-1 )	pre[i] = j;
			}
			for(int j=a[i+n];j<a[i];++j){
				if(min(t[a[i]]-t[a[pre[i]]]-1, i-pre[i]-1) < t[a[i]]-t[j]-1 && maxx[j]
				&& f[maxx[j]] == f[i]-1 )	pre[i] = maxx[j];
			}
			if(pre[i] == i)	pre[i] = 0;
		}
		if(i>k+1){
			maxx[a[i-k-1]] = max(maxx[a[i-k-1]], i-k-1);
			s.update(s.root[f[i-k-1]], 1, INF, t[a[i-k-1]], i-k-1);
		}
	}
	int ans = 0,res=0;
	rest[0] = k;
	for(int i=1;i<=n;++i){
		g[i] = max(f[i], g[pre[i]] + 1 + max(0, min(rest[pre[i]], min(i-pre[i]-1, t[a[i]]-t[a[pre[i]]]-1))));
		if(f[i] != g[i])
			rest[i] = rest[pre[i]] - max(0, min(rest[pre[i]], min(i-pre[i]-1, t[a[i]]-t[a[pre[i]]]-1)));
		else	rest[i] = rest[pre[i]];	
		ans = max(ans, g[i]);
//		cout<<pre[i]<<" "<<f[i]<<" "<<g[i]<<" "<<rest[i]<<endl;
	}
//	cout<<endl;
	cout<<ans-1<<endl;
	return 0;
}

