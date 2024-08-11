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
const int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;
const int M = 1e7 + 10;

int n,m,L,R,maxdep,ans=-INF;
int val[N];
vector<PII> g[N];

struct Seg{
    int sum[N<<2];
    void build(int p,int l,int r){
        // cout<<p<<" "<<l<<" "<<r<<endl;
        sum[p]=-INF;
        if(l==r)    return ;
        int mid=l+r>>1;
        build(p<<1,l,mid), build(p<<1|1,mid+1,r);
    }
    void update(int p,int l,int r,int x,int k){
        if(l==r){ sum[p]=max(sum[p],k); return ;}
        int mid=l+r>>1;
        if(x<=mid)  update(p<<1,l,mid,x,k);
        else    update(p<<1|1,mid+1,r,x,k);
        sum[p]=max(sum[p<<1],sum[p<<1|1]);
    }
    int query(int p,int l,int r,int left,int right){
        if(left<=l&&r<=right)   return sum[p];
        int mid=l+r>>1,res=-INF;
        if(left<=mid)   res=max(res,query(p<<1,l,mid,left,right));
        if(right>mid)   res=max(res,query(p<<1|1,mid+1,r,left,right));
        return res;
    }
};

int maxx[N],siz[N],root,sum,dep[N];
bool vis[N];
void calsiz(int x,int fa){
    // cout<<x<<" "<<fa<<endl;
    siz[x]=1, maxx[x]=0;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(vis[y]||y==fa)  continue;
        calsiz(y,x);
        siz[x]+=siz[y], maxx[x]=max(maxx[x],siz[y]);
    }
    maxx[x]=max(maxx[x],sum-siz[x]);
    if(maxx[x]<maxx[root])  root=x;
}
void caldep(int x,int fa){
    maxdep=max(maxdep,dep[x]);
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(y==fa||vis[y])   continue;
        dep[y]=dep[x]+1;
        caldep(y,x);
    }
}
vector<PII> sub, color;
int dis[N];
void caldis(int x,int fa,int value,int l){
    dep[x]=dep[fa]+1;
    if(dep[x]>R)    return ;
    sub.pb(mk(value,dep[x]));
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(y==fa||vis[y])   continue;
        if(z==l)    caldis(y,x,value,l);
        else    caldis(y,x,value+val[z],z);
    }
}   

Seg gene, col;
void dfz(int x){
//    cout<<"QAQ"<<endl;
    // cout<<"###"<<x<<"###"<<endl;
    vis[x]=true;
    dep[x]=0; maxdep=0; caldep(root,0);
    // cout<<maxdep<<endl;
    int lst=0;
    maxdep=min(maxdep,R);
    gene.build(1,0,maxdep), col.build(1,0,maxdep);
    // cout<<gene.query(1,0,maxdep,1,1)<<endl;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(vis[y])  continue;
        sub.clear(); caldis(y,x,val[z],z);
        // cout<<"##"<<y<<" "<<z<<"##"<<endl;
        // for(int j=0;j<sub.size();++j)
            // cout<<sub[j].fi<<" "<<sub[j].se<<endl;
        // cout<<gene.query(1,0,maxdep,1,1)<<endl;
        for(int j=0;j<sub.size();++j)
            if(sub[j].se>=L&&sub[j].se<=R)  ans=max(sub[j].fi,ans);
        if(lst!=z){
            lst=z;
            for(int j=0;j<color.size();++j)
                gene.update(1,0,maxdep,color[j].se,color[j].fi);
            col.build(1,0,maxdep);
            color.clear();
            for(int j=0;j<sub.size();++j)
                ans=max(ans,sub[j].fi+gene.query(1,0,maxdep,max(0ll,L-sub[j].se),R-sub[j].se));
            for(int j=0;j<sub.size();++j)
                col.update(1,0,maxdep,sub[j].se,sub[j].fi), color.pb(sub[j]);
        }else{
            for(int j=0;j<sub.size();++j)
                ans=max(ans,sub[j].fi+max(col.query(1,0,maxdep,max(0ll,L-sub[j].se),R-sub[j].se)-val[lst],gene.query(1,0,maxdep,max(0ll,L-sub[j].se),R-sub[j].se)));
            for(int j=0;j<sub.size();++j)
                col.update(1,0,maxdep,sub[j].se,sub[j].fi), color.pb(sub[j]);
        }
        // cout<<ans<<endl;
    }
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(vis[y])  continue;
        sum=siz[y], maxx[root=0]=INF;
        calsiz(y,-1), calsiz(root,-1);
        dfz(root);
    }
}

bool cmp(PII x,PII y){ return x.se<y.se; }

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m>>L>>R;
    for(int i=1;i<=m;++i)   cin>>val[i];
    for(int i=1,x,y,z;i<n;++i)  cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
    for(int i=1;i<=n;++i)
        sort(g[i].begin(), g[i].end(), cmp);
    // for(int i=1;i<=n;++i){
    //     cout<<"###"<<i<<"###"<<endl;
    //     for(int j=0;j<g[i].size();++j)
    //         cout<<g[i][j].fi<<" "<<g[i][j].se<<endl;
    // }
    sum=n, maxx[root=0]=INF;
    calsiz(1,-1), calsiz(root,-1);
    // cout<<root<<endl;
    dfz(root);
    cout<<ans<<endl;
    return 0;
}
