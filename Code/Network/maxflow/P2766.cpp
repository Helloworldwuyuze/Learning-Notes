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
const int N = 1e3 + 10;
const int M = N*N + 10;

int T,n,cnt,s,t,a[N],f[N],k;
int Next[M],ver[M],head[N],w[M],tot=-1;
int dep[N], cur[N];
bool r[N][N];
void add(int x,int y,int z){
    ver[++tot]=y;
    w[tot]=z;
    Next[tot]=head[x];
    head[x]=tot;
}

bool bfs(){
    queue<int> q;
    for(int i=s;i<=t;++i)   dep[i]=INF;
    q.push(s), dep[s]=0;
    while(q.size()){
        int x=q.front(); q.pop();
        cur[x]=head[x];
        if(x==t)    return true;
        for(int i=head[x];~i;i=Next[i]){
            int y=ver[i], z=w[i];
            if(z&&dep[y]==INF)  dep[y]=dep[x]+1, q.push(y);
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
            w[i]-=f, w[i^1]+=f, flow-=f, maxflow+=f;
            if(flow==0) return maxflow;
        }
    }
    return maxflow;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n;
    if(n==1){
        cout<<1<<endl<<1<<endl<<1<<endl;
        return 0;
    }
    for(int i=1;i<=n;++i)   cin>>a[i];
    f[1]=k=1;
    for(int i=2;i<=n;++i){
        f[i]=1;
        for(int j=1;j<i;++j)
            if(a[j]<=a[i])  f[i]=max(f[j]+1,f[i]);
        k=max(f[i],k);
        // cout<<f[i]<<" ";
    }
    // cout<<endl;
    cout<<k<<endl;

    s=0, t=n*2+1;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;++i){
        if(f[i]==1) add(s,i,1), add(i,s,0);
        if(f[i]==k) add(i+n,t,1), add(t,i+n,0);
    }
    for(int i=1;i<=n;++i)
        add(i,i+n,1), add(i+n,i,0);
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            if(f[j]==f[i]+1&&a[i]<=a[j])  add(i+n,j,1), add(j,i+n,0), r[i][j]=r[j][i]=true;
    // for(int i=1;i<=n;++i,cout<<endl)
    //     for(int j=1;j<=n;++j)
    //         cout<<r[i][j]<<" ";
    // for(int x=0;x<=n+n+1;++x,cout<<endl)
    //     for(int i=head[x];~i;i=Next[i])
    //         cout<<ver[i]<<" ";
    int ans=0;
    while(bfs())    ans+=dfs(s,INF);
    cout<<ans<<endl;

    ans=0, tot=-1, memset(head,-1,sizeof(head));
    for(int i=1;i<=n;++i){
        if(f[i]==1) add(s,i,(i==1)?INF:1), add(i,s,0);
        if(f[i]==k) add(i+n,t,(i==n)?INF:1), add(t,i+n,0);
    }
    for(int i=1;i<=n;++i)
        add(i,i+n,(i==1||i==n)?INF:1), add(i+n,i,0);
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            if(f[j]==f[i]+1&&a[i]<=a[j])  add(i+n,j,1), add(j,i+n,0);
    while(bfs())    ans+=dfs(s,INF);
    cout<<ans<<endl;
	return 0;
}