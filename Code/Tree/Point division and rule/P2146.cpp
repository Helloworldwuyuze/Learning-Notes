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

int n,m,x;
string op;
int fa[N],siz[N],dep[N],rk[N],dfn[N],son[N],top[N],idx=0;
vector<int> v[N];

void dfs1(int x,int fat){
    fa[x]=fat; siz[x]=1, dep[x]=dep[fat]+1;
    for(int y:v[x]){
        dfs1(y,x);
        siz[x]+=siz[y];
        if(son[x]==-1||siz[y]>siz[son[x]])  son[x]=y;
    }
}
void dfs2(int x,int tp){
    // cout<<x<<" "<<tp<<endl;
    dfn[x]=++idx, rk[idx]=x, top[x]=tp;
    if(son[x]!=-1)  dfs2(son[x],tp);
    for(int y:v[x])
        if(y!=son[x])   dfs2(y,y);
}

namespace TREE{
    #define len(p) (t[p].right-t[p].left+1)
    struct node{
        int left,right,s[2],tag;
    }t[N<<2];
    void push_up(int p){ t[p].s[0]=t[p<<1].s[0]+t[p<<1|1].s[0], t[p].s[1]=t[p<<1].s[1]+t[p<<1|1].s[1];}
    void push_down(int p){
        if(t[p].tag==-1)    return ;
        t[p<<1].s[0]=(!t[p].tag)*len(p<<1), t[p<<1|1].s[0]=(!t[p].tag)*len(p<<1|1);
        t[p<<1].s[1]=t[p].tag*len(p<<1), t[p<<1|1].s[1]=t[p].tag*len(p<<1|1);
        t[p<<1].tag=t[p<<1|1].tag=t[p].tag;
        t[p].tag=-1;
    }
    void build(int p,int left,int right){
        t[p].left=left, t[p].right=right;
        t[p].s[0]=len(p), t[p].s[1]=0, t[p].tag=-1;
        if(left==right) return ;
        int mid=left+right>>1;
        build(p<<1,left,mid), build(p<<1|1,mid+1,right);
    }
    void update(int p,int left,int right,int k){
        if(left<=t[p].left&&t[p].right<=right){
            t[p].s[0]=(!k)*len(p), t[p].s[1]=k*len(p);
            t[p].tag=k;
            return ;
        }
        push_down(p);
        int mid=t[p].left+t[p].right>>1;
        if(left<=mid)   update(p<<1,left,right,k);
        if(right>mid)   update(p<<1|1,left,right,k);
        push_up(p);
    }
}

void update(int x,int y){
    while(top[x]!=top[y])   TREE::update(1,dfn[top[x]],dfn[x],1), x=fa[top[x]];
    // cout<<"UPDATE::"<<dfn[y]<<" "<<dfn[x]<<endl;
    TREE::update(1,dfn[y],dfn[x],1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<n;++i)   cin>>x,v[x].pb(i);
    memset(son,-1,sizeof(son));
    dfs1(0,-1); dfs2(0,0);
    // for(int i=0;i<n;++i)
    //     cout<<i<<" "<<dfn[i]<<" "<<siz[i]<<" "<<son[i]<<" "<<top[i]<<" "<<fa[i]<<" "<<dep[i]<<endl;
    cin>>m;
    TREE::build(1,1,n);
    while(m--){
        cin>>op;
        int l=TREE::t[1].s[0];
        // cout<<l<<" ";
        if(op[0]=='u')  cin>>x, x, TREE::update(1,dfn[x],dfn[x]+siz[x]-1,0), cout<<abs(TREE::t[1].s[0]-l)<<endl;
        else    cin>>x, x, update(x,0), cout<<abs(TREE::t[1].s[0]-l)<<endl;
    }
    return 0;
}