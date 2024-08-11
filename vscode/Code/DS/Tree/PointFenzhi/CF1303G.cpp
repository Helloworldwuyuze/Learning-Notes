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
#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1.5e5 + 10;
const int M = 1e6 + 10;
int n, a[N], ans;
int root, sum, maxx[N], siz[N];
int fa[N], v1[N], v2[N], l1[N], s2[N], cnt, top[N], p[N], dep[N], maxdep;
vector<int> g[N];
bool vis[N];
struct line{
	int k,b,id;
	line(){}
	line(int _k,int _b,int _id){ id=_id, k=_k, b=_b;}
	int val(int x){ return x*k+b;}
}t[N<<2];
void build(int p,int l,int r){
	t[p].id=t[p].b=t[p].k=0;
	if(l==r)	return ;
	int mid=l+r>>1;
	build(p<<1,l,mid), build(p<<1|1,mid+1,r);
}
void update(int p,int l,int r,line f){
	if(!t[p].id){ t[p]=f; return ;}
	int mid=l+r>>1;
	if(t[p].val(mid)<f.val(mid))	swap(t[p],f);
	if(t[p].val(l)<f.val(l))	update(p<<1,l,mid,f);
	if(t[p].val(r)<f.val(r))	update(p<<1|1,mid+1,r,f);
}
int query(int p,int l,int r,int x){
	if(l==r)	return t[p].val(x);
	int mid=l+r>>1;
	if(x<=mid)	return max(t[p].val(x),query(p<<1,l,mid,x));
	else	return max(t[p].val(x),query(p<<1|1,mid+1,r,x));
}
void calsiz(int x,int fat){
	siz[x]=1; maxx[x]=0, fa[x]=fat;
	for(int y:g[x]){
		if(vis[y]||y==fat)	continue;
		calsiz(y,x);
		siz[x]+=siz[y]; maxx[x]=max(maxx[x],siz[y]);
	}
	maxx[x]=max(maxx[x],sum-siz[x]);
	if(maxx[x]<maxx[root])	root=x;
}
void caldis(int x,int val1,int val2,int sum2,int tp){
	if(x!=root&&!tp)	tp=x;
	dep[x]=dep[fa[x]]+1;
	maxdep=max(maxdep, dep[x]);
	bool f=false;
	for(int y:g[x]){
		if(!vis[y]&&y!=fa[x]){
			f=true;
			caldis(y,val1+sum2+a[y],val2+dep[x]*a[y],sum2+a[y],tp);
		}
	}
	if(!f){ p[++cnt]=x; v1[cnt]=val1, v2[cnt]=val2, s2[cnt]=sum2-a[root], l1[cnt]=dep[x], top[cnt]=tp;}
}
void dfz(int x,int fat){
	vis[root]=true;
	cnt=0; maxdep=0;
	caldis(root,a[root],0,a[root],0);
	p[++cnt]=root, v1[cnt]=a[root], v2[cnt]=s2[cnt]=top[cnt]=0, l1[cnt]=1;
	top[0]=top[cnt+1]=-1;
	build(1,1,maxdep);
	for(int i=1;i<=cnt;){
		int j=i;
		while(top[j]==top[i])	ans=max(ans,query(1,1,maxdep,l1[j])+v1[j]), ++j; j=i;
		while(top[j]==top[i])	update(1,1,maxdep,line(s2[j],v2[j],j)), ++j; i=j;
	}
	build(1,1,maxdep);
	for(int i=cnt;i>=1;){
		int j=i;
		while(top[j]==top[i])	ans=max(ans,query(1,1,maxdep,l1[j])+v1[j]), --j; j=i;
		while(top[j]==top[i])	update(1,1,maxdep,line(s2[j],v2[j],j)), --j; i=j;
	}
	// cout<<"###"<<x<<" "<<fat<<"###"<<endl;
	// for(int i=1;i<=n;++i)
	// 	cout<<p[i]<<" "<<v1[i]<<" "<<v2[i]<<" "<<s2[i]<<" "<<l1[i]<<" "<<top[i]<<endl;
	for(int y:g[x]){
		if(vis[y])	continue;
		sum=siz[y]; maxx[root=0]=INF;
		calsiz(y,x), calsiz(root,-1);
		dfz(root,x);
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	for(int i=1;i<=n;++i)	cin>>a[i];
	maxx[root=0]=INF; sum=n;
	calsiz(1,-1); calsiz(root,-1);
	dfz(root,-1);
	cout<<ans<<endl;
	return 0;
}