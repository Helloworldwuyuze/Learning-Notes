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
const int M = 2e6 + 10;
const int MOD = 1e9 + 7;

char c[N];
vector<PII> ques[N];
vector<int> g[N];
int m;

namespace AC{
    int t[N][26], idx = 1, flag[N], fail[N], fa[N] = {0,1}, n, rk[N];
    void insert(char c[]){
        int len=strlen(c), p=1;
        for(int i=0;i<len;++i){
            if(c[i]=='B')   p=fa[p];
            else if(c[i]=='P')  flag[p]=++n, rk[n]=p;
            else{
                if(t[p][c[i]-'a'])  p=t[p][c[i]-'a'];
                else    t[p][c[i]-'a']=++idx, fa[idx]=p, p=t[p][c[i]-'a'];
            }
        }
    }
    queue<int> q;
    void build(){
        for(int i=0;i<26;++i)
            if(t[1][i]) q.push(t[1][i]), fail[t[1][i]]=1;
        fail[1]=1;
        while(q.size()){
            int p=q.front(); q.pop();
            for(int i=0;i<26;++i)
                if(t[p][i]){
                    int tmp=p;
                    while(!t[fail[tmp]][i]&&tmp!=1)    tmp=fail[tmp];
                    if(tmp==1)  fail[t[p][i]]=1;
                    else    fail[t[p][i]]=t[fail[tmp]][i];
                    q.push(t[p][i]);
                }
        }
    }
}

namespace BIT{
    int b[N];
    #define lowbit(x) (x&-x)
    void update(int x,int k){ for(int i=x;i<=AC::idx;i+=lowbit(i))   b[i]+=k;}
    int query(int x){ int ans=0; for(int i=x;i;i-=lowbit(i))    ans+=b[i]; return ans;}
    #undef lowbit
}

int fa[N], siz[N], dfn[N], rk[N], idx;
int ans[N];
void dfs1(int x,int fat){
    fa[x]=fat; dfn[x]=++idx; rk[idx]=x; siz[x]=1;
    for(int i=0;i<g[x].size();++i)
        if(g[x][i]!=fat)    dfs1(g[x][i],x), siz[x]+=siz[g[x][i]];
}
void dfs2(int x){
    // cout<<x<<" "<<dfn[x]<<endl;
    BIT::update(dfn[x],1);
    // for(int i=1;i<=idx;++i)
        // cout<<BIT::query(i)-BIT::query(i-1)<<' ';
    // cout<<endl;
    if(AC::flag[x]){
        int xx=AC::flag[x];
        for(int i=0;i<ques[xx].size();++i){
            int y=AC::rk[ques[xx][i].fi], z=ques[xx][i].se;
            ans[z]=BIT::query(dfn[y]+siz[y]-1)-BIT::query(dfn[y]-1);
        }
    }
    for(int i=0;i<26;++i)
        if(AC::t[x][i]) dfs2(AC::t[x][i]);
    BIT::update(dfn[x],-1);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>c; AC::insert(c); cin>>m;
    for(int i=1,x,y;i<=m;++i)
        cin>>x>>y, ques[y].pb(mk(x,i));
    AC::build();
    for(int i=2;i<=AC::idx;++i)
        g[i].pb(AC::fail[i]), g[AC::fail[i]].pb(i);
    // for(int i=1;i<=AC::idx;++i,cout<<endl)
        // for(int j=0;j<g[i].size();++j)
            // cout<<g[i][j]<<" ";
    dfs1(1,0);
    dfs2(1);
    for(int i=1;i<=m;++i)
        cout<<ans[i]<<endl;
    return 0;
}