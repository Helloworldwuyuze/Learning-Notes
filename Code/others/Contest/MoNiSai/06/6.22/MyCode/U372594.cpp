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
#define endl '\n'

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n,m,a[N],lastans;
vector<int> g[N];

namespace tc{
    int siz[N],son[N],top[N],dep[N],fa[N];
    inline void dfs1(int x,int fat){
        siz[x]=1, fa[x]=fat, dep[x]=dep[fat]+1;
        for(int i=0;i<g[x].size();++i){
            int y=g[x][i];
            if(y==fat)  continue;
            dfs1(y,x);
            siz[x]+=siz[y];
            if(siz[y]>siz[son[x]])  son[x]=y;
        }
    }
    inline void dfs2(int x,int tp){
        top[x]=tp;
        if(son[x])  dfs2(son[x],tp);
        for(int i=0;i<g[x].size();++i){
            int y=g[x][i];
            if(y==fa[x]||y==son[x])  continue;
            dfs2(y,y);
        }
    }
    inline int lca(int x,int y){
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]]) swap(x,y);
            x=fa[top[x]];
        }
        if(dep[x]>dep[y])   swap(x,y);
        return x;
    }
    inline int dis(int x,int y){
        int l=lca(x,y);
        return dep[x]+dep[y]-2*dep[l];
    }
}

struct SegTree{
    int ls[N<<5], rs[N<<5], sum[N<<5], root[N], idx;
    void push_up(int p){ sum[p]=sum[ls[p]]+sum[rs[p]]; }
    inline void update(int &p,int l,int r,int x,int k){
        if(!p) p=++idx;
        if(l==r){ sum[p]+=k; return ;}
        int mid=l+r>>1;
        if(x<=mid)  update(ls[p],l,mid,x,k);
        else    update(rs[p],mid+1,r,x,k);
        push_up(p);
    }
    inline int query(int p,int l,int r,int left,int right){
        if(!p)  return 0;
        if(left<=l&&r<=right)   return sum[p];
        int mid=l+r>>1, res=0;
        if(left<=mid)   res+=query(ls[p],l,mid,left,right);
        if(right>mid)   res+=query(rs[p],mid+1,r,left,right);
        return res;
    }
}t1,t2;

namespace build{
    int dfa[N],maxdep[N],root,maxx[N],siz[N],sum,maxdep1[N];
    bool vis[N];
    inline void calsiz(int x,int fa){
        siz[x]=1, maxx[x]=0;
        for(int i=0;i<g[x].size();++i){
            int y=g[x][i];
            if(y==fa||vis[y])   continue;
            calsiz(y,x);
            siz[x]+=siz[y], maxx[x]=max(maxx[x],siz[y]);
        }
        maxx[x]=max(maxx[x],sum-siz[x]);
        if(maxx[x]<maxx[root])  root=x;
    }
    inline void dfs(int x,int fa){
        int dis=tc::dis(x,root), dis1=tc::dis(x,dfa[root]);
        maxdep[root]=max(maxdep[root],dis), maxdep1[root]=max(maxdep1[root],dis1);
        for(int i=0;i<g[x].size();++i){
            int y=g[x][i];
            if(y==fa||vis[y])   continue;
            dfs(y,x);
        }
    }
    inline void dfs1(int x,int fa){
        int dis=tc::dis(x,root), dis1=tc::dis(x,dfa[root]);
        for(int i=0;i<g[x].size();++i){
            int y=g[x][i];
            if(y==fa||vis[y])   continue;
            dfs1(y,x);
        }
        t1.update(t1.root[root],0,maxdep[root],dis,a[x]);
        t2.update(t2.root[root],0,maxdep1[root],dis1,a[x]);
    }
    inline void dfz(int x){
        // cout<<x<<" "<<build::dfa[x]<<endl;
        vis[x]=true;
        dfs(x,0); dfs1(x,0);
        for(int i=0;i<g[x].size();++i){
            int y=g[x][i];
            if(vis[y])  continue;
            sum=siz[y], maxx[root=0]=INF;
            calsiz(y,-1), calsiz(root,-1);
            dfa[root]=x;
            dfz(root);
        }
    }
}

inline void update(int x,int k,int root){
    if(build::dfa[x]==0){
        int dis1=tc::dis(x,root);
        t1.update(t1.root[x],0,build::maxdep[x],dis1,k);
        return ;
    }
    int dis1=tc::dis(x,root), dis2=tc::dis(build::dfa[x],root);
    t1.update(t1.root[x],0,build::maxdep[x],dis1,k);
    t2.update(t2.root[x],0,build::maxdep1[x],dis2,k);
    update(build::dfa[x],k,root);
}
inline int query(int x,int k,int son,int root){
    if(x==0)    return 0;
    int dis=tc::dis(x,root);
    // cout<<x<<" "<<k<<" "<<dis<<" "<<son<<" "<<root<<" "<<t1.query(t1.root[x],0,build::maxdep[x],0,min(build::maxdep[x],k-dis))<<" "<<t2.query(t2.root[son],0,build::maxdep1[son],0,min(build::maxdep1[son],k-dis))<<endl;
    return t1.query(t1.root[x],0,build::maxdep[x],0,min(build::maxdep[x],k-dis))-t2.query(t2.root[son],0,build::maxdep1[son],0,min(build::maxdep1[son],k-dis))+query(build::dfa[x],k,x,root);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)    cin>>a[i];
    for(int i=1,x,y;i<n;++i)    cin>>x>>y, g[x].pb(y), g[y].pb(x);
    tc::dfs1(1,0), tc::dfs2(1,1);

    // for(int i=1;i<=n;++i)
    //     cout<<i<<" "<<tc::son[i]<<" "<<tc::dep[i]<<" "<<tc::fa[i]<<" "<<tc::top[i]<<endl;

    build::sum=n, build::maxx[build::root=0]=INF;
    build::calsiz(1,-1), build::calsiz(build::root,-1);
    build::dfa[build::root]=0; build::dfz(build::root);

    // for(int i=1;i<=n;++i)
    //     cout<<build::maxdep[i]<<" "<<build::maxdep1[i]<<" "<<build::dfa[i]<<endl;
    // cout<<"-----------------------------------------"<<endl;
    // for(int i=1;i<=n;++i)   cout<<t2.root[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=t2.idx;++i)
    //     cout<<i<<" "<<t2.ls[i]<<" "<<t2.rs[i]<<" "<<t2.sum[i]<<endl;
    // cout<<t2.query(t2.root[9],0,build::maxdep1[9],0,1)<<"###"<<endl;
	int cnt = 0, ans = 0, q = m;
    while(m--){
        int op,x,y;
        cin>>x>>y;
        lastans=t1.query(t1.root[x],0,build::maxdep[x],0,min(build::maxdep[x],y))+query(build::dfa[x],y,x,x);
		if(y!=0)	lastans -= t1.query(t1.root[x], 0, build::maxdep[x], 0, min(build::maxdep[x], y-1)) + query(build::dfa[x], y-1, x, x);
        if(q<=10000)	cout<<lastans<<endl;
		else	++cnt, ans ^= cnt * lastans;
    }
	if(q>10000)	cout<<ans<<endl;
    return 0;
}