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
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n,m,x,y;
vector<int> v[N];
int f[N],ans[N],dp[N];
int pre[N],suf[N];

void dfs(int x,int fa){
    f[x]=1;
    int last=0;
    vector<int> son;
    for(int i=0;i<v[x].size();++i){
        int y=v[x][i];
        if(y==fa)   continue;
        dfs(y,x);
        f[x]=f[x]*(f[y]+1)%m;
        son.pb(v[x][i]);
    }
    int pre1=1, pre2=1;
    for(int i=0;i<son.size();++i){
        pre[son[i]]=pre1;
        pre1=pre1*(f[son[i]]+1)%m;
    }
    for(int i=son.size()-1;i>=0;--i){
        suf[son[i]]=pre2;
        pre2=pre2*(f[son[i]]+1)%m;
    }
}

void solve(int x,int fa){
    if(fa==0)   dp[x]=1;
    else    dp[x]=(dp[fa]*pre[x]%m*suf[x]%m+1)%m;
    for(int i=0;i<v[x].size();++i)
        if(v[x][i]!=fa) solve(v[x][i],x);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<n;++i)    cin>>x>>y, v[x].pb(y), v[y].pb(x);
    dfs(1,0);
    solve(1,0);
    for(int i=1;i<=n;++i)
        cout<<dp[i]*f[i]%m<<endl;
    return 0;
}