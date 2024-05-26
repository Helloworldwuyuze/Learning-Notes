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

#define int long long
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
const int N = 2e5 + 10;
const int M = 1e6 + 10;

int n,t,col[N];

namespace seg{
	int lc[N<<2], rc[N<<2], sum[N<<2], tag[N<<2];
	void push_up(int p){
		if(rc[p<<1]==lc[p<<1|1])	sum[p]=sum[p<<1|1]+sum[p<<1]-1;
		else	sum[p]=sum[p<<1|1]+sum[p<<1];
		lc[p]=lc[p<<1], rc[p]=rc[p<<1|1];
	}
	void push_down(int p){
		if(!tag[p])	return ;
		sum[p<<1]=sum[p<<1|1]=1;
		lc[p<<1]=rc[p<<1]=lc[p<<1|1]=rc[p<<1|1]=tag[p];
		tag[p<<1]=tag[p<<1|1]=tag[p];
		tag[p]=0;
		return ;
	}
	void update(int p,int l,int r,int left,int right,int x){
		if(left<=l&&r<=right){
			tag[p]=x, lc[p]=rc[p]=x, sum[p]=1;
			return ;
		}
		push_down(p);
		int mid=l+r>>1;
		if(left<=mid)	update(p<<1,l,mid,left,right,x);
		if(right>mid)	update(p<<1|1,mid+1,r,left,right,x);
		push_up(p);
	}
	PIII query(int p,int l,int r,int left,int right){
		if(left<=l&&r<=right)	return mk(sum[p],mk(lc[p],rc[p]));
		push_down(p);
		int mid=l+r>>1, tls = 0, trs = 0;
		PIII ls, rs;
		if(left<=mid)	tls=1, ls=query(p<<1,l,mid,left,right);
		if(right>mid)	trs=1, rs=query(p<<1|1,mid+1,r,left,right);
		if(!tls)	return rs;
		else if(!trs)	return ls;
		else	return mk(ls.fi+rs.fi-(ls.se.se==rs.se.fi),mk(ls.se.fi,rs.se.se));
	}
}

vector<int> g[N];
namespace cut{
	int dfn[N], rk[N], top[N], siz[N], fa[N][20], dep[N], son[N], idx;
	void dfs1(int x,int fat){
		fa[x][0]=fat, siz[x]=1, dep[x]=dep[fat]+1;
		for(int i=1;i<=t;++i)	fa[x][i]=fa[fa[x][i-1]][i-1];
		for(int y:g[x]){
			if(y==fat)	continue;
			dfs1(y,x);
			siz[x]+=siz[y];
			if(siz[son[x]]<siz[y])	son[x]=y;
		}
	}
	void dfs2(int x,int tp){
		top[x]=tp, dfn[x]=++idx, rk[idx]=x;
		if(son[x])	dfs2(son[x],tp);
		for(int y:g[x])
			if(y!=son[x]&&y!=fa[x][0])	dfs2(y,y);
	}
	void update(int x,int y,int col){
		// cout<<"CUT::UPDATE "<<x<<" "<<y<<" "<<col<<endl;
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]])	swap(x,y);
			// cout<<x<<" "<<top[x]<<endl;
			seg::update(1,1,idx,dfn[top[x]],dfn[x],col);
			x=fa[top[x]][0];
		}
		if(dep[x]<dep[y])	swap(x,y);
		// cout<<x<<" "<<y<<endl;
		seg::update(1,1,idx,dfn[y],dfn[x],col);
	}
	PIII query(int x,int y){
		PIII lst, now;
		int ans=0, l=-1;
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]])	swap(x,y);
			now=seg::query(1,1,idx,dfn[top[x]],dfn[x]);
			ans+=now.fi-(now.se.se==lst.se.fi);
			lst=now; x=fa[top[x]][0];
			if(l==-1)	l=lst.se.fi;
		}
		if(dep[x]<dep[y])	swap(x,y);
		now=seg::query(1,1,idx,dfn[y],dfn[x]);
		if(l==-1)	l=now.se.fi;
		// cout<<now.fi<<" "<<now.se.fi<<" "<<now.se.se<<endl;
		return mk(ans+now.fi-(now.se.se==lst.se.fi),mk(l,now.se.se));
	}
	int lca(int x,int y){
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]])	swap(x,y);
			x=fa[top[x]][0];
		}
		return dep[x]<dep[y]?x:y;
	}
}

int allcol[N<<1], cnt;

struct question{
	int op,u,v,col,k;
	vector<int> p;
}ques[N];

int a[N], k, q, ans[N];
bool tag[N];
namespace Virtree{
	vector<PII> vir[N];
	int st[N], top, cnt;
	bool cmp(int x,int y){ return cut::dfn[x]<cut::dfn[y];}
	void add(int x,int y){
		int w=cut::query(x,y).fi;
		vir[x].pb(mk(y,w)), vir[y].pb(mk(x,w));
	}
	void build(){
		sort(a+1,a+1+k,cmp);
		st[top=1]=1; cnt=1;
		for(int i=1;i<=k;++i){
			if(a[i]==1)	continue;
			int lca=cut::lca(a[i],st[top]);
			if(st[top]!=lca){
				while(cut::dfn[st[top-1]]>cut::dfn[lca])	add(st[top-1],st[top]), --top;
				if(cut::dfn[st[top-1]]<cut::dfn[lca])	add(lca,st[top]), st[top]=lca, ++cnt;
				else	add(lca,st[top]), --top;
			}
			st[++top]=a[i], ++cnt;
		}
		while(top>1)	add(st[top-1],st[top]), --top;
	}
	void init(int x,int fa);
}

namespace PointDevide{
	int maxx[N], siz[N], sum, root;
	bool vis[N];
	void calsiz(int x,int fa){
		maxx[x]=0, siz[x]=1;
		for(PII y:Virtree::vir[x]){
			if(vis[y.fi]||y.fi==fa)	continue;
			calsiz(y.fi,x);
			siz[x]+=siz[y.fi];
			maxx[x]=max(maxx[x],siz[y.fi]);
		}
		maxx[x]=max(maxx[x],sum-siz[x]);
		if(maxx[x]<maxx[root])	root=x;
	}
	vector<int> v, key, sub;
	int dis[N];
	int closest[N];
	int subs, cols[N], subtot, coltot[N];
	void caldis(int x,int fa){
		v.pb(x);
		if(tag[x])	key.pb(x), sub.pb(x);
		for(PII y:Virtree::vir[x]){
			if(vis[y.fi]||y.fi==fa)	continue;
			closest[y.fi]=closest[x];
			dis[y.fi]=dis[x]+y.se-1;
			caldis(y.fi,x);
		}
	}
	void dfz(int x){
		vis[x]=true;
		for(PII y:Virtree::vir[x]){
			if(vis[y.fi])	continue;
			dis[y.fi]=y.se; key.clear(); closest[y.fi]=y.fi;
			int coly = closest[y.fi];
			caldis(y.fi,x);
			for(int z:key)	cols[coly]+=dis[z], ++coltot[coly], subs+=dis[z], ++subtot;
		}
		for(int y:sub){
			int coly=closest[y];
			ans[y]+=(subtot-coltot[coly])*(dis[y]-1)+(subs-cols[coly]);
		}
		if(tag[x]){
			ans[x]+=subs;
			for(int y:sub)	ans[y]+=dis[y];
		}
		
		for(int y:v)
			cols[closest[y]]=coltot[closest[y]]=0, dis[y]=closest[y]=0;
		v.clear(); key.clear(); sub.clear();
		subs=subtot=0;
		for(PII y:Virtree::vir[x]){
			if(vis[y.fi])	continue;
			maxx[root=0]=INF, sum=siz[y.fi];
			calsiz(y.fi,-1), calsiz(root,-1);
			dfz(root);
		}
	}
}

void Virtree::init(int x,int fa){
	for(PII y:vir[x])
		if(y.fi!=fa)	init(y.fi,x);
	vir[x].clear(), tag[x]=false, ans[x]=0;
	PointDevide::vis[x]=false;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>q; t=log(n)/log(2);
	for(int i=1;i<=n;++i)	cin>>col[i], allcol[++cnt]=col[i];
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, g[x].pb(y), g[y].pb(x);
	for(int i=1;i<=q;++i){
		cin>>ques[i].op;
		if(ques[i].op==1)	cin>>ques[i].u>>ques[i].v>>ques[i].col, allcol[++cnt]=ques[i].col;
		else{
			cin>>ques[i].k;
			for(int j=1,x;j<=ques[i].k;++j)	cin>>x, ques[i].p.pb(x);
		}
	}

	sort(allcol+1, allcol+1+cnt);
	cnt=unique(allcol+1,allcol+1+cnt)-allcol-1;
	for(int i=1;i<=n;++i)	col[i]=lower_bound(allcol+1,allcol+1+cnt,col[i])-allcol;
	for(int i=1;i<=q;++i)
		if(ques[i].op==1)	ques[i].col=lower_bound(allcol+1,allcol+1+cnt, ques[i].col)-allcol;
	cut::dfs1(1,0), cut::dfs2(1,1);
	for(int i=1;i<=n;++i)
		seg::update(1,1,cut::idx,cut::dfn[i],cut::dfn[i],col[i]);
	for(int i=1;i<=q;++i){
		if(ques[i].op==1)	cut::update(ques[i].u,ques[i].v,ques[i].col);
		else{
			Virtree::init(1,0);
			int tot=0; k=ques[i].k;
			for(int x:ques[i].p)	tag[x]=true, a[++tot]=x;
			Virtree::build();
			PointDevide::maxx[PointDevide::root=0]=INF, PointDevide::sum=Virtree::cnt;
			PointDevide::calsiz(1,-1), PointDevide::calsiz(PointDevide::root,-1);
			PointDevide::dfz(PointDevide::root);
			for(int x:ques[i].p)
				cout<<ans[x]+1<<" ";
			cout<<endl;
		}
	}
	return 0;
}