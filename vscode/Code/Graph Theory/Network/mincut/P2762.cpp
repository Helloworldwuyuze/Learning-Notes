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
const int M = 1e4 + 10;

int head[N], tot=-1;
struct edge{
    int v,w,nxt;
}e[M];
void add(int x,int y,int z){
    e[++tot]=edge{y,z,head[x]};
    head[x]=tot;
}
int n,m,a[N],b[N],tool,s,t,ans;
char tools[M];
bool tl[N], ep[N];

queue<int> q;
int dep[N], cur[N];
bool bfs(){
    for(int i=s;i<=t;++i)   dep[i]=INF;
    dep[s]=0, q.push(s);
    while(q.size()){
        int x=q.front(); q.pop();
        cur[x]=head[x];
        for(int i=head[x];~i;i=e[i].nxt){
            int y=e[i].v, w=e[i].w;
            if(w&&dep[y]==INF) dep[y]=dep[x]+1, q.push(y);
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
            e[i].w-=f, e[i^1].w+=f, flow-=f, maxflow+=f;
            if(flow==0) return maxflow;
        }
    }
    return maxflow;
}

int main(){
	memset(head,-1,sizeof(head));
    cin>>n>>m; s=0, t=n+m+1;
    for(int i=1;i<=n;++i){
        cin>>a[i]; add(s,i,a[i]), add(i,s,0); ans+=a[i];
        int used=1;
        memset(tools,0,sizeof(tools));
        cin.getline(tools,10000);
        while(sscanf(tools+used, "%d", &tool)==1){
            add(i,tool+n,INF), add(tool+n,i,0);
            if(tool==0) ++used;
            else    while(tool) ++used, tool/=10;
            ++used;
        }
    }
    for(int i=1;i<=m;++i)   cin>>b[i], add(i+n,t,b[i]), add(t,i+n,0);
    while(bfs())    ans-=dfs(s,INF);
    bfs();
    for(int i=head[s];~i;i=e[i].nxt)
        if(e[i].w)  ep[e[i].v]=true;
    for(int i=head[t];~i;i=e[i].nxt)
        if(!e[i].w) tl[e[i].v-n]=true;
    for(int i=1;i<=n;++i)
        if(dep[i]!=INF) cout<<i<<" ";
    cout<<endl;
    for(int i=1;i<=m;++i)
        if(dep[i+n]!=INF)   cout<<i<<" ";
    cout<<endl;
    cout<<ans<<endl;
	return 0;
}