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
typedef pair<int,bool> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;

int n,a[N],s[N],ans,c[N];
struct line{
    int k,b,id;
    line(){b=-INF; k=id=0;}
    line(int _k,int _b,int _id){k=_k, b=_b, id=_id;}
    int val(int x){ return c[x]*k+b;}
}t[N<<2];

void update(int p,int l,int r,line f){
    if(!t[p].id){t[p]=f; return ;}
    int mid=l+r>>1;
    if(t[p].val(mid)<f.val(mid))    swap(t[p],f);
    if(t[p].val(l)<f.val(l))    update(p<<1,l,mid,f);
    if(t[p].val(r)<f.val(r))    update(p<<1|1,mid+1,r,f);
}
int query(int p,int l,int r,int x){
    if(l==r)    return t[p].val(x);
    int mid=l+r>>1;
    if(x<=mid)  return max(query(p<<1,l,mid,x),t[p].val(x));
    else    return max(query(p<<1|1,mid+1,r,x),t[p].val(x));
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)   cin>>a[i], s[i]=s[i-1]+a[i], c[i]=a[i];
    sort(c+1,c+1+n);
    int m=unique(c+1,c+1+n)-c-1;
    for(int i=1;i<=n;++i)
        a[i]=lower_bound(c+1,c+1+m,a[i])-c;
    update(1,1,m,line(1,-s[0],1));
    for(int i=2;i<=n;++i){
        ans=max(ans,s[i-1]-c[a[i]]*i+query(1,1,m,a[i]));
        // cout<<s[i-1]<<" "<<-c[a[i]]*i<<" "<<query(1,1,m,a[i])<<endl;
        update(1,1,m,line(i,-s[i-1],i));
        // for(int i=1;i<20;++i)
        //     cout<<i<<" "<<t[i].k<<" "<<t[i].b<<" "<<t[i].id<<endl;
        // cout<<endl;
    }
    for(int i=1;i<=N-10<<2;++i) t[i].k=t[i].id=0, t[i].b=-INF;
    memset(s,0,sizeof(s));
    for(int i=n;i;--i)  s[i]=s[i+1]+c[a[i]];
    update(1,1,m,line(n,s[n+1],n));
    for(int i=n-1;i;--i){
        ans=max(ans,-s[i+1]-c[a[i]]*i+query(1,1,m,a[i]));
        // cout<<-s[i+1]<<" "<<-c[a[i]]*i<<" "<<query(1,1,m,a[i])<<endl;
        update(1,1,m,line(i,s[i+1],i));
    }
    // cout<<endl;
    for(int i=1;i<=n;++i)   ans+=i*c[a[i]];
    cout<<ans<<endl;
	return 0;
}