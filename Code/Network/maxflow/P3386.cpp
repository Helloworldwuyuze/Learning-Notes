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
const int N = 1e3 + 10;
const int M = 2e5 + 10;

int head[N], ver[M], w[M], Next[M], tot=-1;
int n1,n2,m,s,t, dep[N], cur[N], ans;
void add(int x,int y,int z){
    ver[++tot]=y;
    w[tot]=z;
    Next[tot]=head[x];
    head[x]=tot;
}

queue<int> q;
bool bfs(){
    for(int i=s;i<=t;++i)   dep[i]=INF;
    q.push(s), dep[s]=0;
    while(q.size()){
        int x=q.front(); q.pop();
        cur[x]=head[x];
        if(x==t)    return true;
        for(int i=head[x];~i;i=Next[i]){
            int y=ver[i], z=w[i];
            if(z&&dep[y]==INF){
                dep[y]=dep[x]+1;
                q.push(y);
            }
        }
    }
    return false;
}
int dfs(int x,int flow){
    if(x==t||flow==0)   return flow;
    int f, maxflow=0;
    for(int &i=cur[x];~i;i=Next[i]){
        int y=ver[i], z=w[i];
        if(dep[y]==dep[x]+1&&(f=dfs(y,min(flow,z)))){
            flow-=f, maxflow+=f, w[i]-=f, w[i^1]+=f;
            if(flow==0) return maxflow;
        }
    }
    return maxflow;
}

signed main(){
	memset(head,-1,sizeof(head));
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n1>>n2>>m; s=0, t=n1+n2+1;
    for(int i=1,x,y,z;i<=m;++i) cin>>x>>y, y+=n1, add(x,y,1), add(y,x,0);
    for(int i=1;i<=n1;++i)  add(s,i,1), add(i,s,0);
    for(int i=n1+1;i<=n1+n2;++i)    add(i,t,1), add(t,i,0);
    while(bfs())    ans+=dfs(s,INF);
    cout<<ans<<endl;
	return 0;
}