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
const int LEN = 300 + 10;
const int M = 3e3 + 10;
const int MOD = 1e9 + 7;

int n,k;
char c[LEN];
vector<int> v[LEN];

int t[LEN][3], fail[LEN], flag[LEN], idx, val[LEN], de[LEN];
void insert(char c[]){
    int len=strlen(c), p=0;
    for(int i=0;i<len;++i)
        p=t[p][c[i]-'A']?t[p][c[i]-'A']:(t[p][c[i]-'A']=++idx);
    flag[p]++;
}
queue<int> q;
void build(){
    for(int i=0;i<3;++i)
        if(t[0][i]) q.push(t[0][i]);
    while(q.size()){
        int p=q.front(); q.pop();
        for(int i=0;i<3;++i)
            if(t[p][i]) fail[t[p][i]]=t[fail[p]][i], q.push(t[p][i]), ++de[fail[t[p][i]]];
            else    t[p][i]=t[fail[p]][i];
    }
    for(int i=1;i<=idx;++i)
        v[i].pb(fail[i]), v[fail[i]].pb(i);
}
void dfs(int x,int fa){
    val[x]+=flag[x];
    for(int i=0;i<v[x].size();++i){
        int y=v[x][i];
        if(y==fa)   continue;
        val[y]+=val[x];
        dfs(y,x);
    }
}
int f[M][LEN];
vector<int> g[M];
bool vis[LEN];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        cin>>c, insert(c);
    build(); dfs(0,-1);
    g[0].pb(0);
    for(int x=0;x<=k;++x){
        for(int i=0;i<=idx;++i) vis[i]=false;
        for(int j=0;j<g[x].size();++j){
            int p=g[x][j];
            // cout<<"###"<<x<<" "<<p<<" "<<f[x][p]<<"###"<<endl;
            for(int i=0;i<3;++i){
                f[x+1][t[p][i]]=max(f[x+1][t[p][i]],f[x][p]+val[t[p][i]]);
                if(!vis[t[p][i]])   g[x+1].pb(t[p][i]), vis[t[p][i]]=true;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=idx;++i)
        ans=max(ans,f[k][i]);
    cout<<ans<<endl;
    return 0;
}