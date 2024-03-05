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
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n,m,q[N],a[N];
#define ls(p) t[p].left
#define rs(p) t[p].right
#define sm(p) t[p].sum
#define tg(p) t[p].tag

struct node{
    int sum,tag,left,right;
};

struct Tree{
    node t[N<<32];
    int idx, root[N];
    void push_up(int p){ sm(p)=sm(ls(p))+sm(rs(p));}
    void update(int &p,int q,int l,int r,int x,int k){
        if(!p)  p=++idx;
        t[p]=t[q];
        if(l==r){ sm(p)+=k; return ;}
        int mid=l+r>>1;
        if(x<=mid)  update(ls(p),q,l,mid,x,k);
        else    update(rs(p),q,mid+1,r,x,k);
        push_up(p);
    }
    int query(int p,int l,int r,int left,int right){
        if(left<=l&&right<=r)   return t[p].sum;
        int mid=l+r>>1,res=0;
        if(left<=mid)   res+=query(ls(p),l,mid,left,right);
        if(right>mid)   res+=query(rs(p),mid+1,r,left,right);
        return res;
    }
}t;

set<int> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)   cin>>a[i];
    for(int i=1;i<=n;++i){
        s.insert(i);
        t.update(t.root[i],t.root[i-1],1,n,a[i],1);
    }
    return 0;
}