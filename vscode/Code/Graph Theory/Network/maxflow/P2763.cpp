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
const int N = 1e3 + 10;
const int M = 1e6 + 10;

int k,n,m,p,rq[N],x,s,t,sum;
int head[N], tot=-1;
struct edge{ int v,w,nxt;}e[M];
void add(int x,int y,int z){ e[++tot]=edge{y,z,head[x]}, head[x]=tot;}
set<int> st[N];

queue<int> q;
int cur[N], dep[N];
bool bfs(){
    for(int i=s;i<=t;++i)   dep[i]=INF;
    q.push(s), dep[s]=0;
    while(q.size()){
        int x=q.front(); q.pop();
        cur[x]=head[x];
        for(int i=head[x];~i;i=e[i].nxt)
            if(dep[e[i].v]==INF&&e[i].w)    dep[e[i].v]=dep[x]+1, q.push(e[i].v);
    }
    return dep[t]!=INF;
}
int dfs(int x,int flow){
    if(x==t||flow==0)   return flow;
    int maxflow=0, f;
    for(int i=head[x];~i;i=e[i].nxt){
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
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>k>>n; s=0, t=k+n+1;
    for(int i=1,x;i<=k;++i)   cin>>x, add(i+n,t,x), add(t,i+n,0), sum+=x;
    for(int i=1;i<=n;++i){
        cin>>p; add(s,i,1), add(i,s,0);
        while(p--)  cin>>x, add(i,x+n,1), add(x+n,i,0);
    }
    int ans=0;
    while(bfs())    ans+=dfs(s,INF);
    if(ans==sum){
        for(int x=1;x<=n;++x)
            for(int i=head[x];~i;i=e[i].nxt)
                if(e[i].w==0&&e[i].v!=s){st[e[i].v-n].insert(x); break;}
        for(int i=1;i<=k;++i){
            cout<<i<<": ";
            for(int j:st[i])    cout<<j<<" ";
            cout<<endl;
        }
    }else   cout<<"No Solution!"<<endl;
	return 0;
}