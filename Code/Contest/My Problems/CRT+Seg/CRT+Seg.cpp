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
#define int __int128

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

long long n,m,a,b,op,l,r,x;

int gcd(int a,int b){ return b?gcd(b,a%b):a;}
void exgcd(int a,int b,int &x,int &y){
    if(b==0){ x=1, y=0; return ;}
    exgcd(b,a%b,x,y);
    int tmp=x;
    x=y, y=tmp-a/b*y;
}

PII t[N<<2];
void push_up(PII &s,PII ls,PII rs){
	if(!ls.se||!rs.se){
		s.fi=ls.fi+rs.fi, s.se=ls.se+rs.se;
		return ;
	}
    int x,y,d=gcd(ls.se,rs.se), lcm=ls.se*rs.se/d;
    exgcd(ls.se/d,rs.se/d,x,y);
    x=(x%(rs.se/d)+rs.se/d)%(rs.se/d);
    s.fi=(ls.fi+(rs.fi-ls.fi)/d*ls.se%lcm*x%lcm+lcm)%lcm; s.se=lcm;
}
void update(int p,int l,int r,int x,PII k){
    if(l==r){ t[p]=k; return ;}
    int mid=l+r>>1;
    if(x<=mid)  update(p<<1,l,mid,x,k);
    else    update(p<<1|1,mid+1,r,x,k);
    push_up(t[p],t[p<<1],t[p<<1|1]);
}
PII query(int p,int l,int r,int left,int right){
    if(left<=l&&r<=right)  return t[p];
    PII res=mk(0,0);
    int mid=l+r>>1;
    if(left<=mid)   push_up(res,res,query(p<<1,l,mid,left,right));
    if(right>mid)   push_up(res,res,query(p<<1|1,mid+1,r,left,right));
    return res;
}

signed main(){
	freopen("equation1.in","r",stdin);
	freopen("equation1.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)   cin>>a>>b, update(1,1,n,i,mk(a,b));
    cin>>m;
    while(m--){
        cin>>op;
        if(op==1){
            cin>>x>>a>>b;
            update(1,1,n,x,mk(a,b));
        }else{
            cin>>l>>r;
            cout<<(long long)query(1,1,n,l,r).fi<<endl;
        }
    }
    return 0;
}
