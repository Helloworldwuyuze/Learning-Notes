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
const int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e4 + 10;
const int M = 1e7 + 10;

int n,ans;
vector<PII> g[N];

int maxx[N],siz[N],root,sum;
bool vis[N];
void calsiz(int x,int fa){
    siz[x]=1, maxx[x]=0;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(vis[y]||y==fa)   continue;
        calsiz(y,x);
        siz[x]+=siz[y], maxx[x]=max(maxx[x],siz[y]);
    }
    maxx[x]=max(maxx[x],sum-siz[x]);
    if(maxx[x]<maxx[root])  root=x;
}

int s[3],dis[N];
vector<int> t;
void caldis(int x,int fa){
    t.pb(x);
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(y==fa||vis[y])   continue;
        dis[y]=(dis[x]+z)%3;
        caldis(y,x);
    }
}

void dfz(int x){
    vis[x]=true;
    s[0]=1, s[1]=s[2]=0;
    // cout<<"###"<<x<<"###"<<endl;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(vis[y])  continue;
        dis[y]=z%3; t.clear();
        caldis(y,x);
        for(int j=0;j<t.size();++j)
            ans+=s[(3-dis[t[j]])%3]*2;
        // cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<endl;
        for(int j=0;j<t.size();++j)
            s[dis[t[j]]]++;
        // cout<<endl;
    }
    // cout<<ans<<endl;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(vis[y])  continue;
        sum=siz[y], maxx[root=0]=INF;
        calsiz(y,-1), calsiz(root,-1);
        dfz(root);
    }
}

int gcd(int x,int y){ return y==0?x:gcd(y,x%y); }

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1,x,y,z;i<n;++i)  cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
    sum=n, maxx[root=0]=INF;
    calsiz(1,-1), calsiz(root,-1);
    dfz(root);
    int x=gcd(ans+n,n*n);
    cout<<(ans+n)/x<<"/"<<n*n/x<<endl;
    return 0;
}

