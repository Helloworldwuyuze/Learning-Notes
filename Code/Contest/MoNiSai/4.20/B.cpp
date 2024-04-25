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
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 5e5 + 10;
const int MOD = 998244353;
#define endl '\n'

int T,n,w[N],e[N];

vector<int> g[N];
int dfn[N], low[N], belong[N], idx, st[N], top, tot, t;

void Tarjan(int x){
    dfn[x]=low[x]=++idx;
    st[++top]=x;
    for(int i=0;i<g[x].size();++i)
        if(!dfn[g[x][i]])   Tarjan(g[x][i]), low[x]=min(low[x],low[g[x][i]]);
        else if(belong[g[x][i]]==0) low[x]=min(low[x],dfn[g[x][i]]);
    // cout<<x<<endl; 
    if(dfn[x]==low[x]){
        ++tot;
        do{
            t=st[top--];
            belong[t]=tot;
        }while(t!=x&&top);
    }
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;++i)   cin>>w[i];
        for(int i=1;i<=n;++i)   cin>>e[i];
        idx=tot=top=0;
        for(int i=1;i<=N-10;++i)   g[i].clear(), dfn[i]=low[i]=belong[i]=0;
        for(int i=1;i*2<=N-10;++i)
            for(int j=i*2;j<=N-10;j+=i)   g[i].pb(j);
        for(int i=1;i<=n;++i)   g[w[i]].pb(e[i]);
        Tarjan(1);
        int ans=0;
        for(int i=1;i<=n;++i)
            ans+=belong[w[i]]==belong[e[i]];
        cout<<ans<<endl;
    }
	return 0;
}

