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
// #define endl '\n'

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e7 + 10;

int n,m,a[N],b[N];

int t[N<<2];
int cover[N<<2], tag[N<<2];

void push_up(int p){ t[p]=t[p<<1]+t[p<<1|1];}
void push_down(int p,int l,int r){
    if(tag[p]==0)   return ;
    int mid=l+r>>1;
    cover[p<<1]=cover[p<<1|1]=true;
    tag[p<<1]=tag[p], tag[p<<1|1]=tag[p];
    t[p<<1]=(mid-l+1)*tag[p], t[p<<1|1]=(r-mid)*tag[p];
    tag[p]=0;
}
void update(int p,int l,int r,int left,int right,int k){
    cout<<p<<" "<<l<<" "<<r<<" "<<left<<" "<<right<<" "<<k<<endl;
    if(left<=l&&r<=right){ tag[p]=k, t[p]=k*(r-l+1); cover[p]=true; return ;}
    int mid=l+r>>1;
    push_down(p,l,r);
    if(left<=mid)   update(p<<1,l,mid,left,right,k);
    if(right>mid)    update(p<<1|1,mid+1,r,left,right,k);
    push_up(p);
}
void modify(int p,int l,int r,int x,int k){
    if(l==r){
        cover[p]=true;
        if(k<0) t[p]+=k;
        else    t[p]=k;
        return ;
    }
    int mid=l+r>>1;
    push_down(p,l,r);
    if(x<=mid)  modify(p<<1,l,mid,x,k);
    else    modify(p<<1|1,mid+1,r,x,k);
    push_up(p);
}

bool queryco(int p,int l,int r,int x){
    if(l==r)    return cover[p];
    int mid=l+r>>1;
    push_down(p,l,r);
    if(x<=mid)  return queryco(p<<1,l,mid,x);
    else    return queryco(p<<1|1,mid+1,r,x);
}
int query(int p,int l,int r,int left,int right){
    if(left<=l&&r<=right)    return t[p];
    int mid=l+r>>1, res=0;
    push_down(p,l,r);
    if(left<=mid)  res+=query(p<<1,l,mid,left,right);
    if(right>mid)  res+=query(p<<1|1,mid+1,r,left,right);
    return res;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)	cin>>a[i];
	for(int i=1;i<=n;++i)	cin>>b[i];
	while(m--){
		int op, x, y, k;
		cin>>op;
		if(op==1){
			cin>>x>>y>>k;
            modify(1,1,n,y,x);
            if(k>2) update(1,1,n,y+1,y+k-1,1);
			if(y+k<=n)  modify(1,1,n,y+k,-x-k+1);
		}else{
			cin>>x;
			bool cov = queryco(1,1,n,x);
            cout<<cov<<" "<<query(1,1,n,1,x)<<endl;
            if(cov) cout<<a[query(1,1,n,1,x)]<<endl;
            else    cout<<b[x]<<endl;
		}
        for(int i=1;i<=n<<1;++i)    cout<<cover[i]<<" ";
        cout<<endl;
        for(int i=1;i<=n<<1;++i)    cout<<t[i]<<" ";
        cout<<endl;
        for(int i=1;i<=n<<1;++i)    cout<<tag[i]<<" ";
        cout<<endl;
	}
	return 0;
}
