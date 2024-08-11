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
const int N = 1e2 + 10;
const int M = 1e5 + 10;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

int n,m,ans;
int Hash(int x,int y){ return (x-1)*m+y; }
int a[N][N],s,t,tot=-1,head[N*N];
struct edge{ int v,w,nxt; }e[M];
void add(int x,int y,int z){ e[++tot]=edge{y,z,head[x]}, head[x]=tot; }

queue<int> q;
int cur[N*N], dep[N*N];
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
	cin>>n>>m; s=0, t=n*m+1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			cin>>a[i][j]; ans+=a[i][j];
			int x=Hash(i,j);
			if((i+j)%2)	add(s,x,a[i][j]), add(x,s,0);
			else	add(x,t,a[i][j]), add(t,x,0);
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			int x=Hash(i,j);
			if((i+j)%2==0)	continue;
			for(int k=0;k<4;++k){
				int ii=i+dx[k], jj=j+dy[k];
				if(ii<=0||ii>n||jj<=0||jj>m)	continue;
				int y=Hash(ii,jj);
				add(x,y,INF), add(y,x,0);
			}
		}
	while(bfs())	ans-=dfs(s,INF);
	cout<<ans<<endl;
	return 0;
}