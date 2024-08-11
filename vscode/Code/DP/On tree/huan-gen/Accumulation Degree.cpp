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
const int N = 1e6 + 10;
const int M = 1e6 + 10;

int n,root,siz[N],f[N];
vector<PII> g[N];

void dfs1(int x,int fa){
    for(int i=0;i<g[x].size();++i){
        PII y=g[x][i];
        if(y.fi==fa)   continue;
        dfs1(y.fi,x);
        f[x]+=min(y.se, f[y.fi]);
    }
    if(g[x].size()==1&&x!=root) f[x]=g[x][0].se;
}
void dfs2(int x,int fa,int edge){
    if(x!=root)    f[x]+=min(f[fa]-min(f[x],edge),edge);
    for(int i=0;i<g[x].size();++i){
        PII y=g[x][i];
        if(y.fi==fa)    continue;
        dfs2(y.fi,x,y.se);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T; cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;++i){
            f[i]=0;
            while(g[i].size())  g[i].erase(g[i].begin());
        }
        for(int i=1,x,y,z;i<n;++i)    cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
        if(n==2){ cout<<g[1][0].se<<endl; continue;}
        for(int i=1;i<=n;++i)
            if(g[i].size()!=1){ root=i; break;}
        dfs1(root,0); dfs2(root,0,0);
        int ans=0;
        for(int i=1;i<=n;++i)   ans=max(ans,f[i]);
        cout<<ans<<endl;
    }
    return 0;
}