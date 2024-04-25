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

int n,m,ans,s,t;
struct edge{ int v,w,nxt; }e[N];
int head[N], tot=-1;
void add(int x,int y,int z){ e[++tot]=edge{y,z,head[x]}, head[x]=tot;}

queue<int> q;
int cur[N], dep[N];
bool bfs(){
	for(int i=s;i<=t;++i)	dep[i]=INF;
	dep[s]=0, q.push(s);
	while(!q.empty()){
		int x=q.front(); q.pop();
		cur[x]=head[x];
		for(int i=head[x];~i;i=e[i].nxt){
			int y=e[i].v, w=e[i].w;
			if(dep[y]==INF&&w)	dep[y]=dep[x]+1, q.push(y);
		}
	}
	return dep[t]!=INF;
}
int dfs(int x,int flow){
	if(x==t||flow==0)	return flow;
	int maxflow=0, f;
	for(int &i=cur[x];~i;i=e[i].nxt){
		int y=e[i].v, w=e[i].w;
		if(dep[y]==dep[x]+1&&(f=dfs(y,min(flow,w)))){
			e[i].w-=f, e[i^1].w+=f, flow-=f, maxflow+=f;
			if(flow==0)	return maxflow;
		}
	}
	return maxflow;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	memset(head,-1,sizeof(head));
	cin>>m>>n; s=0,t=n+1;
	int x,y;
	for(int i=1;i<=m;++i)	add(s,i,1), add(i,s,0);
	for(int i=m+1;i<=n;++i)	add(i,t,1), add(t,i,0);
	while(cin>>x>>y&&x!=-1&&y!=-1)	add(x,y,1), add(y,x,0);
	while(bfs())	ans+=dfs(s,INF);
	cout<<ans<<endl;
	for(int x=1;x<=m;++x){
		for(int i=head[x];~i;i=e[i].nxt){
			int y=e[i].v, w=e[i].w;
			if(!w&&y!=s){ cout<<x<<" "<<y<<endl; break;}
		}
	}
	return 0;
}