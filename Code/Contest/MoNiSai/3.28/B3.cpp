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
typedef pair<int,bool> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;

int n,m;
vector<int> g[N];
int tag[N],f[N];
bool t[N],s[N];

int dep[N],p[2],root=N-10;

void dfs1(int x,int fa,int j){
    // cout<<x<<" "<<fa<<" "<<j<<endl;
    if((dep[x]>dep[p[j]]||dep[x]==dep[p[j]]&&x<p[j])&&t[x])   p[j]=x;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(y==fa)   continue;
        dep[y]=dep[x]+1;
        dfs1(y,x,j);
    }
}

void dfs2(int x,int fa){
    int flag=0; s[x]=t[x];
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(y==fa)   continue;
        dfs2(y,x);
        s[x]|=s[y];
        f[x]+=f[y]+s[y]*2;
    }
    if(flag==1&&t[x])   root=min(root,x);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1,x,y;i<n;++i)    cin>>x>>y, g[x].pb(y), g[y].pb(x);
    for(int i=1;i<=m;++i)   cin>>tag[i], t[tag[i]]=true;
    if(m==1){
        cout<<tag[1]<<endl<<0<<endl;
        return 0;
    }
    dfs1(1,0,0);
    memset(dep,0,sizeof(dep));
    dfs1(p[0],0,1);
    dfs2(p[0],0);
    // cout<<p[0]<<" "<<p[1]<<endl;
    cout<<min(p[0],p[1])<<endl<<f[p[0]]-dep[p[1]]<<endl;
    return 0;
}
