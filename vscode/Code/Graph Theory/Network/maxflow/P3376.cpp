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
const int N = 2e2 + 10;
const int M = 1e4 + 10;

int n,m,s,t;
int Next[M], head[N], w[M], ver[M], tot=-1;
void add(int x,int y,int z){
	ver[++tot]=y;
	w[tot]=z;
	Next[tot]=head[x];
	head[x]=tot;
}
int ans,dep[N],cur[N];

queue<int> q;
bool bfs(){
	while(!q.empty())	q.pop();
	for(int i=1;i<=n;++i)	dep[i]=INF;
	cur[s]=head[s], q.push(s), dep[s]=0;
	while(!q.empty()){
		int p=q.front(); q.pop();
		if(p==t)	return true;
		for(int i=head[p];~i;i=Next[i]){
			int y=ver[i], z=w[i];
			if(z>0&&dep[y]==INF){
				q.push(y);
				cur[y]=head[y]; dep[y]=dep[p]+1;
			}
		}
	}
	return false;
}
int dfs(int x,int flow){
	if(x==t)	return flow;
	int maxflow=0;
	for(int i=cur[x];~i&&flow;i=Next[i]){
		cur[x]=i;
		int y=ver[i], z=w[i], k;
		if(dep[y]==dep[x]+1&&(k=dfs(y,min(flow,z)))){
			w[i]-=k, w[i^1]+=k;
			maxflow+=k, flow-=k;
		}
	}
	return maxflow;
}

signed main(){
	memset(head,-1,sizeof(head));
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>s>>t;
	for(int i=1,x,y,z;i<=m;++i)	cin>>x>>y>>z, add(x,y,z), add(y,x,0);
	while(bfs())	ans+=dfs(s,INF);
	cout<<ans<<endl;
	return 0;
}