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
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n,m,a[30][50],s,t,ans,minn,id[30][50],idx;
struct edge{ int v,w,cost,nxt;}e[M];
int head[N], tot=-1;
void add(int x,int y,int w,int cost){
	e[++tot]=edge{y,w,-cost,head[x]}, head[x]=tot;
	e[++tot]=edge{x,0,cost,head[y]}, head[y]=tot;
}

queue<int> q;
int dis[N], cur[N];
bool vis[N];
bool spfa(){
	for(int i=s;i<=t;++i)	dis[i]=INF;
	q.push(s), dis[s]=0;
	while(q.size()){
		int x=q.front(); q.pop();
		cur[x]=head[x]; vis[x]=false;
		for(int i=head[x];~i;i=e[i].nxt){
			int y=e[i].v, w=e[i].w, cost=e[i].cost;
			if(w&&dis[y]>dis[x]+cost){
				dis[y]=dis[x]+cost;
				if(!vis[y])	vis[y]=true, q.push(y);
			}
		}
	}
	return dis[t]!=INF;
}
int dfs(int x,int flow){
	if(x==t||flow==0)	return flow;
	int maxflow=0, f;
	vis[x]=true;
	for(int &i=cur[x];~i;i=e[i].nxt){
		int y=e[i].v, w=e[i].w, cost=e[i].cost;
		if(!vis[y]&&dis[y]==dis[x]+cost&&(f=dfs(y,min(flow,w)))){
			e[i].w-=f, e[i^1].w+=f, flow-=f, maxflow+=f, minn+=f*cost;
			if(flow==0){vis[x]=false; return maxflow;}
		}
	}
	vis[x]=false;
	return maxflow;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>m>>n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m+i-1;++j)
			cin>>a[i][j], id[i][j]=++idx;
	tot=-1, memset(head,-1,sizeof(head)), s=ans=0, t=2*idx+1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m+i-1;++j){
			add(id[i][j],id[i][j]+idx,1,a[i][j]);
			if(i!=n)	add(id[i][j]+idx,id[i+1][j],1,0), add(id[i][j]+idx,id[i+1][j+1],1,0);
		}
	for(int i=1;i<=m;++i)
		add(s,id[1][i],1,0);
	for(int i=1;i<=n+m-1;++i)
		add(id[n][i]+idx,t,1,0);
	while(spfa())	ans+=dfs(s,INF);
	cout<<-minn<<endl;
	tot=-1, memset(head,-1,sizeof(head));
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m+i-1;++j){
			add(id[i][j],id[i][j]+idx,INF,0);
			if(i!=n)	add(id[i][j]+idx,id[i+1][j],1,a[i+1][j]), add(id[i][j]+idx,id[i+1][j+1],1,a[i+1][j+1]);
		}
	for(int i=1;i<=m;++i)
		add(s,id[1][i],1,a[1][i]);
	for(int i=1;i<=n+m-1;++i)
		add(id[n][i]+idx,t,INF,0);
	ans=minn=0;
	while(spfa())	ans+=dfs(s,INF);
	cout<<-minn<<endl;
	tot=-1, memset(head,-1,sizeof(head)), s=0, t=idx+1;
	for(int i=1;i<n;++i)
		for(int j=1;j<=m+i-1;++j)
			add(id[i][j],id[i+1][j],m,a[i+1][j]), add(id[i][j],id[i+1][j+1],m,a[i+1][j+1]);
	for(int i=1;i<=m;++i)
		add(s,id[1][i],1,a[1][i]);
	for(int i=1;i<=n+m-1;++i)
		add(id[n][i],t,INF,0);
	ans=minn=0;
	while(spfa())	ans+=dfs(s,INF);
	cout<<-minn<<endl;
	return 0;
}