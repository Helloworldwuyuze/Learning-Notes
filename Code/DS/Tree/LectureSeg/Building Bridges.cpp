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
const int N = 1e6 + 10;
const int M = 1e6 + 10;

struct line{
    int k,b,id;
    line(){k=0, b=INF;}
    line(int _k,int _b,int _id){k=_k, b=_b, id=_id;}
    int val(int x){ return x*k+b;}
}t[N<<2];
int h[N],w[N],n,f[N];
void update(int p,int l,int r,line f){
    if(!t[p].id){ t[p]=f; return ;}
    int mid=l+r>>1;
    if(t[p].val(mid)>f.val(mid))    swap(t[p],f);
    if(t[p].val(l)>f.val(l))    update(p<<1,l,mid,f);
    if(t[p].val(r)>f.val(r))    update(p<<1|1,mid+1,r,f);
}
int query(int p,int l,int r,int x){
    if(l==r)    return t[p].val(x);
    int mid=l+r>>1;
    if(x<=mid)  return min(t[p].val(x), query(p<<1,l,mid,x));
    else    return min(t[p].val(x), query(p<<1|1,mid+1,r,x));
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    int maxh=0;
    for(int i=1;i<=n;++i)   cin>>h[i], maxh=max(maxh,h[i]);
    for(int i=1;i<=n;++i)   cin>>w[i], w[i]+=w[i-1];
    update(1,0,maxh,line(-2*h[1],h[1]*h[1]-w[1],1));
    for(int i=2;i<=n;++i){
        int val=query(1,0,maxh,h[i]);
        f[i]=val+h[i]*h[i]+w[i-1];
        update(1,1,maxh,line(-2*h[i],f[i]+h[i]*h[i]-w[i],i));
        // cout<<f[i]<<" ";
    }
    // cout<<endl;
    cout<<f[n]<<endl;
    return 0;
}

