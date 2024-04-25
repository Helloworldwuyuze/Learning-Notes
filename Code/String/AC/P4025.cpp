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
const int N = 6000 + 10;
const int M = 100 + 10;
const int MOD = 1e4 + 7;

int n,m;
char c[N];

int t[N][26], fail[N], idx, de[N];
bool val[N], flag[N];
queue<int> q;
vector<int> g[N];
void insert(char c[]){
    int len=strlen(c), p=0;
    for(int i=0;i<len;++i)
        p=t[p][c[i]-'A']?(t[p][c[i]-'A']):(t[p][c[i]-'A']=++idx);
    flag[p]=true;
}
void build(){
    for(int i=0;i<26;++i)
        if(t[0][i]) q.push(t[0][i]);
    while(q.size()){
        int p=q.front(); q.pop();
        for(int i=0;i<26;++i)
            if(t[p][i]) fail[t[p][i]]=t[fail[p]][i], q.push(t[p][i]);
            else    t[p][i]=t[fail[p]][i];
    }
    for(int i=1;i<=idx;++i)
        g[i].pb(fail[i]), g[fail[i]].pb(i);
}
void dfs(int x,int fa){
    val[x]|=flag[x];
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(y==fa)   continue;
        val[y]|=val[x];
        dfs(y,x);
    }
}
bool vis[N][2];
int f[M][N][2];
vector<PII> v[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)   cin>>c, insert(c);
    build(); dfs(0,0);
    // for(int i=0;i<=idx;++i,cout<<endl)
    //     for(int j=0;j<26;++j)
    //         cout<<t[i][j]<<" ";
    // memset(f,-0x3f,sizeof(f));
    f[0][0][0]=1; v[0].pb(mk(0,0));
    for(int x=0;x<=m;++x){
        for(int i=0;i<=idx;++i) vis[i][0]=vis[i][1]=false;
        for(int i=0;i<v[x].size();++i){
            int y=v[x][i].fi;
            bool z=v[x][i].se;
            // cout<<x<<" "<<y<<" "<<z<<" "<<f[x][y][z]<<endl;
            for(int j=0;j<26;++j){
                bool nz=z|val[t[y][j]];
                f[x+1][t[y][j]][nz]+=f[x][y][z];
                f[x+1][t[y][j]][nz]%=MOD;
                if(!vis[t[y][j]][z|val[t[y][j]]])   v[x+1].pb(mk(t[y][j],z|val[t[y][j]])), vis[t[y][j]][z|val[t[y][j]]]=true;
                // if(nz){
                //     f[x+1][t[y][j]][0]+=f[x][y][z], f[x+1][t[y][j]][0]%=MOD;
                //     if(!vis[t[y][j]][0])   v[x+1].pb(mk(t[y][j],0)), vis[t[y][j]][0]=true;
                // }
            }
        }
    }
    // for(int x=0;x<=m;++x, cout<<endl)
    //     for(int i=0;i<=idx;++i)
    //         cout<<f[x][i][1]<<" ";
    // cout<<endl;
    // for(int x=0;x<=m;++x, cout<<endl)
    //     for(int i=0;i<=idx;++i)
    //         cout<<f[x][i][0]<<" ";
    int ans=0;
    for(int i=0;i<=idx;++i)
        ans=(ans+f[m][i][1])%MOD;
    cout<<ans<<endl;
    return 0;
}