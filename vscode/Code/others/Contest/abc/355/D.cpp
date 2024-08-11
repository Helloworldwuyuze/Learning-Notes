#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>
#include<unordered_map>

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
#define endl '\n'

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10;
const int M = 1e6 + 10;

struct ques{
	int l,r;
}q[N];

int t[N], n, m;
bool cmp(ques x,ques y){
	return x.r<y.r;
}
int sum[N<<2];
void update(int p,int l,int r,int x,int k){
	if(l==r){ sum[p]+=k; return ;}
	int mid=l+r>>1;
	if(x<=mid)	update(p<<1,l,mid,x,k);
	else	update(p<<1|1,mid+1,r,x,k);
	sum[p]=sum[p<<1]+sum[p<<1|1];
}
int query(int p,int l,int r,int left,int right){
	if(left<=l&&r<=right)	return sum[p];
	int mid=l+r>>1, res=0;
	if(left<=mid)	res+=query(p<<1,l,mid,left,right);
	if(right>mid)	res+=query(p<<1|1,mid+1,r,left,right);
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>q[i].l>>q[i].r, t[++m]=q[i].l, t[++m]=q[i].r;
	sort(t+1,t+1+m);
	m=unique(t+1,t+1+m)-t-1;
	for(int i=1;i<=n;++i){
		q[i].l=lower_bound(t+1,t+1+m,q[i].l)-t; 
		q[i].r=lower_bound(t+1,t+1+m,q[i].r)-t;
	}
	sort(q+1,q+1+n,cmp);
	long long ans=0;
	for(int i=1;i<=n;++i){
		ans+=query(1,1,n<<1,q[i].l,q[i].r);  
		update(1,1,n<<1,q[i].r,1);
	}
	cout<<ans<<endl;
	return 0;
}