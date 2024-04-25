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
const int N = 500 + 10;
const int M = 1e5 + 10;

int n,m,c[N],r[N],s,t,ans,sum;
int head[N], tot=-1;
bool vis[N];
struct edge{ int v,w,nxt; }e[M];
void add(int x,int y,int z){ e[++tot]=edge{y,z,head[x]}, head[x]=tot;}

int dep[N], cur[N];
queue<int> q;
bool bfs(){
    for(int i=s;i<=t;++i)   dep[i]=INF;
    dep[s]=0, q.push(s);
    while(q.size()){
        int x=q.front(); q.pop();
        cur[x]=head[x];
        for(int i=head[x];~i;i=e[i].nxt){
            int y=e[i].v, w=e[i].w;
            if(w&&dep[y]==INF)  dep[y]=dep[x]+1, q.push(y);
        }
    }
    return dep[t]!=INF;
}

int dfs(int x,int flow){
    if(x==t||flow==0)   return flow;
    int maxflow=0, f;
    for(int &i=cur[x];~i;i=e[i].nxt){
        int y=e[i].v, w=e[i].w;
        if(dep[y]==dep[x]+1&&(f=dfs(y,min(flow,w)))){
            flow-=f, maxflow+=f, e[i].w-=f, e[i^1].w+=f;
            if(flow==0) return maxflow;
        }
    }
    return maxflow;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    memset(head,-1,sizeof(head));
    cin>>n>>m; s=0, t=n+m+1;
    for(int i=1;i<=n;++i)   cin>>r[i], add(s,i,r[i]), add(i,s,0), sum+=r[i];
    for(int i=1;i<=m;++i)   cin>>c[i], add(i+n,t,c[i]), add(t,i+n,0);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            add(i,j+n,1), add(j+n,i,0);
    while(bfs())    ans+=dfs(s,INF);
    if(ans==sum){
        cout<<1<<endl;
        for(int i=1;i<=n;++i){
            memset(vis,0,sizeof(vis));
            for(int j=head[i];~j;j=e[j].nxt)
                if(e[j].v!=s&&!e[j].w)   vis[e[j].v-n]=true;
            for(int i=1;i<=m;++i)
                if(vis[i])  cout<<i<<" ";
            cout<<endl;
        }
    }else   cout<<0<<endl;
	return 0;
}