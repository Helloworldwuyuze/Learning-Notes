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

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n;
double s,a[N],b[N],k[N];
double q[N], c[N], f[N];

struct line{
	int id;
	double k,b;
	line(){ id=0;}
	line(double _k,double _b,double _id){id=_id, k=_k, b=_b;}
	double val(int x){return c[x]*k+b;}
}t[N<<2];

void update(int p,int l,int r,line f){
	if(!t[p].id){ t[p]=f; return ;}
	int mid=l+r>>1;
	if(t[p].val(mid)<f.val(mid)&&!(fabs(t[p].val(mid)-f.val(mid))<eps))	swap(t[p],f);
	if(t[p].val(l)<f.val(l)+eps)	update(p<<1,l,mid,f);
	if(t[p].val(r)<f.val(r)+eps)	update(p<<1|1,mid+1,r,f);
}
double query(int p,int l,int r,int x){
	if(l==r)	return t[p].val(x);
	int mid=l+r>>1;
	if(x<=mid)	return max(t[p].val(x),query(p<<1,l,mid,x));
	else	return max(t[p].val(x),query(p<<1|1,mid+1,r,x));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>s;
	for(int i=1;i<=n;++i)	cin>>a[i]>>b[i]>>k[i], q[i]=c[i]=a[i]/b[i];
	sort(c+1,c+1+n);
	f[0]=s;
	for(int i=1;i<=n;++i){
		f[i]=max(f[i-1],b[i]*query(1,1,n,lower_bound(c+1,c+1+n,q[i])-c));
		double g=a[i]*k[i]+b[i];
		update(1,1,n,line(f[i]*k[i]/g,f[i]/g,i));
		// cout<<f[i]<<endl;
	}
	cout<<fixed<<setprecision(9)<<f[n]<<endl;
	return 0;
}