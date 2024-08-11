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
const int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 3e5 + 10;
const int M = 1e6 + 10;

int f[N], c, town[N], p[N], n, m;

struct seg{
	int maxx[N<<2];
	void update(int p,int l,int r,int x,int k){
		if(l==r){ maxx[p]=max(maxx[p],k); return ;}
		int mid=l+r>>1;
		if(x<=mid)	update(p<<1,l,mid,x,k);
		else	update(p<<1|1,mid+1,r,x,k);
		maxx[p]=max(maxx[p<<1],maxx[p<<1|1]);
	}
	int query(int p,int l,int r,int left,int right){
		if(left<=l&&r<=right)	return maxx[p];
		int mid=l+r>>1, res=-INF;
		if(left<=mid)	res=max(res,query(p<<1,l,mid,left,right));
		if(right>mid)	res=max(res,query(p<<1|1,mid+1,r,left,right));
		return res;
	}
}t1,t2;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>c>>m;
	for(int i=1;i<=m;++i)	cin>>town[i]>>p[i];
	for(int i=1;i<=n<<2;++i)	t1.maxx[i]=t2.maxx[i]=-INF;
	f[1]=p[1]-abs(town[1]-1)*c;
	t1.update(1,1,n,town[1],f[1]+town[1]*c);
	t2.update(1,1,n,town[1],f[1]-town[1]*c);
	// cout<<f[1]<<endl;
	for(int i=2;i<=m;++i){
		int x1=t1.query(1,1,n,1,town[i]), x2=t2.query(1,1,n,town[i]+1,n);
		f[i]=max(x1-town[i]*c,x2+town[i]*c)+p[i];
		// cout<<x1<<" "<<x2<<" ";
		t1.update(1,1,n,town[i],f[i]+town[i]*c);
		t2.update(1,1,n,town[i],f[i]-town[i]*c);
		// cout<<f[i]<<endl;
	}
	int maxx=0;
	for(int i=1;i<=m;++i)
		maxx=max(maxx,f[i]);
	cout<<max(f[m],0ll)<<endl;
	return 0;
}