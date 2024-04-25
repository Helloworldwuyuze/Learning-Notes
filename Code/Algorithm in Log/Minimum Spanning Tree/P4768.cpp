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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 4e5 + 10;
const int M = 1e6 + 10;

int n,m,x,y,l,a,T,tot,t,q,k,s;
struct edge{
	int u,v,len,hei;
	bool operator <(const edge &o) const{ return hei<o.hei;}
}e[N];
vector<int> g[N<<1];
vector<PII> v[N];
int fa[N],h[N];

int find(int x){ return x==fa[x]?fa[x]:fa[x]=find(fa[x]);}

int dis[N],vis[N];
void dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push(mk(0,s)), dis[s]=0;
	while(q.size()){
		int x=q.top().se; q.pop();
		if(vis[x])	continue;
		vis[x]=true;
		for(PII y:v[x])
			if(dis[y.fi]>dis[x]+y.se){
				dis[y.fi]=dis[x]+y.se;
				q.push(mk(dis[y.fi],y.fi));
			}
	}
}

int minn[N<<1],f[N<<1][25];
void dfs(int x,int fat){
	if(x<=n)	minn[x]=dis[x];
	f[x][0]=fat;
	for(int i=1;i<=t;++i)
		f[x][i]=f[f[x][i-1]][i-1];
	for(int y:g[x]){
		if(y==fat)	continue;
		dfs(y,x);
		minn[x]=min(minn[x],minn[y]);
	}
}

int solve(int v,int p){
	for(int i=t;i>=0;--i)
		if(h[f[v][i]]>p&&f[v][i]!=0)	v=f[v][i];
	return minn[v];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m; t=log(n)/log(2)+1;
		for(int i=1;i<=n;++i)	v[i].clear();
		for(int i=1;i<=n<<1;++i)	g[i].clear();
		for(int i=1;i<=m;++i)	cin>>x>>y>>l>>a, e[i]=edge{x,y,l,a}, v[x].pb(mk(y,l)), v[y].pb(mk(x,l));
		dijkstra(1);
		for(int i=1;i<=n<<1;++i)	fa[i]=i;
		sort(e+1,e+1+m);
		memset(h,0x3f,sizeof(h)); tot=n;
		for(int i=m;i;--i){
			int u=e[i].u, v=e[i].v;
			int fu=find(u), fv=find(v);
			if(fu==fv)	continue;
			++tot; int ft=find(tot);
			fa[fu]=fa[fv]=ft;
			g[tot].pb(fu), g[tot].pb(fv); g[fu].pb(ft), g[fv].pb(ft);
			h[tot]=e[i].hei;
			if(tot==2*n-1)	break;
		}

		// for(int i=1;i<=n*2-1;++i,cout<<endl)
		// 	for(int j:g[i])	cout<<j<<" ";

		memset(minn,0x3f,sizeof(minn));
		dfs(tot,0);
		cin>>q>>k>>s;
		int lastans=0;
		while(q--){
			int v,p; cin>>v>>p;
			v=(v+k*lastans-1)%n+1;
			p=(p+k*lastans)%(s+1);
			lastans=solve(v,p);
			cout<<lastans<<endl;
		}
	}
	return 0;
}