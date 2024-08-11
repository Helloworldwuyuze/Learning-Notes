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
const int N = 5e3 + 10;
const int M = 2e5 + 10;

int n, q, id;
int ls[M], rs[M], a[M], op, x, y;
int dfn[M], idx, siz[M];
bool f[M];

int b[M];
#define lowbit(x) (x&-x)
void update(int x,int k){	for(int i=x;i<=n;i+=lowbit(i))	b[i] += k;}
int query(int x){ int ans = 0; for(int i=x;i;i-=lowbit(i))	ans += b[i]; return ans;}
#undef lowbit

int minn[M<<2], maxx[M<<2];
void modify(int p,int l,int r,int x,int k){
	if(l == r)	return (void)(minn[p] = maxx[p] = k);
	int mid = l+r>>1;
	if(x<=mid)	modify(p<<1, l, mid, x, k);
	else	modify(p<<1|1, mid+1, r, x, k);
	minn[p] = min(minn[p<<1], minn[p<<1|1]);
	maxx[p] = max(maxx[p<<1], maxx[p<<1|1]);
}
int qrymn(int p,int l,int r,int left,int right){
	if(left<=l && r<=right)	return minn[p];
	int mid = l+r>>1, res = INF;
	if(left <= mid)	res = min(res, qrymn(p<<1, l, mid, left, right));
	if(right > mid)	res = min(res, qrymn(p<<1|1, mid+1, r, left, right));
	return res; 
}
int qrymx(int p,int l,int r,int left,int right){
	if(left<=l && r<=right)	return maxx[p];
	int mid = l+r>>1, res = 0;
	if(left <= mid)	res = max(res, qrymx(p<<1, l, mid, left, right));
	if(right > mid)	res = max(res, qrymx(p<<1|1, mid+1, r, left, right));
	return res; 
}

void dfs(int x){
	if(!x)	return ;
	dfn[x] = ++idx, siz[x] = 1;
	dfs(ls[x]), dfs(rs[x]);
	siz[x] += siz[ls[x]] + siz[rs[x]];
}
void solve(int x){
	if(!ls[x] && !rs[x])	return update(dfn[x], f[x]=true);
//	cout<<"IN! "<<x<<" "<<ls[x]<<" "<<rs[x]<<endl;
	f[x] = true;
	if(ls[x]){
		solve(ls[x]);
		int tmp = qrymx(1, 1, n, dfn[ls[x]], dfn[ls[x]]+siz[ls[x]]-1);
//		cout<<"LS! "<<a[x]<<" "<<tmp<<endl;
		f[x] &= f[ls[x]] && a[x]>=tmp;
	}
	if(rs[x]){
		solve(rs[x]);
		int tmp = qrymn(1, 1, n, dfn[rs[x]], dfn[rs[x]]+siz[rs[x]]-1);
//		cout<<"RS! "<<a[x]<<" "<<tmp<<endl;
		f[x] &= f[rs[x]] && a[x]<=tmp;
	}
	update(dfn[x], f[x]);
//	cout<<"OUT! "<<x<<" "<<f[x]<<endl;
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>q>>id;
	for(int i=1;i<=n;++i)	cin>>ls[i]>>rs[i];
	for(int i=1;i<=n;++i)	cin>>a[i];
	if(id<=5){
		dfs(1);
		for(int i=1;i<=n;++i)
			modify(1, 1, n, dfn[i], a[i]);
		solve(1);
//		for(int i=1;i<=n;++i)	cout<<f[i]<<" ";
//		cout<<endl;
//		for(int i=1;i<=n<<1;++i)	cout<<i<<" "<<minn[i]<<" "<<maxx[i]<<endl;
//		cout<<endl;
		while(q--){
			cin>>op>>x;
			if(op == 1){
				cin>>y;
				a[x] = y;
				modify(1, 1, n, dfn[x], a[x]);
				for(int i=1;i<=n;++i)	b[i] = 0;
				solve(1);
//				for(int i=1;i<=n;++i)	cout<<f[i]<<" ";
//				cout<<endl;
//				for(int i=1;i<=n<<1;++i)	cout<<i<<" "<<minn[i]<<" "<<maxx[i]<<endl;
//				cout<<endl;
			}else	cout<<query(dfn[x]+siz[x]-1)-query(dfn[x]-1)<<endl;
		}
	}
	return 0;
}

