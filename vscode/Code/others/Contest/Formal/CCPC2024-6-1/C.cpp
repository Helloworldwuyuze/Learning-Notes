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
// #define endl '\n'

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10;
const int M = 1e7 + 10;
const int MOD = 998244353;

struct range{
	int l,r;
	bool operator <(const range &other) const{ return l==other.l?r<other.r:l<other.l; }
}q[N];
int n,k,a[N],m,T;

namespace seg{
	int maxx[N<<2], tag[N<<2];
	void push_down(int p){
		if(!tag[p])	return ;
		maxx[p<<1]+=tag[p], maxx[p<<1|1]+=tag[p];
		tag[p<<1]+=tag[p], tag[p<<1|1]+=tag[p];
		tag[p]=0;
	}
	void update(int p,int l,int r,int left,int right){
		if(left<=l&&r<=right){ tag[p]++, maxx[p]++; return ;}
		int mid=l+r>>1;
		push_down(p);
		if(left<=mid)	update(p<<1,l,mid,left,right);
		if(right>mid)	update(p<<1|1,mid+1,r,left,right);
		maxx[p]=max(maxx[p<<1],maxx[p<<1|1]);
	}
	int query(int p,int l,int r,int left,int right){
		if(left<=l&&r<=right)	return maxx[p];
		int mid=l+r>>1, res=0;
		push_down(p);
		if(left<=mid)	res=max(res,query(p<<1,l,mid,left,right));
		if(right>mid)	res=max(res,query(p<<1|1,mid+1,r,left,right));
		return res;
	}
}
using namespace seg;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>k; m=0;
		for(int i=1;i<=n;++i)	cin>>q[i].l>>q[i].r, a[++m]=q[i].l, a[++m]=q[i].r;
		sort(a+1,a+1+m);
		m=unique(a+1,a+1+m)-a-1;
		for(int i=1;i<=n;++i){
			q[i].l=lower_bound(a+1,a+1+m,q[i].l)-a;
			q[i].r=lower_bound(a+1,a+1+m,q[i].r)-a;
		}
		sort(q+1,q+1+n);
		int ans=1; bool flag=false;
		for(int i=1;i<=n;++i){
			int cover=query(1,1,m,q[i].l,q[i].r);
			if(cover>=k){ flag=true; break; }
			ans=ans*(k-cover)%MOD;
			update(1,1,m,q[i].l,q[i].r);
		}
		if(!flag)	cout<<ans<<endl;
		else	cout<<0<<endl;
		for(int i=1;i<=m<<2;++i)	maxx[i]=tag[i]=0;
	}
	return 0;
}
