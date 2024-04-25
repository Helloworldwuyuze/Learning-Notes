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
typedef pair<int,bool> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;

int n,k,ans;
vector<int> g[N];

int sum,maxx[N],root,siz[N];
bool vis[N];
void calsiz(int x,int fa){
    siz[x]=1, maxx[x]=0;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(y==fa||vis[y])   continue;
        calsiz(y,x);
        siz[x]+=siz[y], maxx[x]=max(maxx[x],siz[y]);
    }
    maxx[x]=max(maxx[x],sum-siz[x]);
    if(maxx[x]<maxx[root])  root=x;
}
int t[N];
vector<int> tmp;
void caldis(int x,int fa,int dis){
    if(dis>k)   return ;
    tmp.pb(dis);
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(vis[y]||y==fa)   continue;
        caldis(y,x,dis+1);
    }
}
void dfz(int x){
    vis[x]=true;
    for(int i=0;i<=k;++i)   t[i]=0;
    t[0]++;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(vis[y])  continue;
        tmp.clear(); caldis(y,x,1);
        for(int j=0;j<tmp.size();++j)   ans+=t[k-tmp[j]];
        for(int j=0;j<tmp.size();++j)   t[tmp[j]]++;
    }
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(vis[y])  continue;
        sum=siz[y], maxx[root=0]=INF;
        calsiz(y,-1), calsiz(root,-1);
        dfz(root);
    }
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n>>k;
    for(int i=1,x,y;i<n;++i)    cin>>x>>y, g[x].pb(y), g[y].pb(x);
    sum=n, maxx[root=0]=INF;
    calsiz(1,-1), calsiz(root,-1);
    dfz(root);
    cout<<ans<<endl;
	return 0;
}