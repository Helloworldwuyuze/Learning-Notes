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
const int N = 5e5 + 10;
const int M = 1e6 + 10;

int n,m,a[N];
vector<int> v[N];
int fa[N],dep[N],siz[N],son[N],dfn[N],rk[N],idx,top[N];

void dfs1(int x,int fat){
    fa[x]=fat, dep[x]=dep[fat]+1;
    siz[x]=1;
    for(int y:v[x]){
        dfs1(y,x);
        siz[x]+=siz[y];
        if(siz[y]>siz[son[x]])  son[x]=y;
    }
}

void dfs2(int x,int tp){
    top[x]=tp, dfn[x]=++idx, rk[idx]=x;
    if(son[x])  dfs2(son[x],tp);
    for(int y:v[x])
        if(y!=son[x])   dfs2(y,y);
}

int t[N];
#define lowbit(x) (x&-x)
void update(int x,int k){ for(int i=x;i<=n;i+=lowbit(i))  t[i]+=k;}
int query(int x){ int ans=0; for(int i=x;i;i-=lowbit(i))  ans+=t[i]; return ans;}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1,x;i<=n;++i){
        cin>>a[i];
        if(i!=1)    cin>>x, v[x].pb(i);
    }
    dfs1(1,0); dfs2(1,1);
    // for(int i=1;i<=n;++i)
    //     cout<<fa[i]<<" "<<son[i]<<" "<<dep[i]<<" "<<siz[i]<<" "<<dfn[i]<<" "<<top[i]<<endl;
    for(int i=1;i<=n;++i)   update(dfn[i],a[i]), update(dfn[i]+1,-a[i]);
    while(m--){
        char op;
        int a,x;
        cin>>op;
        if(op=='p')
            cin>>a>>x, update(dfn[a]+1,x), update(dfn[a]+siz[a],-x);
        else    cin>>a, cout<<query(dfn[a])<<endl;
    }
    return 0;
}