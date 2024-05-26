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
const int N = 4e3 + 10;
const int M = 1e6 + 10;

int n,fst,pfst,slw,pslw,pay,s,t,minn=0;
int head[N],tot=-1;
struct edge{ int v,w,cost,nxt;}e[M];
void add(int x,int y,int z,int cost){ e[++tot]=edge{y,z,cost,head[x]}, head[x]=tot; e[++tot]=edge{x,0,-cost,head[y]}, head[y]=tot;}

int dis[N],cur[N];
bool vis[N];
queue<int> q;
bool bfs(){
	for(int i=s;i<=t;++i)	dis[i]=INF;
	q.push(s), dis[s]=0;
	while(q.size()){
		int x=q.front(); q.pop();
		cur[x]=head[x]; vis[x]=false;
		for(int i=head[x];~i;i=e[i].nxt){
			int y=e[i].v, w=e[i].w, cost=e[i].cost;
			if(w&&dis[y]>dis[x]+cost){
				dis[y]=dis[x]+cost;
				if(!vis[y])	q.push(y), vis[y]=true;
			}
		}
	}
	return dis[t]!=INF;
}
int dfs(int x,int flow){
	if(x==t||flow==0)	return flow;
	// cout<<x<<endl;
	vis[x]=true;
	int maxflow=0, f;
	for(int &i=cur[x];~i;i=e[i].nxt){
		int y=e[i].v, w=e[i].w, cost=e[i].cost;
		// cout<<y<<" "<<w<<" "<<cost<<endl;
		if(!vis[y]&&dis[y]==dis[x]+cost&&(f=dfs(y,min(flow,w)))){
			e[i].w-=f, e[i^1].w+=f, flow-=f, maxflow+=f, minn+=cost*f;
			if(flow==0)	return maxflow;
		}
	}
	// cout<<"END"<<x<<" "<<minn<<endl;
	vis[x]=false;
	return maxflow;
}

int main(){
	memset(head,-1,sizeof(head));
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n; s=0, t=n+n+1;
	for(int i=1,x;i<=n;++i)	cin>>x, add(i,t,x,0), add(s,i+n,x,0);
	cin>>pay>>fst>>pfst>>slw>>pslw;
	for(int i=1;i<=n;++i){
		add(s,i,INF,pay);
		if(i!=n)	add(i+n,i+n+1,INF,0);
		if(i+fst<=n)	add(i+n,i+fst,INF,pfst);
		if(i+slw<=n)	add(i+n,i+slw,INF,pslw);
	}
	for(int x=s;x<=t;++x){
		// cout<<"###"<<x<<"###"<<endl;
		for(int i=head[x];~i;i=e[i].nxt)
			cout<<e[i].v<<" "<<e[i].w<<" "<<e[i].cost<<endl;
	}
	int ans=0;
	// cout<<"QAQ"<<endl;
	while(bfs())	cout<<ans<<endl, ans+=dfs(s,INF);
	cout<<minn<<endl;
	return 0;
}