#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int N=3e5+5;
int n,m,a[N];
ll mod=19260817;
struct Tree{
	struct node{ll l,r,sum,lazy;}tree[N<<2];
	#define rt tree[root]
	#define lson tree[root<<1]
	#define rson tree[root<<1|1]
	inline void pushup(ll root){
		rt.sum=lson.sum+rson.sum;rt.sum%=mod;
	}
	inline void pd(ll root){
		ll lazy=rt.lazy;if(!lazy) return;
		lson.sum+=(lson.r-lson.l+1)*lazy,lson.lazy+=lazy;lson.sum%=mod,lson.lazy%=mod;
		rson.sum+=(rson.r-rson.l+1)*lazy,rson.lazy+=lazy;rson.sum%=mod,rson.lazy%=mod;
		rt.lazy=0;
	}
	inline void build(ll root,ll l,ll r){
		rt.l=l,rt.r=r;if(l==r){rt.sum=a[l]%mod;return;}
		ll mid=l+r>>1;build(root<<1,l,mid),build(root<<1|1,mid+1,r);
		pushup(root);
	}
	inline void upd(ll root,ll x,ll y,ll k){
		ll l=rt.l,r=rt.r;if(x<=l&&y>=r){rt.sum+=(r-l+1)*k%mod,rt.lazy+=k;rt.sum%=mod,rt.lazy%=mod;return;}
		ll mid=l+r>>1;pd(root);if(x<=mid) upd(root<<1,x,y,k);if(y>mid) upd(root<<1|1,x,y,k);
		pushup(root);
	}
	inline ll ask(ll root,ll x,ll y){
		ll l=rt.l,r=rt.r;if(x<=l&&y>=r) return rt.sum%mod;
		ll mid=l+r>>1,ans=0;pd(root);if(x<=mid) ans+=ask(root<<1,x,y)%mod;if(y>mid) ans+=ask(root<<1|1,x,y)%mod;
		return ans%mod;
	}
}A,B;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	A.build(1,1,n);for(int i=1;i<=n;i++) a[i]=0;B.build(1,1,n);ll las=0;
	for(int i=1;i<=m;i++){
		int op,l,r,v;scanf("%d%d%d",&op,&l,&r);l^=las,r^=las;
		if(op==1){las=(A.ask(1,l,r)%mod)%mod;printf("%lld\n",las);}
		if(op==2){scanf("%d",&v);v^=las;A.upd(1,l,r,v);}
		if(op==3){scanf("%d",&v);v^=las;B.upd(1,l,r,v);}
		if(op==4){
			for(int j=l;j<=r;j++){
				A.upd(1,j,j,B.ask(1,j,j));
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 4
1 1 2 3 1
1 2 4
3 4 2 2
4 7 5
1 4 2
*/
