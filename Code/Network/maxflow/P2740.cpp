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
const int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e4 + 10;
const int M = 1e4 + 10;

int n,m,s,t;
int Next[M], ver[M], w[M], head[N], tot=-1;
int ans, dep[N], gap[N], cur[N];
void add(int x,int y,int z){
    ver[++tot]=y;
    w[tot]=z;
    Next[tot]=head[x];
    head[x]=tot;
}
vector<int> v[N];

queue<int> q;
void bfs(){
    memset(dep,-1,sizeof(dep));
    q.push(t), dep[t]=0; gap[dep[t]]++;
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int y:v[x]){
            if(dep[y]==-1){
                dep[y]=dep[x]+1;
                q.push(y); gap[dep[y]]++;
            }
        }
    }
}

int dfs(int x,int flow){
    if(x==t||flow==0)   return flow;
    int maxflow=0, f;
    for(int i=cur[x];~i;i=Next[i]){
        cur[x]=i;
        int y=ver[i], z=w[i];
        if(dep[y]==dep[x]-1&&(f=dfs(y,min(flow-maxflow,z)))){
            maxflow+=f;
            w[i]-=f, w[i^1]+=f;
            if(flow==maxflow) return maxflow;
        }
    }
    --gap[dep[x]];
    if(gap[dep[x]]==0)  dep[s]=n+1;
    ++dep[x];
    ++gap[dep[x]];
    return maxflow;
}

signed main(){
	memset(head,-1,sizeof(head));
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>m>>n; s=1, t=n;
    for(int i=1,x,y,z;i<=m;++i) cin>>x>>y>>z, add(x,y,z), add(y,x,0), v[y].pb(x);
    bfs(); int f;
    while(dep[s]<n){
        for(int i=1;i<=n;++i)   cur[i]=head[i];
        ans+=dfs(s,INF);
    }
    cout<<ans<<endl;
	return 0;
}