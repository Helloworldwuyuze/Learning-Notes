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

int n,s[N],last[M],x[N],maxs,f[N];
vector<int> v[N];
int root[M], ls[N], rs[N], idx;
struct line{
    int k,b,id;
    line(){b=-INF, k=id=0;}
    line(int _k,int _b,int _id){k=_k, b=_b, id=_id;}
    int val(int x){ return k*x+b;}
}t[N<<2];

// void build(int &p,int l,int r){
//     if(!p)  p=++idx;
//     if(l==r)    return ;
//     int mid=l+r>>1;
//     build(ls[p],l,mid), build(rs[p],mid+1,r);
// }
void update(int &p,int l,int r,line f){
    if(!p)  p=++idx;
    if(!t[p].id){ t[p]=f; return ;}
    int mid=l+r>>1;
    if(t[p].val(mid)<f.val(mid))    swap(t[p],f);
    if(t[p].val(l)<f.val(l))    update(ls[p],l,mid,f);
    if(t[p].val(r)<f.val(r))    update(rs[p],mid+1,r,f);
}
int query(int p,int l,int r,int x){
    if(!p)  return -INF;
    if(l==r)    return t[p].val(x);
    int mid=l+r>>1;
    if(x<=mid)  return max(t[p].val(x),query(ls[p],l,mid,x));
    else    return max(t[p].val(x),query(rs[p],mid+1,r,x));
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>s[i];
        x[i]=x[last[s[i]]]+1, last[s[i]]=i;
        v[s[i]].pb(-2*s[i]*x[i]); maxs=max(maxs,x[i]);
    }
    // for(int i=1;i<=maxs;++i){
    //     if(v[i].size()){
    //         sort(v[i].begin(), v[i].end());
    //         build(root[i],1,v[i].size());
    //     }
    // }
    for(int i=1;i<=n;++i){
        f[i]=max(f[i-1]+s[i],query(root[s[i]],1,v[s[i]].size(),x[i])+s[i]*x[i]*x[i]);
        // cout<<x[i]<<" "<<f[i]<<" "<<-2*s[i]*(x[i]-1)<<" "<<(x[i]-1)*(x[i]-1)*s[i]+f[i]<<" "<<query(root[s[i]],1,maxs,x[i])<<" "<<s[i]*x[i]*x[i]<<endl;
        update(root[s[i]],1,v[s[i]].size(),line(-2*(s[i])*(x[i]-1),(x[i]-1)*(x[i]-1)*s[i]+f[i-1],s[i]));
    }
    // cout<<endl;
    cout<<f[n]<<endl;
    return 0;
}

