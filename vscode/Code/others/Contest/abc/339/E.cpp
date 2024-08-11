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
const int N = 5e5 + 10;
const int M = 1e6 + 10;

int n,m,x,ans,f[N],a[N];
int b[N];
struct node{
    int left,right,maxx;
}t[N<<2];
void push_up(int p){ t[p].maxx=max(t[p<<1].maxx,t[p<<1|1].maxx);}
void build(int p,int left,int right){
    t[p].left=left, t[p].right=right;
    t[p].maxx=0;
    if(left==right) return ;
    int mid=left+right>>1;
    build(p<<1,left,mid), build(p<<1|1,mid+1,right);
}
void update(int p,int x,int k){
    if(t[p].left==t[p].right){ t[p].maxx=k; return ;}
    int mid=t[p].left+t[p].right>>1;
    if(x<=mid)   update(p<<1,x,k);
    else    update(p<<1|1,x,k);
    push_up(p);
}
int query(int p,int left,int right){
    if(left<=t[p].left&&t[p].right<=right)  return t[p].maxx;
    int mid=t[p].left+t[p].right>>1, res=0;
    if(left<=mid)   res=max(res,query(p<<1,left,right));
    if(right>mid)   res=max(res,query(p<<1|1,left,right));
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    build(1,1,N-10);
    for(int i=1;i<=n;++i)   cin>>a[i];
    for(int i=1;i<=n;++i){
        f[i]=query(1,max(1,a[i]-m),min(N-10,a[i]+m))+1;
        update(1,a[i],f[i]); ans=max(ans,f[i]);
    }
    cout<<ans<<endl;
    return 0;
}