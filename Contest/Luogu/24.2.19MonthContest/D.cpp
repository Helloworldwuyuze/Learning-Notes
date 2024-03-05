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
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;
const int M = 1e6 + 10;

int n,q,a[N],fa[N],x[N],y[N],sum,i,ans[N],s[N];
vector<int> g[N];
bool vis[N],flag1=true,flag2=true;

void dfs(int u){
    ++sum; vis[u]=true;
    for(int v:g[u])
        if(!vis[v]&(a[v]==x[i]||a[v]==y[i]))    dfs(v);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>q;
    for(i=1;i<=n;++i)   cin>>a[i];
    for(i=2;i<=n;++i){
        cin>>fa[i], g[i].pb(fa[i]), g[fa[i]].pb(i);
        if(fa[i]!=1)    flag1=false;
        if(fa[i]!=i-1)  flag2=false;
    }
    if(flag1){
        for(int i=1;i<=n;++i)   s[a[i]]++;
        for(int i=1;i<=q;++i){
            cin>>x[i]>>y[i];
            if(x[i]==a[1]||y[i]==a[1]){
                cout<<(s[x[i]]+s[y[i]])*(s[x[i]]+s[y[i]])<<endl;
            }else   cout<<s[x[i]]+s[y[i]]<<endl;
        }
        return 0;
    }
    for(i=1;i<=q;++i)   cin>>x[i]>>y[i];
    for(i=1;i<=q;++i){
        for(int j=1;j<=n;++j)   vis[j]=false;
        for(int j=1;j<=n;++j){
            sum=0;
            if(!vis[j]&&(a[j]==x[i]||a[j]==y[i])) dfs(j);
            ans[i]+=sum*sum;
        }
    }
    for(int i=1;i<=q;++i)   cout<<ans[i]<<endl;
    return 0;
}