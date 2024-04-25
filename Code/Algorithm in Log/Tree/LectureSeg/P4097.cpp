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
const int N = 1e5 + 10;
const int M = 1e6 + 10;
const int MODx = 39989;
const int MODy = 1e9;

struct line{
    double k,b;
    int id;
    line(){}
    line(double x0,double y0,double x1,double y1,int Id){
        if(x1-x0<eps){ k=0; b=max(y0,y1);}
        else{
            k=(y1-y0)/(x1-x0);
            b=y0-x0*k;
        }
        id=Id;
    }
    double val(int x){ return k*x+b; }
}l[N],t[N<<2];
int lastans,n,op,k,x0,y0,x1,y1;
int cnt;

void update(int p,int l,int r,int left,int right,line g){
    if(left<=l&&r<=right){
        if(t[p].id==0){ t[p]=g; return ;}
        int mid=l+r>>1;
        if(fabs(t[p].val(mid)-g.val(mid))<eps){
            if(t[p].id>g.id)    swap(t[p],g);
        }
        else if(t[p].val(mid)<g.val(mid))   swap(t[p],g);
        if(t[p].val(l)<g.val(l)+eps)    update(p<<1,l,mid,left,right,g);
        if(t[p].val(r)<g.val(r)+eps)    update(p<<1|1,mid+1,r,left,right,g);
        return ;
    }
    int mid=l+r>>1;
    if(left<=mid)   update(p<<1,l,mid,left,right,g);
    if(right>mid)   update(p<<1|1,mid+1,r,left,right,g);
}
line query(int p,int l,int r,int x){
    if(l==r)    return t[p];
    int mid=l+r>>1; line res;
    if(x<=mid)  res=query(p<<1,l,mid,x);
    else    res=query(p<<1|1,mid+1,r,x);
    if(fabs(t[p].val(x)-res.val(x))<eps) return res.id<t[p].id?res:t[p];
    else    return res.val(x)>t[p].val(x)?res:t[p];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    while(n--){
        cin>>op;
        if(op==1){
            cin>>x0>>y0>>x1>>y1;
            x0=(x0+lastans-1)%MODx+1, x1=(x1+lastans-1)%MODx+1;
            y0=(y0+lastans-1)%MODy+1, y1=(y1+lastans-1)%MODy+1;
            if(x0>x1)   swap(x0,x1), swap(y0,y1);
            update(1,1,MODx,x0,x1,line(x0,y0,x1,y1,++cnt));
        }else{
            cin>>k;
            k=(k+lastans-1)%MODx+1;
            lastans=query(1,1,MODx,k).id;
            cout<<lastans<<endl;
        }
    }
    return 0;
}

