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
const int MOD = 1e9 + 7;

int n,dis[N],er[N][40];
vector<PII> g[N];

void dfs(int x,int fa){
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(y==fa)   continue;
        dis[y]=dis[x]^z;
        dfs(y,x);
    }
}

struct node{
    int ch[N*32][2],idx;
    int flag[N];
    void insert(int a[]){
        int p=0;
        for(int i=1;i<=31;++i){
            if(!ch[p][a[i]]) ch[p][a[i]]=++idx;
            p=ch[p][a[i]];
        }
    }
    int query(int a[]){
        int ans=0, p=0;
        for(int i=1;i<=31;++i){
            if(ch[p][!a[i]])    ans=ans*2+(!a[i]), p=ch[p][!a[i]];
            else    ans=ans*2+a[i], p=ch[p][a[i]];
        }
        return ans;
    }
}t;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1,x,y,z;i<n;++i)  cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
    dfs(1,0);
    for(int i=1;i<=n;++i){
        int siz=31, d=dis[i];
        while(d)    er[i][siz--]=d%2, d>>=1;
        t.insert(er[i]);
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        ans=max(ans,dis[i]^t.query(er[i]));
        // cout<<dis[i]<<" "<<t.query(er[i])<<endl;
    }
    cout<<ans<<endl;
    return 0;
}