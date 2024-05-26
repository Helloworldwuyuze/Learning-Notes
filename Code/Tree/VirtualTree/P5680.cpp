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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n,m,k,q;
vector<PII> graph[N], g[N], vir[N];

namespace BIT{
	int b[N];
	#define lowbit(x) (x&-x)
	void update(int x,int k){ for(int i=x;i<=n;i+=lowbit(i))	b[i]+=k;}
	int query(int x){int ans=0;for(int i=x;i;i-=lowbit(i))	ans+=b[i]; return ans;}
	#undef lowbit
}

namespace cut{
	int dfn[N], siz[N], top[N], dep[N], fa[N], son[N], d[N], idx;
	void dfs1(int x,int fat){
		fa[x]=fat; siz[x]=1;
		for(PII y:g[x]){
			if(y.fi==fat)	continue;
			dep[y.fi]=dep[x]+1; d[y.fi]=d[x]+y.se;
			dfs1(y.fi,x);
			siz[x]+=siz[y.fi];
			if(siz[y.fi]>siz[son[x]])	son[x]=y.fi;
		}
	}
	void dfs2(int x,int tp){
		top[x]=tp, dfn[x]=++idx;
		if(son[x])	dfs2(son[x],tp);
		for(PII y:g[x])
			if(y.fi!=fa[x]&&y.fi!=son[x])	dfs2(y.fi,y.fi);
	}
	int lca(int x,int y){
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]])	swap(x,y);
			x=fa[top[x]];
		}
		return dep[x]<dep[y]?x:y;
	}
	int dis(int x,int y){ return d[x]+d[y]-2*d[lca(x,y)]; }
}

priority_queue<PII, vector<PII>, greater<PII> > Q;
int dis[N], pre[N];
bool vis[N];
void dijkstra(int s){
	for(int i=1;i<=n;++i)	dis[i]=pre[i]=INF;
	dis[s]=pre[s]=0, Q.push(mk(dis[s],s));
	while(!Q.empty()){
		int p=Q.top().se; Q.pop();
		if(vis[p])	continue;
		vis[p]=true;
		for(auto y:graph[p])
			if(dis[y.fi]>dis[p]+y.se||dis[y.fi]==dis[p]+y.se&&p<pre[y.fi]){
				dis[y.fi]=dis[p]+y.se; pre[y.fi]=p;
				Q.push(mk(dis[y.fi],y.fi));
			}
	}
}

set<int> ques;
bool tag[N], flag[N];
int a[N], st[N], top, op, num, minn[N];

bool cmp(int x,int y){ return cut::dfn[x]<cut::dfn[y];}
void build(){
	sort(a+1,a+1+num,cmp);
	st[top=1]=k;
	for(int i=1;i<=num;++i){
		if(a[i]==k)	continue;
		int lca=cut::lca(st[top],a[i]);
		// cerr<<i<<endl;
		if(lca!=st[top]){
			while(cut::dfn[st[top-1]]>cut::dfn[lca])	vir[st[top-1]].pb(mk(st[top],cut::dis(st[top],st[top-1]))), --top;
			if(cut::dfn[st[top-1]]<cut::dfn[lca])	vir[lca].pb(mk(st[top],cut::dis(lca,st[top]))), st[top]=lca;
			else	vir[lca].pb(mk(st[top],cut::dis(st[top],lca))), --top;
		}
		st[++top]=a[i];
	}
	while(top>1)	vir[st[top-1]].pb(mk(st[top],cut::dis(st[top-1],st[top]))), --top;
}

void dfs1(int x){
	for(PII y:vir[x]){
		minn[y.fi]=min(minn[x],y.se);
		dfs1(y.fi);
	}
}
bool fl=false;
int dfs2(int x){
	int sum=0;
	for(PII y:vir[x]){
		if(BIT::query(cut::dfn[y.fi]+cut::siz[y.fi]-1)-BIT::query(cut::dfn[y.fi]-1)==0)	continue;
		sum+=dfs2(y.fi); fl=true;
	}
	if(tag[x]&&x!=k)	return minn[x];
	else	return min(minn[x],sum);
}
void init(int x){
	for(PII y:vir[x])	init(y.fi);
	minn[x]=0, vir[x].clear();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>k>>q;
	for(int i=1,x,y,z;i<=m;++i)	cin>>x>>y>>z, graph[x].pb(mk(y,z)), graph[y].pb(mk(x,z));
	dijkstra(k);
	for(int i=1;i<=n;++i)
		if(pre[i])	g[i].pb(mk(pre[i],dis[i]-dis[pre[i]])), g[pre[i]].pb(mk(i,dis[i]-dis[pre[i]]));
	cut::dfs1(k,0), cut::dfs2(k,k);
	for(int i=1;i<=q;++i){
		cin>>op>>num;
		for(int i=1;i<=num;++i)	cin>>a[i];
		if(op==0){
			for(int i=1;i<=num;++i){
				// cerr<<cut::dfn[a[i]]<<endl;
				tag[a[i]]=!tag[a[i]];
				if(ques.find(a[i])!=ques.end())	ques.erase(a[i]), BIT::update(cut::dfn[a[i]],-1);
				else	ques.insert(a[i]), BIT::update(cut::dfn[a[i]],1);
			}
		}else{
			build(); fl=false;
			// for(int x=1;x<=n;++x){
				// cerr<<"###"<<x<<"###"<<endl;
				// for(PII y:vir[x])	cerr<<y.fi<<" "<<y.se<<endl;
			// }
			// cerr<<"QAQ"<<endl;
			minn[k]=INF; dfs1(k);
			// for(int i=1;i<=n;++i)	cout<<minn[i]<<" ";
			// cout<<endl;
			int ans=dfs2(k);
			if(ans==0)	cout<<-1<<endl;
			else	cout<<ans<<endl;
			init(k);
		}
	}
	return 0;
}