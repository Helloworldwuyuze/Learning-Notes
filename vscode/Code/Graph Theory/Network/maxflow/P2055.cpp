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
const int N = 100 + 10;
const int M = 2e4 + 10;

int T,n,cnt,s,t;
bool sch[N], lft[N], rtv[N][N];
int Next[M],ver[M],head[N],w[M],tot=-1;
int dep[N], cur[N];
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
    cin>>T;
    while(T--){
        cin>>n; cnt=n;
        memset(head,-1,sizeof(head));
        memset(sch,0,sizeof(sch)), memset(lft,0,sizeof(lft)), memset(rtv,0,sizeof(rtv));
        tot=-1;
        for(int i=1;i<=n;++i)   cin>>sch[i];
        for(int i=1;i<=n;++i)   cin>>lft[i], cnt-=(lft[i]==1)&&sch[i];
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)   cin>>rtv[i][j];
        s=0, t=n*2+1;
        for(int i=1;i<=n;++i){
            if(sch[i])  add(i+n,t,1), add(t,i+n,0);
            if(!(sch[i]&&lft[i]==1))    add(s,i,1), add(i,s,0);
            if(sch[i]&&lft[i]!=1)  add(i,i+n,1), add(i+n,i,0);
            for(int j=1;j<=n;++j)
                if(rtv[i][j]&&sch[j])   add(i,j+n,1), add(j+n,i,0);
        }
        // for(int i=s;i<=t;++i,cout<<endl)
        //     for(int j=head[i];~j;j=Next[j])
        //         cout<<ver[j]<<" ";
        // for(int i=1;i<=n;++i) add(s,i,1), add(i,s,0);
        // for(int i=n+1;i<=n*2;++i)   add(i,t,1), add(t,i,0);
        int ans=0;
        while(bfs())    ans+=dfs(s,INF);
        if(ans==cnt)    cout<<"^_^"<<endl;
        else    cout<<"T_T"<<endl;
    }
	return 0;
}