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
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;
const int M = 2e5 + 10;
const int MOD = 1e9 + 7;

struct ques{
    int l,r,v;
}a[N];
int n,m;
struct node{
    int left,right,maxx,tag;
}t[N<<2];

bool operator <(ques x,ques y){
    return x.r<y.r;
}

void push_down(int p){
    if(!t[p].tag)   return ;
    t[p<<1].tag+=t[p].tag, t[p<<1|1].tag+=t[p].tag;
    t[p<<1].maxx+=t[p].tag, t[p<<1|1].maxx+=t[p].tag;
    t[p].tag=0;
}
void build(int p,int left,int right){
    t[p]=node{left,right,0,0};
    if(left==right) return ;
    int mid=left+right>>1;
    build(p<<1,left,mid), build(p<<1|1,mid+1,right);
}
void push_up(int p){
    t[p].maxx=max(t[p<<1].maxx,t[p<<1|1].maxx);
}
void update(int p,int left,int right,int k){
    if(left<=t[p].left&&t[p].right<=right){
        t[p].maxx+=k; t[p].tag+=k;
        return ;
    }
    push_down(p);
    int mid=t[p].left+t[p].right>>1;
    if(left<=mid)   update(p<<1,left,right,k);
    if(right>mid)   update(p<<1|1,left,right,k);
    push_up(p);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;++i)   cin>>a[i].l>>a[i].r>>a[i].v;
    sort(a+1,a+1+m);
    build(1,1,n);
    int j=1;
    for(int i=1;i<=n;++i){
        update(1,i,i,max(0ll,t[1].maxx));
        while(a[j].r==i&&j<=m)   update(1,a[j].l,a[j].r,a[j].v), ++j;
    }
    cout<<max(0ll,t[1].maxx)<<endl;
    return 0;
}