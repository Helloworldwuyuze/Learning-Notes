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

const int INF = 0x3f3f3f3f;
typedef pair<int,bool> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;

int n,m,du[N];
vector<int> g[N];
bool f[N],vis[N];

void dfs(int x,int fa){
    f[x]=!f[fa]; vis[x]=true;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(y==fa||vis[y])   continue;
        dfs(y,x);
    }
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1,x,y;i<=m;++i)   cin>>x>>y, g[x].pb(y), g[y].pb(x), du[x]++, du[y]++;
    bool flag=true;
    for(int i=1;i<=n;++i)
        if(!du[i])  flag=false;
    if(!flag){ cout<<"NIE"<<endl; return 0;}
    cout<<"TAK"<<endl;
    for(int i=1;i<=n;++i)
        if(!vis[i]) dfs(i,0);
    for(int i=1;i<=n;++i)
        if(f[i])    cout<<"K"<<endl;
        else    cout<<"S"<<endl;
	return 0;
}