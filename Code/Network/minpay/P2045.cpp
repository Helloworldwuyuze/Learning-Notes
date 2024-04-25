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

int n,k,s,t,tot=-1,m,a[60][60], ans, minn;
struct edge{
	int nxt, v, cost, w;
}e[M];
int head[N];
void add(int u,int v,int w,int cost){
	e[++tot]=edge{head[u],v,cost,w};
	head[u]=tot;
}
int Hash(int x,int y){ return (x-1)*n+y; }

int dis[N],cur[N];
bool vis[N];
queue<int> q;
bool spfa(){
	for(int i=s;i<=t;++i)	dis[i]=INF, vis[i]=false;
	q.push(s), dis[s]=0;
	while(q.size()){
		int x=q.front(); q.pop();
		vis[x]=false; cur[x]=head[x];
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
		if(vis[y]==false&&dis[y]==dis[x]+cost&&(f=dfs(y,min(flow,w)))){
			e[i].w-=f, e[i^1].w+=f, flow-=f, maxflow+=f, minn+=cost*f;
			if(flow==0)	return maxflow;
		}
	}
	vis[x]=false;
	return maxflow;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	memset(head,-1,sizeof(head));
	cin>>n>>k; m=n*n; s=0, t=2*m+1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			int x=Hash(i,j);
			add(x,x+m,INF,0), add(x+m,x,0,0);
			add(x,x+m,1,-a[i][j]), add(x+m,x,0,a[i][j]);
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			int x=Hash(i,j), y=Hash(i+1,j), z=Hash(i,j+1);
			if(i!=n)	add(x+m,y,INF,0), add(y,x+m,0,0);
			if(j!=n)	add(x+m,z,INF,0), add(z,x+m,0,0);
		}
	add(0,1,k,0), add(1,0,0,0), add(2*m,t,k,0), add(t,2*m,0,0);
	while(spfa())	ans+=dfs(s,INF);
	cout<<-minn<<endl;
	return 0;
}