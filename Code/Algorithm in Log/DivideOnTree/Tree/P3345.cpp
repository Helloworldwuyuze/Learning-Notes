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
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n,q;
vector<PII> g[N];

namespace tc{
	int son[N],fa[N],siz[N],dep[N],top[N],dist[N];
	void dfs1(int x,int fat){
		fa[x]=fat, dep[x]=dep[fat]+1, siz[x]=1;
		for(PII v:g[x]){
			int y=v.fi, z=v.se;
			if(y==fat)	continue;
			dist[y]=dist[x]+z;
			dfs1(y,x);
			siz[x]+=siz[y];
			if(siz[y]>siz[son[x]])	son[x]=y;
		}
	}
	void dfs2(int x,int tp){
		top[x]=tp;
		if(son[x])	dfs2(son[x],tp);
		for(PII v:g[x]){
			int y=v.fi, z=v.se;
			if(y==fa[x]||y==son[x])	continue;
			dfs2(y,y);
		}
	}
	int lca(int x,int y){
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]])	swap(x,y);
			x=fa[top[x]];
		}
		if(dep[x]>dep[y])	swap(x,y);
		return x;
	}
	int dis(int x,int y){
		int l=lca(x,y);
		return dist[x]+dist[y]-2*dist[l];
	}
}

namespace build{
	int maxx[N],siz[N],fa[N],sum,root;
	bool vis[N];
	void calsiz(int x,int fat){
		siz[x] = 1, maxx[x] = 0;
		for(PII v:g[x]){
			int y=v.fi, z=v.se;
			if(vis[y]||y==fat)	continue;
			calsiz(y,x);
			siz[x]+=siz[y]; maxx[x]=max(maxx[x],siz[y]);
		}
		maxx[x]=max(maxx[x],sum-siz[x]);
		if(maxx[x]<maxx[root])	root=x;
	}
	void dfz(int x){
		vis[x]=true;
		for(PII v:g[x]){
			int y=v.fi, z=v.se;
			if(vis[y])	continue;
			sum=siz[y], maxx[root=0]=INF;
			calsiz(y,-1), calsiz(root,-1);
			fa[root]=x;
			dfz(root);
		}
	}
}

int sum1[N], sum2[N], siz1[N], siz2[N];

void update(int x,int k){
	for(int i=x;i;i=build::fa[i]){
		int dis=tc::dis(x,i);
		sum1[i]+=k*dis, siz1[i]+=k;
	}
	for(int i=x;build::fa[i];i=build::fa[i]){
		int dis=tc::dis(build::fa[i],x);
		sum2[i]+=k*dis, siz2[i]+=k;
	}
}
int caldis(int x){
	int ans=sum1[x];
	for(int i=x;build::fa[i];i=build::fa[i]){
		ans+=sum1[build::fa[i]];
		ans-=sum2[i];
		ans+=tc::dis(build::fa[i],x)*(siz1[build::fa[i]]-siz2[i]);
	}
	return ans;
}
int query(int x){
	// DBG;
	// cout<<x<<" "<<caldis(x)<<endl;
	int ans = caldis(x);
	for(PII v:g[x]){
		int y=v.fi, z=v.se;
		if(caldis(y)<ans)	return query(y);
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>q;
	for(int i=1,x,y,z;i<n;++i)	cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
	tc::dfs1(1,0), tc::dfs2(1,1);

	// for(int i=1;i<=n;++i)
	// 	cout<<i<<" "<<tc::siz[i]<<" "<<tc::son[i]<<" "<<tc::fa[i]<<" "<<tc::top[i]<<" "<<tc::dist[i]<<endl;

	build::sum=n, build::maxx[build::root=0]=INF;
	build::calsiz(1,-1), build::calsiz(build::root,-1);
	int root=build::root;
	build::dfz(root);

	// cout<<root<<endl;
	// for(int i=1;i<=n;++i)	cout<<build::fa[i]<<" ";
	// cout<<endl;

	while(q--){
		int x,k; cin>>x>>k;
		update(x,k);
		cout<<query(root)<<endl;
		// for(int i=1;i<=n;++i){
		// 	cout<<sum1[i]<<" "<<siz1[i]<<" "<<sum2[i]<<" "<<siz2[i]<<endl;
		// }
	}
	return 0;
}