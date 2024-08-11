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
const int N = 5e3 + 10;
const int M = 1e5 + 10;

int n,m,s,t,minn;
int pay[M], head[N], w[M], Next[M], ver[M], tot=-1;
void add(int x,int y,int dis,int cost){
	ver[++tot]=y;
	pay[tot]=cost, w[tot]=dis;
	Next[tot]=head[x];
	head[x]=tot;
}

queue<int> q;
bool vis[N];
int dis[N], cur[N];
bool spfa(){
	for(int i=1;i<=n;++i)	dis[i]=INF, vis[i]=false;
	q.push(s), dis[s]=0;
	while(!q.empty()){
		int x=q.front(); q.pop();
		// cout<<x<<" "<<endl;
		vis[x]=false; cur[x]=head[x];
		for(int i=head[x];~i;i=Next[i]){
			int y=ver[i], z=w[i], cost=pay[i];
			if(z&&dis[y]>dis[x]+cost){
				dis[y]=dis[x]+cost;
				if(!vis[y])	q.push(y);
			}
		}
	}
	return dis[t]!=INF;
}
int dfs(int x,int flow){
	if(x==t||flow==0)	return flow;
	int maxflow=0, f;
	vis[x]=true;
	for(int &i=cur[x];~i;i=Next[i]){
		int y=ver[i], z=w[i], cost=pay[i];
		if(!vis[y]&&dis[y]==dis[x]+cost&&(f=dfs(y,min(flow,z)))){
			w[i]-=f, w[i^1]+=f, maxflow+=f, flow-=f, minn+=cost*f;
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
	cin>>n>>m>>s>>t;
	for(int i=1,x,y,dis,cost;i<=m;++i)	cin>>x>>y>>dis>>cost, add(x,y,dis,cost), add(y,x,0,-cost);
	int ans=0;
	while(spfa())	ans+=dfs(s,INF);
	cout<<ans<<" "<<minn<<endl;
	return 0;
}