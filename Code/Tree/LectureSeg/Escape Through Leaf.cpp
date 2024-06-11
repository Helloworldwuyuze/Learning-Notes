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
const int N = 1e5 + 10;
const int M = 1e4 + 10;

int n,a[N],b[N],f[N],maxa,c[N],cnt;
vector<int> g[N];
int root[N], ls[N<<5], rs[N<<5], idx;
struct line{
    int k,b,id;
    line(){}
    line(int _k,int _b,int _id){k=_k, b=_b, id=_id;}
    int val(int x){ return c[x]*k+b;}
}t[N<<2];

void update(int &p,int l,int r,line f){
    if(!p)  p=++idx;
    if(!t[p].id){ t[p]=f; return ;}
    int mid=l+r>>1;
    if(t[p].val(mid)>f.val(mid))   swap(t[p],f);
    if(t[p].val(l)>f.val(l))    update(ls[p],l,mid,f);
    if(t[p].val(r)>f.val(r))    update(rs[p],mid+1,r,f);
}
int query(int p,int l,int r,int x){
    // cout<<p<<" "<<l<<" "<<r<<" "<<x<<endl;
    if(!p)  return INF;
    if(l==r)    return t[p].val(x);
    int mid=l+r>>1;
    if(x<=mid)  return min(t[p].val(x),query(ls[p],l,mid,x));
    else    return min(t[p].val(x),query(rs[p],mid+1,r,x));
}
int merge(int p,int q,int l,int r){
    // DBG;
    // cout<<p<<" "<<q<<" "<<l<<" "<<r<<endl;
    if(!p||!q)  return p+q;
    if(l==r)    return t[p].val(l)<t[q].val(l)?p:q;
    int mid=l+r>>1;
    ls[p]=merge(ls[p],ls[q],l,mid), rs[p]=merge(rs[p],rs[q],mid+1,r);
    update(p,l,r,t[q]);
    return p;
}

void dfs(int x,int fat){
    bool flag=false;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(y==fat)  continue;
        dfs(y,x); flag=true;
        root[x]=merge(root[x],root[y],1,cnt);
    }
    // cout<<x<<" "<<root[x]<<" "<<t[root[x]].k<<" "<<t[root[x]].b<<endl;
    if(flag)    f[x]=query(root[x],1,cnt,a[x]);
    update(root[x],1,cnt,line(b[x],f[x],x));
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)   cin>>a[i], c[i]=a[i];
    sort(c+1,c+1+n);
    cnt=unique(c+1,c+1+n)-c-1;
    for(int i=1;i<=n;++i)
        a[i]=lower_bound(c+1,c+1+cnt,a[i])-c;
    for(int i=1;i<=n;++i)   cin>>b[i];
    for(int i=1,x,y;i<n;++i)    cin>>x>>y, g[x].pb(y), g[y].pb(x);
    dfs(1,0);
    for(int i=1;i<=n;++i)   cout<<f[i]<<" ";
    return 0;
}

