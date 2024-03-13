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
#define int long long

using namespace std;

const int INF = 123456789123456789;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;
const int M = 1e6 + 10;

int n,m,x,y,z,op,s,t;
vector<PII> g[N];
int siz[N],dfn[N],idx,rk[N],dep[N],fa[N][20],top[N],son[N],dis[N];
int k[N<<2],b[N<<2],tot;

//预处理

void dfs1(int u,int fat){
    fa[u][0]=fat; siz[u]=1;
    dep[u]=dep[fat]+1;
    int t=log(n)/log(2)+1;
    for(int i=1;i<=t;++i)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(PII v:g[u]){
        if(v.fi==fat)  continue;
        dis[v.fi]=dis[u]+v.se;
        dfs1(v.fi,u);
        siz[u]+=siz[v.fi];
        if(siz[v.fi]>siz[son[u]])   son[u]=v.fi;
    }
}
void dfs2(int u,int tp){
    top[u]=tp;dfn[u]=++idx; rk[idx]=u; 
    if(son[u])  dfs2(son[u],tp);
    for(PII v:g[u])
        if(v.fi!=fa[u][0]&&v.fi!=son[u])   dfs2(v.fi,v.fi);
}

//倍增LCA

int LCA(int x,int y){
    int t=log(n)/log(2)+1;
    if(dep[x]<dep[y])   swap(x,y);
    for(int i=t;i>=0;--i)
        if(dep[fa[x][i]]>=dep[y])   x=fa[x][i];
    if(x==y)    return x;
    for(int i=t;i>=0;--i)
        if(fa[x][i]!=fa[y][i])  x=fa[x][i], y=fa[y][i];
    return fa[x][0];
}

//SegMent Tree
inline int val(int i,int x){ return k[i]*dis[rk[x]]+b[i]; }
int tr[N<<2], mn[N<<2];
inline void push_up(int p){ mn[p]=min(mn[p],min(mn[p<<1],mn[p<<1|1])); }
void update(int p,int left,int right,int l,int r,int x){
    // DBG;
    // cout<<p<<" "<<left<<" "<<right<<" "<<l<<" "<<r<<" "<<x<<endl;
    int mid=l+r>>1;
    if(left<=l&&r<=right){
        if(val(x,l)<=val(tr[p],l)&&val(x,r)<=val(tr[p],r)){
            tr[p]=x; mn[p]=min(mn[p],min(val(x,l),val(x,r)));
            return ;
        }if(val(x,l)>=val(tr[p],l)&&val(x,r)>=val(tr[p],r)) return ;
        if(k[x]<k[tr[p]]){
            if(val(x,mid)<=val(tr[p],mid))  update(p<<1,left,right,l,mid,tr[p]), tr[p]=x;
            else    update(p<<1|1,left,right,mid+1,r,x);
        }else{
            if(val(x,mid)<=val(tr[p],mid))  update(p<<1|1,left,right,mid+1,r,tr[p]), tr[p]=x;
            else    update(p<<1,left,right,l,mid,x);
        }
    }
    if(left<=mid)   update(p<<1,left,right,l,mid,x);
    if(right>mid)   update(p<<1|1,left,right,mid+1,r,x);
    push_up(p);
    // DBG;
    // cout<<p<<" "<<left<<" "<<right<<" "<<l<<" "<<r<<" "<<x<<" "<<mn[p]<<endl;
}
int query(int p,int left,int right,int l,int r){
    if(left<=l&&r<=right)    return mn[p];
    int mid=l+r>>1, res=INF;
    if(b[tr[p]]!=INF)    res=min(val(tr[p],max(l,left)),val(tr[p],min(r,right)));
    if(left<=mid)   res=min(res,query(p<<1,left,right,l,mid));
    if(right>mid)   res=min(res,query(p<<1|1,left,right,mid+1,r));
    return res;
}
void build(int p,int l,int r){
    mn[p]=INF, tr[p]=1;
    if(l==r)    return ;
    int mid=l+r>>1;
    build(p<<1,l,mid), build(p<<1|1,mid+1,r);
}

//Tree Cut
void change(int x,int y){
    while(top[x]!=top[y])   update(1,dfn[top[x]],dfn[x],1,n,tot), x=fa[top[x]][0];
    update(1,dfn[y],dfn[x],1,n,tot);
}
int ask(int x,int y){
    int ans=INF;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        ans=min(ans,query(1,dfn[top[x]],dfn[x],1,n));
        x=fa[top[x]][0];
    }
    if(dep[x]<dep[y])   swap(x,y);
    // DBG;
    // cout<<dfn[y]<<" "<<dfn[x]<<endl;
    return min(ans,query(1,dfn[y],dfn[x],1,n));
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<n;++i)    cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
    dfs1(1,0); dfs2(1,1);
    k[++tot]=0, b[tot]=INF; build(1,1,n);
    // DBG; cout<<"DFN::";
    // for(int i=1;i<=n;++i)   cout<<dfn[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n<<1;++i)    cout<<i<<" "<<tr[i]<<" "<<mn[i]<<endl;
    while(m--){
        cin>>op;
        if(op==1){
            cin>>s>>t>>x>>y;
            int w=LCA(s,t);
            k[++tot]=-x, b[tot]=x*dis[s]+y, change(s,w);
            k[++tot]=x, b[tot]=x*(dis[s]-2*dis[w])+y, change(t,w);
        }else   cin>>s>>t, cout<<ask(s,t)<<endl;
        // cout<<endl<<"CERR::LINE"<<endl;
        // for(int i=1;i<=tot;++i) cout<<k[i]<<" "<<b[i]<<endl;
        // cout<<"CERR::TREE"<<endl;
        // for(int i=1;i<=n<<1;++i)    cout<<i<<" "<<tr[i]<<" "<<mn[i]<<endl;
        // cout<<"CERR::POINT"<<endl;
        // for(int i=1;i<=n;++i)   cout<<ask(i,i)<<endl;
    }
    return 0;
}