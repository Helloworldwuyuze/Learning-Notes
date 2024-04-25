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

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;
const int M = 1e6 + 10;

#define tran(x) (f[x][0]+z-max(f[x][0],f[x][1]+len[x]))

int n,f[N][2],len[N],fa[N],ans;
vector<int> son[N], dp[N][2], mx[N];

int Next[M],ver[M],w[M],head[N],tot=-1;
void add(int x,int y,int z){
    ver[++tot]=y;
    w[tot]=z;
    Next[tot]=head[x];
    head[x]=tot;
}

void dfs1(int x,int fat){
    f[x][0]=0, f[x][1]=-INF;
    int maxx1=-INF,maxx2=-INF;
    for(int i=head[x];~i;i=Next[i]){
        int y=ver[i], z=w[i];
        if(y==fat)   continue;

        son[x].pb(y);
        fa[y]=x, len[y]=z; 
        dfs1(y,x);
        f[x][0]+=max(f[y][0],f[y][1]+z);
        if(tran(y)>maxx1)   maxx2=maxx1, maxx1=tran(y);
        else if(tran(y)>maxx2)  maxx2=tran(y);
    }
    f[x][1]=f[x][0]+maxx1;
    for(int i=head[x];~i;i=Next[i]){
        int y=ver[i], z=w[i];
        if(y==fat)    continue;

        dp[x][0].pb(f[x][0]-max(f[y][0],f[y][1]+z));
        if(tran(y)==maxx1)  dp[x][1].pb(dp[x][0].back()+maxx2), mx[x].pb(maxx2);
        else    dp[x][1].pb(dp[x][0].back()+maxx1), mx[x].pb(maxx1);
    }
}

void dfs2(int x){
    for(int i=0;i<son[x].size();++i){
        int y=son[x][i], z=len[y];
        f[x][0]=dp[x][0][i], f[x][1]=dp[x][1][i];
        if(fa[x]){
           f[x][0]+=max(f[fa[x]][0],f[fa[x]][1]+len[x]);
           f[x][1]=f[x][0]+max(mx[x][i],f[fa[x]][0]+len[x]-max(f[fa[x]][0],f[fa[x]][1]+len[x]));
        }
        ans=max(ans,f[y][0]+max(f[x][0],f[x][1]+z));
        dfs2(y);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    memset(head,-1,sizeof(head));
    cin>>n;
    for(int i=1,x,y,z;i<n;++i)  cin>>x>>y>>z, add(x,y,z), add(y,x,z);
    dfs1(1,0);
    // for(int i=1;i<=n;++i)
    //     cout<<f[i][0]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;++i)
    //     cout<<f[i][1]<<" ";
    // cout<<endl;
    dfs2(1);
    cout<<ans<<endl;
    return 0;
}
/*
95 171 0 182 0 144 179 0 0 0
150 179 -1061109567 174 -1061109567 178 145 -1061109567 -1061109567 -1061109567
*/
