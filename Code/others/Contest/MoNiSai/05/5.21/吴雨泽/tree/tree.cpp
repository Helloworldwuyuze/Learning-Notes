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

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;
const int M = 1e7 + 10;
const int MOD = 1e9 + 7;

vector<int> g[N];
int n, a[N];
int fa[N], siz[N], dfn[N], rk[N], idx=0, ans;

void dfs(int x,int fat){
	dfn[x]=++idx, rk[idx]=x, fa[x]=fat, siz[x]=1;
	for(int y:g[x])
		if(y!=fat)	dfs(y,x), siz[x]+=siz[y];
}

namespace seg{
	int maxx[N<<2], tag[N<<2];
	void push_up(int p){
		maxx[p]=a[maxx[p<<1]]>a[maxx[p<<1|1]]?maxx[p<<1]:maxx[p<<1|1];
	}
	void build(int p,int l,int r){
		tag[p]=-1;
		if(l==r){ maxx[p]=rk[l]; return ;}
		int mid=l+r>>1;
		build(p<<1,l,mid), build(p<<1|1,mid+1,r);
		push_up(p);
	}
	void push_down(int p){
		if(tag[p]==-1)	return ;
		maxx[p<<1]=maxx[p<<1|1]=maxx[p], tag[p<<1]=tag[p<<1|1]=tag[p];
		tag[p]=-1;
	}
	void update(int p,int l,int r,int left,int right,int k){
		if(left<=l&&r<=right){
			maxx[p]=tag[p]=k;
			return ;
		}
		push_down(p);
		int mid=l+r>>1;
		if(left<=mid)	update(p<<1,l,mid,left,right,k);
		if(right>mid)	update(p<<1|1,mid+1,r,left,right,k);
		push_up(p);
	}
	int query(int p,int l,int r,int left,int right){
		if(left<=l&&r<=right)	return maxx[p];
		int mid=l+r>>1, ls=0, rs=0;
		push_down(p);
		if(left<=mid)	ls=query(p<<1,l,mid,left,right);
		if(right>mid)	rs=query(p<<1|1,mid+1,r,left,right);
		return a[ls]>a[rs]?ls:rs;
	}
}

bool vis[N];
void solve(int x,bool type,int from){
	// cout<<x<<" "<<type<<" "<<from<<endl;
	if(type==0){
		while(true){
			int root=seg::query(1,1,n,dfn[x],dfn[x]+siz[x]-1);
			if(a[root]==0)	return ;
			solve(root,1,x);
		}
	}else{
		vis[x]=true;
		for(int y:g[x]){
			if(vis[y]||y==fa[x])	continue;
			ans+=a[x]+a[seg::query(1,1,n,dfn[y],dfn[y]+siz[y]-1)];
			solve(y,0,x);
		}
		seg::update(1,1,n,dfn[x],dfn[x]+siz[x]-1,0);
		if(!vis[fa[x]]&&from!=x)	ans+=a[x]+a[seg::query(1,1,n,dfn[from],dfn[from]+siz[from]-1)];
	}
	// cout<<"END::"<<x<<" "<<type<<" "<<from<<" "<<ans<<endl;
}

signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>a[i];
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	dfs(1,0);
	seg::build(1,1,n);
	solve(1,0,0);
	cout<<ans<<endl;
	return 0;
}
