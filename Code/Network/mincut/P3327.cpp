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

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 40 + 10;
const int M = 3e6 + 10;
const int MOD = 1e9 + 7;

int p,q,r,s,t,sum,d;
struct edge{ int v,w,nxt;}e[M];
int head[M], tot=-1;
int Hash(int x,int y,int z){ return (z-1)*p*q+(x-1)*q+y;}
void add(int x,int y,int w){ e[++tot]=edge{y,w,head[x]}, head[x]=tot;}
int a[N][N][N];

queue<int> Q;
int cur[M], dep[M];
bool bfs(){
    for(int i=s;i<=t;++i)   dep[i]=INF;
    dep[s]=0, Q.push(s);
    while(Q.size()){
        int x=Q.front(); Q.pop();
        cur[x]=head[x];
        for(int i=head[x];~i;i=e[i].nxt){
            int y=e[i].v, w=e[i].w;
            if(w&&dep[y]==INF)  dep[y]=dep[x]+1, Q.push(y);
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
    cin>>p>>q>>r>>d; s=0, t=p*q*r+1;
    for(int k=1;k<=r;++k)
        for(int i=1;i<=p;++i)
            for(int j=1;j<=q;++j)
                cin>>a[i][j][k];
    for(int i=1;i<=p;++i)
        for(int j=1;j<=q;++j)
            add(s,Hash(i,j,1),INF), add(Hash(i,j,1),s,0), add(Hash(i,j,r),t,a[i][j][r]), add(t,Hash(i,j,r),0);
    for(int k=d+1;k<=r;++k)
        for(int i=1;i<=p;++i)
            for(int j=1;j<=q;++j){
                int x=Hash(i,j,k);
                for(int l=0;l<4;++l){
                    int ii=i+dx[l], jj=j+dy[l];
                    if(ii<=0||ii>p||jj<=0||jj>q)    continue;
                    int y=Hash(ii,jj,k-d);
                    add(x,y,INF), add(y,x,0);
                }
            }
    for(int k=1;k<r;++k)
        for(int i=1;i<=p;++i)
            for(int j=1;j<=q;++j)
                add(Hash(i,j,k),Hash(i,j,k+1),a[i][j][k]), add(Hash(i,j,k+1),Hash(i,j,k),0);
    int ans=0;
    while(bfs())    ans+=dfs(s,INF);
    cout<<ans<<endl;
	return 0;
}

