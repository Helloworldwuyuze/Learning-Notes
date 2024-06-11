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
#define null nullptr

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e3 + 10;
const int M = 1e6 + 10;

int T,n,h,r,x[N],y[N],z[N];
vector<int> g[N];
bool flag, vis[N];

void dfs(int x){
    vis[x]=true;
    if(x==n+1){ flag=true; return ;}
    for(int y:g[x]){
        if(!vis[y]) dfs(y);
    }
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>h>>r;
        for(int i=1;i<=n;++i)   cin>>x[i]>>y[i]>>z[i];
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j])<=4*r*r)
                    g[i].pb(j), g[j].pb(i);
            }
        }
        for(int i=1;i<=n;++i){
            if(z[i]+r>=h)   g[n+1].pb(i), g[i].pb(n+1);
            if(z[i]-r<=0)   g[0].pb(i), g[i].pb(0);
        }
        flag=false; dfs(0);
        if(flag)    cout<<"Yes"<<endl;
        else    cout<<"No"<<endl;
        for(int i=0;i<=n+1;++i) g[i].clear(), vis[i]=false;
    }
	return 0;
}