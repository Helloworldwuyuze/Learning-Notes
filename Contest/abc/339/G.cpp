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

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;
const int M = 1e9;

int n,m,a[N],le[N],ri[N],qu[N],last;

struct node{
    int left,right,sum;
}t[N<<5];
int root[N],idx;

#define ls(p) t[p].left
#define rs(p) t[p].right
#define sm(p) t[p].sum

void push_up(int p){
    sm(p)=sm(ls(p))+sm(rs(p));
}
void update(int &p,int q,int l,int r,int x,int k){
    p=++idx;
    t[p]=t[q];
    if(l==r){ sm(p)+=k; return ;}
    int mid=l+r>>1;
    if(x<=mid)  update(ls(p),ls(q),l,mid,x,k);
    else    update(rs(p),rs(q),mid+1,r,x,k);
    push_up(p);
}
int query(int p,int l,int r,int left,int right){
    if(!p)  return 0;
    // cout<<p<<" "<<lef<<" "<<rig<<" "<<l<<" "<<r<<endl;
    if(left<=l&&r<=right)  return sm(p);
    int mid=l+r>>1,res=0;
    if(left<=mid)   res+=query(ls(p),l,mid,left,right);
    if(right>mid)   res+=query(rs(p),mid+1,r,left,right);
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=(N<<5)-10;++i)   t[i].sum=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        update(root[i],root[i-1],0,M,a[i],a[i]);
        // cout<<query(root[i],0,M,0,4)<<" ";
    }
    // cout<<endl;
    // for(int i=1;i<=idx;++i)
    //     cout<<i<<" "<<t[i].left<<" "<<t[i].right<<" "<<t[i].sum<<endl;
    cin>>m;
    for(int i=1;i<=m;++i){
        cin>>le[i]>>ri[i]>>qu[i];
        le[i]^=last, ri[i]^=last, qu[i]^=last;
        // cout<<le[i]<<" "<<ri[i]<<" "<<qu[i]<<endl;
        // cout<<query(root[ri[i]],0,M,0,qu[i])<<" "<<query(root[le[i]-1],0,M,0,qu[i])<<endl;
        last=query(root[ri[i]],0,M,0,qu[i])-query(root[le[i]-1],0,M,0,qu[i]);
        cout<<last<<endl;
    }
    return 0;
}