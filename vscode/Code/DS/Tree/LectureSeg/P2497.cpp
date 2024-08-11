#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>

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
const int N = 5e5 + 10;
const int M = 1e6 + 10;

int n,s,x[N],v[N],r[N],a[N];
double g[N],f[N],ans=INF;
struct line{
    double k,b;
    int id;
    line(){b=INF;k=id=0;}
    line(double _k, double _b, int _id){ k=_k, b=_b, id=_id;}
    double val(int x){ return k*a[x]+b;}
}t[N<<2];

void update(int p,int l,int r,line f){
    if(!t[p].id){ t[p]=f; return ;}
    int mid=l+r>>1;
    if(t[p].val(mid)>f.val(mid)&&!(fabs(t[p].val(mid)-f.val(mid))<eps)) swap(t[p],f);
    if(t[p].val(l)>f.val(l)+eps)    update(p<<1,l,mid,f);
    if(t[p].val(r)>f.val(r)+eps)    update(p<<1|1,mid+1,r,f);
}
double query(int p,int l,int r,int x){
    if(l==r)    return t[p].val(x);
    int mid=l+r>>1;
    if(x<=mid)  return min(t[p].val(x),query(p<<1,l,mid,x));
    else    return min(t[p].val(x),query(p<<1|1,mid+1,r,x));
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>s;
    for(int i=1;i<=n;++i)    cin>>x[i]>>r[i]>>v[i], g[i]=0.5/sqrt(r[i]), a[i]=x[i];
    int m=unique(a+1,a+1+n)-a-1;
    for(int i=1;i<=n;++i)   x[i]=lower_bound(a+1,a+1+m,x[i])-a;
    f[1]=v[1];
    update(1,1,m,line(g[1],-g[1]*a[x[1]]+f[1],1));
    // cout<<t[1].k<<" "<<t[1].b<<endl;
    // cout<<query(1,1,m,x[1])<<endl;
    for(int i=2;i<=n;++i){
        f[i]=query(1,1,m,x[i])+v[i];
        update(1,1,m,line(g[i],-a[x[i]]*g[i]+f[i],i));
        if(a[x[i]]+r[i]>=s) ans=min(ans,f[i]);
        // cout<<f[i]<<" ";
    }
    // cout<<endl;
    cout<<fixed<<setprecision(3)<<ans<<endl;
    return 0;
}