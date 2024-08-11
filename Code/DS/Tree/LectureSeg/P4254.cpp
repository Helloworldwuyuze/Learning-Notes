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
const int M = 5e4 + 10;
const int MODx = 39989;
const int MODy = 1e9;

struct line{
    double k,b;
    int id;
    line(){id=0;}
    line(double _k,double _b,int _id){ k=_k, b=_b; id=_id;}
    double val(int x){ return k*x+b;}
}t[M<<2];
int n,cnt;
string op;

void update(int p,int l,int r,line f){
    if(!t[p].id){ t[p]=f; return ;}
    int mid=l+r>>1;
    if(t[p].val(mid)<f.val(mid)&&!(fabs(t[p].val(mid)-f.val(mid))<eps)) swap(t[p],f);
    if(t[p].val(l)<f.val(l)+eps)    update(p<<1,l,mid,f);
    if(t[p].val(r)<f.val(r)+eps)    update(p<<1|1,mid+1,r,f);
    return ;
}
double query(int p,int l,int r,int x){
    if(l==r)    return t[p].val(x);
    int mid=l+r>>1;
    if(x<=mid)  return max(query(p<<1,l,mid,x),t[p].val(x));
    else    return max(query(p<<1|1,mid+1,r,x),t[p].val(x));
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    while(n--){
        cin>>op;
        if(op=="Project"){
            double k,b;
            cin>>b>>k; b-=k;
            update(1,1,M-10,line(k,b,++cnt));
        }else{
            int k;
            cin>>k;
            cout<<(int)(query(1,1,M-10,k)/100)<<endl;
        }
    }
    return 0;
}

