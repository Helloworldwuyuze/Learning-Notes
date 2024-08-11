#include<iostream>
#include<cstdio>
#include<vector>
#define lson rt<<1
#define rson rt<<1|1
#define mod 19260817
using namespace std;
struct node{
	long long sum;
	long long laz;
}tr[2][100005<<2];int n,m;
bool upd[100005<<2];
int a[100005],b[100005];
void pushdown(int rt,int l,int r){
	if(tr[0][rt].laz){
		long long k=tr[0][rt].laz;
		tr[0][rt].laz=0;
		int mid=l+r>>1;
		tr[0][lson].laz+=k,tr[0][rson].laz+=k;
		tr[0][lson].sum+=k*(mid-l+1)%mod,tr[0][rson].sum+=k*(r-mid)%mod;
		tr[0][lson].sum%=mod;tr[0][rson].sum%=mod;
		tr[0][lson].laz%=mod,tr[0][rson].laz%=mod;
	}
}
void pushup(int rt){tr[0][rt].sum=(tr[0][lson].sum+tr[0][rson].sum)%mod;}
long long query(int rt,int l,int r,int x,int y,bool id){
//	cout<<l<<" "<<r<<endl;
	if(x<=l&&r<=y)return tr[id][rt].sum%mod;
	int mid=l+r>>1;
	pushdown(rt,l,r);
	long long ans=0;
	if(x<=mid)ans+=query(lson,l,mid,x,y,id);
	if(y>mid)ans+=query(rson,mid+1,r,x,y,id);
	return ans%mod;
}
void build(int rt,int l,int r){
	if(l==r){
		tr[0][rt].sum=a[l]%mod,tr[1][rt].sum=b[l]%mod;
		tr[0][rt].laz=tr[1][rt].laz=0;
		return;
	}int mid=l+r>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int x,int y,int k,int op){
	if(x<=l&&r<=y){
		if(op<=1)tr[op][rt].sum=(tr[op][rt].sum+k*(r-l+1)%mod)%mod,tr[op][rt].laz=(tr[op][rt].laz+k)%mod;
		return;
	}int mid=l+r>>1;
	pushdown(rt,l,r);
	if(x<=mid)update(lson,l,mid,x,y,k,op);
	if(y>mid)update(rson,mid+1,r,x,y,k,op);
	pushup(rt);
}struct que{
	int l,r,op,v;
}c[100005];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)scanf("%d",&a[i]);
		build(1,1,n);
		
		bool ok=1;
		for(int i=1; i<=m; i++){
			int op;
			int l,r,v;
			scanf("%d%d%d",&op,&l,&r);
			c[i].op=op;
			c[i].l=l;
			c[i].r=r;
			
			if(op==2||op==3){
				scanf("%d",&v);
			}c[i].v=v;
			if(op==3||op==4)ok&=(l==r);
		}if(ok){
			int lans=0;
			for(int i=1; i<=m; i++){
				int op;
				int l,r,v;
				op=c[i].op;
				l=c[i].l;
				r=c[i].r;
				v=c[i].v;
				l^=lans,r^=lans,v^=lans;
				if(op==1){
					lans=query(1,1,n,l,r,0)%mod;
					printf("%lld\n",lans);
				}
				else if(op==2)update(1,1,n,l,r,v,0);
				else if(op==3){
					b[l]=(b[l]+v)%mod;
				}
				else{
					update(1,1,n,l,l,b[l],0);
				} 
			}
		}else{
			int lans=0;
			for(int i=1; i<=m; i++){
				int op;
				int l,r,v;
				l=c[i].l,r=c[i].r,v=c[i].v;
				op=c[i].op;
				l^=lans,r^=lans,v^=lans;
				if(op==1){
					long long ans=0;
					for(int i=l; i<=r; i++)ans=(ans+a[i])%mod;
					lans=ans;
					printf("%lld\n",ans);
				}else if(op==2){
					for(int i=l; i<=r; i++)a[i]=(a[i]+v)%mod;
				}else if(op==3){
					for(int i=l; i<=r; i++)b[i]=(b[i]+v)%mod;
				}else{
					for(int i=l; i<=r; i++)a[i]=(a[i]+b[i])%mod;
				}
			}
		}
	
	return 0;
}/*
10 5
1 4 5 2 8 8 3 4 8 1
1 1 6
2 1 3 3
3 4 4 5
4 4 4
1 1 10

*/
