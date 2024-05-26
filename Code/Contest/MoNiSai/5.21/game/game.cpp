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
#define endl '\n'

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e7 + 10;
const int MOD = 1e9 + 7;

struct seg{
	int minn[N<<2], tag[N<<2];
	void push_up(int p){
		minn[p]=min(minn[p<<1],minn[p<<1|1]);
	}
	void push_down(int p){
		if(tag[p]==0)	return ;
		tag[p<<1]+=tag[p], tag[p<<1|1]+=tag[p];
		minn[p<<1]+=tag[p], minn[p<<1|1]+=tag[p];
		tag[p]=0;
	}
	void update1(int p,int l,int r,int left,int right,int k){
		if(right<left)	return;
		if(left<=l&&r<=right){ tag[p]+=k, minn[p]+=k; return ;}
		int mid=l+r>>1;
		push_down(p);
		if(left<=mid)	update1(p<<1,l,mid,left,right,k);
		if(right>mid)	update1(p<<1|1,mid+1,r,left,right,k);
		push_up(p);
	}
	void update2(int p,int l,int r,int x,int k){
		if(l==r){ minn[p]=k; return ;}
		int mid=l+r>>1;
		push_down(p);
		if(x<=mid)	update2(p<<1,l,mid,x,k);
		else	update2(p<<1|1,mid+1,r,x,k);
		push_up(p);
	}
	int query(int p,int l,int r,int left,int right){
		if(right<left)	return INF;
		if(left<=l&&r<=right)	return minn[p];
		int mid=l+r>>1, res=INF;
		push_down(p);
		if(left<=mid)	res=min(res,query(p<<1,l,mid,left,right));
		if(right>mid)	res=min(res,query(p<<1|1,mid+1,r,left,right));
		return res;
	}
}seg1,seg2,seg3;
int n,m,a[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i)	cin>>a[i];
	for(int i=1;i<=n;++i){
		if(i!=1&&i!=n){
			seg1.update2(1,1,n,i,INF);
			seg2.update2(1,1,n,i,INF);
			seg3.update2(1,1,n,i,INF);
		}else if(i==n){
			seg1.update2(1,1,n,i,a[1]-1);
			seg2.update2(1,1,n,i,a[1]-1+i);
			seg3.update2(1,1,n,i,a[1]-1-i);
		}else{
			seg1.update2(1,1,n,i,n-a[1]);
			seg2.update2(1,1,n,i,n-a[1]+i);
			seg3.update2(1,1,n,i,n-a[1]-i);
		}
	}
	for(int i=2;i<=m;++i){
		int tmp1=seg2.query(1,1,n,a[i]+1,n), tmp2=seg3.query(1,1,n,1,a[i]);
		int dp=min(tmp1-a[i],tmp2+a[i]), delta=abs(a[i-1]-a[i]);
		// cout<<dp<<endl;
		seg1.update2(1,1,n,a[i-1],dp);
		seg2.update2(1,1,n,a[i-1],dp+a[i-1]);
		seg3.update2(1,1,n,a[i-1],dp-a[i-1]);

		seg1.update1(1,1,n,1,a[i-1]-1,delta);
		seg2.update1(1,1,n,1,a[i-1]-1,delta);
		seg3.update1(1,1,n,1,a[i-1]-1,delta);

		seg1.update1(1,1,n,a[i-1]+1,n,delta);
		seg2.update1(1,1,n,a[i-1]+1,n,delta);
		seg3.update1(1,1,n,a[i-1]+1,n,delta);
	}
	cout<<seg1.minn[1]<<endl;
	return 0;
}
