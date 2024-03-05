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

struct node{
    int left,right;
    bool tag,ok,l,r;
}t[N<<2];
char c[N];
int n,q,op,l,r;

void push_up(int p){
    t[p].l=t[p<<1].l, t[p].r=t[p<<1|1].r;
    t[p].ok=t[p<<1].ok&t[p<<1|1].ok&(t[p<<1].r!=t[p<<1|1].l);
}
void build(int p,int left,int right){
    t[p].left=left, t[p].right=right;
    t[p].tag=false; t[p].ok=true;
    if(left==right){
        t[p].l=t[p].r=c[left]-'0';
        return ;
    }
    int mid=left+right>>1;
    build(p<<1,left,mid), build(p<<1|1,mid+1,right);
    push_up(p);
}
void push_down(int p){
    if(t[p].tag==0) return;
    t[p<<1].tag^=1, t[p<<1|1].tag^=1;
    t[p<<1].l^=1, t[p<<1].r^=1;
    t[p<<1|1].l^=1, t[p<<1|1].r^=1;
    t[p].tag=0;
}
void update(int p,int left,int right){
    if(left<=t[p].left&&t[p].right<=right){
        t[p].tag^=1; t[p].l^=1, t[p].r^=1;
        return ;
    }
    push_down(p);
    int mid=t[p].left+t[p].right>>1;
    if(left<=mid)   update(p<<1,left,right);
    if(right>mid)   update(p<<1|1,left,right);
    push_up(p);
}
node query(int p,int left,int right){
    if(left<=t[p].left&&t[p].right<=right)  return t[p];
    push_down(p);
    int mid=t[p].left+t[p].right>>1;
    if(left>mid)    return query(p<<1|1,left,right);
    if(right<=mid)  return query(p<<1,left,right);
    if(left<=mid&&mid<right){
        node l=query(p<<1,left,right), r=query(p<<1|1,left,right);
        node ans; ans.l=l.l, ans.r=r.r, ans.ok=l.ok&r.ok&(l.r!=r.l);
        return ans;
    }
}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>q;
    cin>>(c+1);
    build(1,1,n);
    // for(int i=1;i<=n<<1;++i)
    while(q--){
        cin>>op>>l>>r;
        if(op==1)   update(1,l,r);
        else{
            if(query(1,l,r).ok==0)  cout<<"No"<<endl;
            else    cout<<"Yes"<<endl;
        }
        for(int i=1;i<=n<<1;++i)
            cout<<i<<" "<<t[i].left<<" "<<t[i].right<<" "<<t[i].l<<" "<<t[i].r<<" "<<t[i].ok<<" "<<t[i].tag<<endl;
    }
    return 0;
}