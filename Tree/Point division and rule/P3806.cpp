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
#define DBG cerr << endl << __LINE__ << ' ' << __FUNCTION__ << endl

#define DRE default_random_engine
#define UID uniform_int_distribution
#define y0 Y0
#define y1 Y1

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

const int INF = 2e9;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e4 + 10;
const int M = 1e6 + 10;

vector<PII> g[N];
int n,m,q[N];

int root, maxx[N], sum, siz[N], dis[N];
bool vis[N], tf[10000010], ret[N];
void calcsiz(int x,int fa){
    siz[x]=1, maxx[x]=0;
    for(PII y:g[x])
        if(y.fi!=fa&&!vis[y.fi]){
            calcsiz(y.fi,x);
            siz[x]+=siz[y.fi];
            maxx[x]=max(maxx[x],siz[y.fi]);
        }
    maxx[x]=max(maxx[x],sum-siz[x]);
    if(maxx[x]<maxx[root])  root=x;
}
int dd[N],cnt;
void calcdist(int x,int fa){
    dd[++cnt]=dis[x];
    for(PII y:g[x])
        if(!vis[y.fi]&&y.fi!=fa)
            dis[y.fi]=dis[x]+y.se, calcdist(y.fi,x);
}

queue<int> tag;
void dfz(int x,int fa){
    tf[0]=true;
    tag.push(0);
    vis[x]=true;
    for(PII y:g[x]){
        if(y.fi!=fa&&!vis[y.fi]){
            dis[y.fi]=y.se;
            calcdist(y.fi,x);
            for(int i=1;i<=cnt;++i)
                for(int j=1;j<=m;++j)
                    if(dd[i]<=q[j])    ret[j]|=tf[q[j]-dd[i]];
            for(int i=1;i<=cnt;++i)
                if(dd[i]<10000010)  tag.push(dd[i]), tf[dd[i]]=true;
            cnt=0;
        }
    }
    while(!tag.empty()) tf[tag.front()]=false, tag.pop();
    for(PII y:g[x]){
        if(y.fi!=fa&&!vis[y.fi]){
            sum=siz[y.fi], root=0, maxx[root]=INF;
            calcsiz(y.fi,x), calcsiz(root,-1);
            dfz(root,x);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=2,x,y,z;i<=n;++i) cin>>x>>y>>z, g[x].push_back(mk(y,z)), g[y].push_back(mk(x,z));
    for(int i=1;i<=m;++i)   cin>>q[i];
    root=0, maxx[root]=INF, sum=n;
    calcsiz(1,-1), calcsiz(root,-1);
    dfz(root,-1);
    for(int i=1;i<=m;++i)
        if(ret[i])  cout<<"AYE"<<endl;
        else    cout<<"NAY"<<endl;
    return 0;
}