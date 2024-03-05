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
#define left Left
#define right Right
#define endl '\n'

#define pi acos(-1)
#define eps (1e-8)
#define int long long

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;
int k[N],b[N],h[N],w[N],f[N];
int tr[M<<2],u;

inline int val(int i,int x){ return k[i]*x+b[i];}
void update(int p,int l,int r,int x){
    if(l==r){
        if(val(x,l)<val(tr[p],l))   tr[p]=x;
        return ;
    }
    int mid=l+r>>1;
    if(val(x,mid)<val(tr[p],mid))   swap(x,tr[p]);
    if(val(x,l)<val(tr[p],l))   update(p<<1,l,mid,x);
    else if(val(x,r)<val(tr[p],r))   update(p<<1|1,mid+1,r,x);
}
int query(int p,int l,int r,int x){
    if(l==r)    return val(tr[p],x);
    int mid=l+r>>1;
    return min(val(tr[p],x),x<=mid?query(p<<1,l,mid,x):query(p<<1|1,mid+1,r,x));
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin>>n, b[0]=1e18;
    for(int i=1;i<=n;++i)   cin>>h[i];
    for(int i=1;i<=n;++i)   cin>>w[i], w[i]+=w[i-1];
    k[1]=-2*h[1], b[1]=h[1]*h[1]-w[1], update(1,0,M,1);
    for(int i=2;i<=n;++i){
        f[i]=h[i]*h[i]+w[i-1]+query(1,0,M,h[i]);
        k[i]=-2*h[i], b[i]=f[i]+h[i]*h[i]-w[i], update(1,0,M,i);
    }
    cout<<f[n]<<endl;
    return 0;
}