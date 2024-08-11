#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
#define il inline
#define mod 19260817
#define N 300005
#define lc(x) (x<<1)
#define rc(x) (x<<1)|1
il ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') {f=-1;} c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
struct matrix {
	int a[5][5],n,m;
	matrix() {
		memset(a,0,sizeof(a));
	}
	matrix(ll _n,ll _m) {
		n=_n,m=_m;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=0;
	}
	void operator =(const matrix B) {
		n=B.n,m=B.m;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=B.a[i][j];
	}
	matrix operator *(const matrix B)const {
		matrix ans(n,B.m);
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=B.m;j++) {
				for(int k=1;k<=m;k++) ans.a[i][j]=(ans.a[i][j]+1ll*a[i][k]*B.a[k][j]%mod)%mod;
				ans.a[i][j]=(ans.a[i][j]%mod+mod)%mod;
			}
		}
		return ans;
	}
	matrix operator +(const matrix B) {
		matrix ans(n,m);
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ans.a[i][j]=(a[i][j]+B.a[i][j]+mod)%mod;
		return ans;
	}
	bool operator ==(const matrix B)const {
		if(n!=B.n||m!=B.m) return 0;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]!=B.a[i][j]) return 0;
		return 1;
	}
};
matrix I,T[5];
struct sgt {
	ll l,r;
	matrix sum,tag;
};
sgt tr[N<<2];
ll n,q,lans=0,a[N],b[N];
il void push_up(ll now) {
	tr[now].sum=tr[lc(now)].sum+tr[rc(now)].sum;
}
il void build(ll now,ll l,ll r) {
	tr[now].l=l,tr[now].r=r;
	tr[now].sum=matrix(3,1),tr[now].tag=I;
	if(l==r) {
		tr[now].sum.a[1][1]=a[l];
		tr[now].sum.a[2][1]=b[l];
		tr[now].sum.a[3][1]=1;
		return;
	}
	ll mid=(l+r)>>1;
	build(lc(now),l,mid);
	build(rc(now),mid+1,r);
	push_up(now);
}
il void push_down(ll now) {
	if(!(tr[now].tag==I)) {
		tr[lc(now)].sum=tr[now].tag*tr[lc(now)].sum;
		tr[lc(now)].tag=tr[now].tag*tr[lc(now)].tag;
		tr[rc(now)].sum=tr[now].tag*tr[rc(now)].sum;
		tr[rc(now)].tag=tr[now].tag*tr[rc(now)].tag;
		tr[now].tag=I;
	}
}
il void modify(ll nl,ll nr,ll l,ll r,ll now,int id) {
	if(nl<=l&&r<=nr) {
		tr[now].sum=T[id]*tr[now].sum;
		tr[now].tag=T[id]*tr[now].tag;
		return;
	}
	push_down(now);
	ll mid=(l+r)>>1;
	if(nl<=mid) modify(nl,nr,l,mid,lc(now),id);
	if(mid<nr) modify(nl,nr,mid+1,r,rc(now),id);
	push_up(now);
}
il ll query(ll qx,ll qy,ll l,ll r,ll now) {
	if(qx<=l&&r<=qy) return tr[now].sum.a[1][1];
	push_down(now);
	ll mid=(l+r)>>1,ans=0;
	if(qx<=mid) ans=(ans+query(qx,qy,l,mid,lc(now)))%mod;
	if(mid<qy) ans=(ans+query(qx,qy,mid+1,r,rc(now)))%mod;
	return ans;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	I=matrix(3,3);
	for(int i=1;i<=3;i++) I.a[i][i]=1;
	for(int i=2;i<=4;i++) T[i]=I;
	T[2].a[1][3]=1;
	T[3].a[2][3]=1;
	T[4].a[1][2]=1;
	n=read(),q=read();
	for(int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	for(int i=1;i<=q;i++) {
		ll opt=read(),l=read()^lans,r=read()^lans;
		switch(opt) {
			case 1:{
				printf("%lld\n",lans=query(l,r,1,n,1));
				break;
			}
			case 2:{
				ll v=read()^lans;
				T[2].a[1][3]=v;
				modify(l,r,1,n,1,2);
				break;
			}
			case 3:{
				ll v=read()^lans;
				T[3].a[2][3]=v;
				modify(l,r,1,n,1,3);
				break;
			}
			case 4:{
				modify(l,r,1,n,1,4);
				break;
			}
		}
	}
	return 0;
}

