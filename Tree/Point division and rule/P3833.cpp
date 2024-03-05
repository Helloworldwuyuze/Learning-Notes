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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n,m,tt;
vector<int> v[N];
char op;
int x,y,z;

int siz[N],fa[N][20],dfn[N],rk[N],top[N],son[N],dep[N],idx;
void dfs1(int x,int fat){
    fa[x][0]=fat, siz[x]=1, dep[x]=dep[fat]+1;
    for(int i=1;i<=tt;++i)
        fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int y:v[x]){
        if(y!=fat)  dfs1(x,fat);
        siz[x]+=siz[y];
        if(siz[y]>siz[son[x]])  son[x]=y;
    }
}
void dfs2(int x,int tp){
    top[x]=tp, dfn[x]=++idx, rk[idx]=x;
    if(son[x])  dfs2(son[x],tp);
    for(int y:v[x])
        if(y!=son[x]&&y!=fa[x][0])  dfs2(y,y);
}

struct node{
    int left,right,tag,sum;
}t[N<<2];
#define len(p) (t[p].right-t[p].left+1)
void build(int p,int left,int right){
    t[p].left=left, t[p].right=right; t[p].tag=t[p].sum=0;
    if(left==right) return ;
    int mid=left+right;
    build(p<<1,left,mid), build(p<<1|1,mid+1,right);
}
void update(int p,int left,int right,int x){
    if(left<=t[p].left&&t[p].right<=right){
        t[p].tag+=x, t[p].sum+=len(p)*x;
        return ;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n; tt=log(n)/log(2);
    for(int i=1,x,y;i<=n;++i)   cin>>x>>y, v[x].pb(y), v[y].pb(x);
    cin>>m;
    
    return 0;
}