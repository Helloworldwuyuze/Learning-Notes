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
const int N = 5e5 + 10;
const int M = 1e6 + 10;

int n,m,s,t,ans;
struct Plant{
    int score,attack;
    vector<int> att;
}p[N];
struct edge{
    int v,w,nxt;
}e[M];
int head[N], tot=-1;
bool BeAttacked[N];
void add(int x,int y,int z){ e[++tot]=edge{y,z,head[x]}, head[x]=tot;}
int Hash(int x,int y){ return (x-1)*m+y;}

vector<int> g[N];
bool vis[N];
int du[N];
queue<int> q;
void topu(){
    for(int i=1;i<=n*m;++i)
        if(!du[i])  q.push(i);
    while(q.size()){
        int x=q.front(); q.pop();
        vis[x]=true;
        for(int y:g[x])
            if(--du[y]==0)  q.push(y);
    }
}

int cur[N], dep[N];
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
            e[i].w-=f, e[i^1].w+=f, flow-=f, maxflow+=f;
            if(flow==0) return maxflow;
        }
    }
    return maxflow;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    memset(head,-1,sizeof(head));
    cin>>n>>m; s=0, t=n*m+1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            int score, attack, x, y, id=Hash(i,j);
            cin>>score>>attack;
            p[id].score=score, p[id].attack=attack;
            while(attack--){
                cin>>x>>y; ++x, ++y;
                int _id=Hash(x,y);
                p[id].att.pb(_id), g[id].pb(_id), du[_id]++;
            }
            if(j!=m)    g[id+1].pb(id), du[id]++;
        }
    }
    for(int x=1;x<=n*m;++x)
        for(int y:g[x]) cout<<x<<" "<<y<<endl;
    topu();
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            int id=Hash(i,j);
            if(!vis[id])    continue;
            for(auto _id:p[id].att) add(_id,id,INF), add(id,_id,0);
            if(j!=m){
                int _id=Hash(i,j+1);
                add(id,_id,INF), add(_id,id,0);
            }
            if(p[id].score>=0)  add(s,id,p[id].score), add(id,s,0), ans+=p[id].score;
            else    add(id,t,-p[id].score), add(t,id,0);
        }
    }
    while(bfs())    ans-=dfs(s,INF);
    cout<<ans<<endl;
	return 0;
}