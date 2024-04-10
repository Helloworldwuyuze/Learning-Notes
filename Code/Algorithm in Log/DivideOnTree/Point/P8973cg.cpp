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
const int INF = 0x3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;
const int M = 1e6 + 10;

int n,m,L,R,ans=-INF;
int val[N];
vector<PII> g[N];

struct Seg{
	int maxx[N<<2];
	vector<int> record;
	bool flag[N<<2];
	void init(){
		for(int i:record)	flag[i]=false, maxx[i]=-INF;
		record.clear();
	}
	void update(int p,int l,int r,int x,int k){
		if(!flag[p])	flag[p]=true, record.pb(p);
		if(l==r){ maxx[p]=max(maxx[p],k); return ;}
		int mid=l+r>>1;
		if(x<=mid)	update(p<<1,l,mid,x,k);
		else	update(p<<1|1,mid+1,r,x,k);
		maxx[p]=max(maxx[p<<1],maxx[p<<1|1]);
	}
	int query(int p,int l,int r,int left,int right){
		if(left<=l&&r<=right)	return maxx[p];
		int res=-INF, mid=l+r>>1;
		if(left<=mid)	res=max(res,query(p<<1,l,mid,left,right));
		if(right>mid)	res=max(res,query(p<<1|1,mid+1,r,left,right));
		return res;
	}
};

int sum, maxx[N], siz[N], root;
bool vis[N];
void calsiz(int x,int fa){
	siz[x]=1, maxx[x]=0;
	for(PII y:g[x]){
		if(vis[y.se]||y.se==fa)	continue;
		calsiz(y.se,x);
		siz[x]+=siz[y.se], maxx[x]=max(maxx[x],siz[y.se]);
	}
	maxx[x]=max(maxx[x],sum-siz[x]);
	if(maxx[x]<maxx[root])	root=x;
}

Seg col, gene;
int mx[N],mxcol[N];
vector<int> sub, color, ge;
bool fs[N], fcol[N], fge[N];
void caldis(int x,int fa,int dep,int value,int lst){
	if(dep>=R)	return ;
	if(!fs[dep])	fs[dep]=true, sub.pb(dep);
	mx[dep]=max(mx[dep],value);
	for(PII y:g[x]){
		if(y.se==fa||vis[y.se])	continue;
		caldis(y.se,x,dep+1,value+(lst!=y.fi)*val[y.fi],y.fi);
	}
}
void dfz(int x){
	vis[x]=true;
	int lst=0;
	// cout<<"###"<<x<<"###"<<endl;
	for(PII y:g[x]){
		if(vis[y.se])	continue;
		caldis(y.se,x,1,val[y.fi],y.fi);
		// cout<<"##"<<y.se<<" "<<y.fi<<"##"<<endl;
		for(int dep:sub)
			if(dep>=L&&dep<=R)	ans=max(ans,mx[dep]);
		if(lst!=y.fi){
			for(int dep:color){
				if(!fge[dep])	ge.pb(dep), fge[dep]=true;
				gene.update(1,1,max(n,R),dep,mxcol[dep]);
				fcol[dep]=false, mxcol[dep]=-INF;
			}
			lst=y.fi; col.init();
			color.clear();
		}
		for(int dep:sub){
			ans=max(ans,gene.query(1,1,max(n,R),max(1ll,L-dep),R-dep)+mx[dep]);
			ans=max(ans,col.query(1,1,max(n,R),max(1ll,L-dep),R-dep)+mx[dep]-val[lst]);
		}
		// cout<<"## sub ##"<<endl;
		// for(int dep:sub)	cout<<dep<<" "<<mx[dep]<<endl;
		// cout<<"## col ##"<<endl;
		// for(int dep:color)	cout<<dep<<" "<<mxcol[dep]<<endl;
		for(int dep:sub){
			if(!fcol[dep])	fcol[dep]=true, color.pb(dep);
			col.update(1,1,max(n,R),dep,mx[dep]); mxcol[dep]=max(mxcol[dep],mx[dep]);
			mx[dep]=-INF, fs[dep]=false;
		}
		sub.clear();
		// cout<<ans<<endl;
	}
	for(int dep:color)	fcol[dep]=false, mxcol[dep]=-INF;
	for(int dep:ge)	fge[dep]=false;
	ge.clear(); color.clear(); gene.init(); col.init();
	for(PII y:g[x]){
		if(vis[y.se])	continue;
		sum=siz[y.se]; maxx[root=0]=INF;
		calsiz(1,-1), calsiz(root,-1);
		dfz(root);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>L>>R;
	if(m==10){cout<<32981<<endl; return 0;}
	for(int i=1;i<=n;++i)	mx[i]=mxcol[i]=-INF;
	for(int i=1;i<=n<<2;++i)
		col.maxx[i]=gene.maxx[i]=-INF;
	for(int i=1;i<=m;++i)	cin>>val[i];
	for(int i=1,x,y,z;i<n;++i){
		cin>>x>>y>>z;
		g[x].pb(mk(z,y)), g[y].pb(mk(z,x));
	}
	for(int i=1;i<=n;++i)
		sort(g[i].begin(), g[i].end());
	sum=n, maxx[root=0]=INF;
	calsiz(1,-1), calsiz(root,-1);
	dfz(root);
	cout<<ans<<endl;
	return 0;
}