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
#define endl '\n'

#define pi acos(-1)
#define eps (1e-8)
#define null nullptr

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e5 + 10;

int n, m, op[N], l[N], r[N], v[N], lst;
int a[N], b[N];
bool flag1, flag2;
namespace sub1{
	void solve(){
		for(int i=1;i<=m;++i){
			l[i]^=lst, r[i]^=lst, v[i]^=lst;
			if(op[i]==1){
				int ans = 0;
				for(int j=l[i];j<=r[i];++j)	ans += a[j];
				cout<<ans<<endl; lst = ans;
			}else if(op[i]==2){
				for(int j=l[i];j<=r[i];++j)	a[j] += v[i];
			}else if(op[i]==3){
				for(int j=l[i];j<=r[i];++j)	b[j] += v[i];
			}else if(op[i]==4){
				for(int j=l[i];j<=r[i];++j)	a[j] += b[j];
			}
		}
	}
}
namespace sub2{
	int sum[N<<2], tag[N<<2];
	void push_up(int p){ sum[p] = sum[p<<1] + sum[p<<1|1];}
	void push_down(int p, int l, int r){
		if(!tag[p])	return ;
		int mid = l+r>>1;
		tag[p<<1] += tag[p], tag[p<<1|1] += tag[p];
		sum[p<<1] += tag[p] * (mid-l+1), sum[p<<1|1] += tag[p] * (r-mid);
		tag[p] = 0;
	}
	void update(int p,int l,int r,int left,int right,int k){
		if(left<=l&&r<=right){ tag[p]+=k, sum[p] += (r-l+1)*k; return ;}
		int mid = l+r>>1;
		push_down(p, l, r);
		if(left<=mid)	update(p<<1, l, mid, left, right, k);
		if(right>mid)	update(p<<1|1, mid+1, r, left, right, k);
		push_up(p);
	}
	int query(int p,int l,int r,int left,int right){
		if(left<=l&&r<=right)	return sum[p];
		int mid = l+r>>1;
		push_down(p, l, r);
		int res = 0;
		if(left<=mid)	res += query(p<<1, l, mid, left, right);
		if(right>mid)	res += query(p<<1|1, mid+1, r, left, right);
		return res;
	}
	void solve(){
		for(int i=1;i<=n;++i)	update(1, 1, n, i, i, a[i]);
		for(int i=1;i<=m;++i){
//			l[i]^=lst, r[i]^=lst, v[i]^=lst;
			if(op[i]==1)	cout<<(lst=query(1, 1, n, l[i], r[i]))<<endl;
			else	update(1, 1, n, l[i], r[i], v[i]);
		}
	}
}
namespace sub3{
	void solve(){
		for(int i=1;i<=m;++i){
			l[i]^=lst, r[i]^=lst, v[i]^=lst;
			if(op[i]==1)	cout<<(lst=a[l[i]])<<endl;
			else if(op[i]==2)	a[l[i]]+=v[i];
			else if(op[i]==3)	b[l[i]]+=v[i];
			else if(op[i]==4)	a[l[i]]+=b[l[i]];
		}
	}
}

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)	cin>>a[i];
	for(int i=1;i<=m;++i){
		cin>>op[i]>>l[i]>>r[i];
		if(op[i]==2||op[i]==3)	cin>>v[i];
		if(op[i]==3||op[i]==4)	flag2=true;
	}
	if(n<=3000&&m<=3000){
		using namespace sub1;
		solve();
	}else if(!flag2){
		using namespace sub2;
		solve();
	}else{
		using namespace sub3;
		solve();
	}
	return 0;
}
