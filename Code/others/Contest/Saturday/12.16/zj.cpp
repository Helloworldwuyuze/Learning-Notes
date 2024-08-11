#include<iostream>
#include<cstdio>
#define lson rt<<1
#define rson rt<<1|1
#define ll double
#define inf 10000000000.0
using namespace std;
struct node{
	ll sumx,sumy,sumxy,sumxx;
	ll addx,addy;
	bool cov;
	node operator+(const node a){
		node b;
		b.sumx=sumx+a.sumx;
		b.sumy=sumy+a.sumy;
		b.sumxx=sumxx+a.sumxx;
		b.sumxy=sumxy+a.sumxy;
		return b;
	}void operator=(const node a){
		sumx=a.sumx;
		sumy=a.sumy;
		sumxx=a.sumxx;
		sumxy=a.sumxy;
	}
}tr[400005];
ll x[100005],y[100005];
void pushup(int rt){tr[rt]=tr[lson]+tr[rson];}
void upd(int rt,int l,int r,ll adx,ll ady){
	tr[rt].addx+=adx;
	tr[rt].addy+=ady;
	tr[rt].sumxx+=2.0*tr[rt].sumx*1.0*adx+adx*1.0*adx*(r*1.0-l*1.0+1.0);
	tr[rt].sumxy+=adx*1.0*tr[rt].sumy+ady*1.0*tr[rt].sumx+(r*1.0-l*1.0+1*1.0)*1.0*adx*1.0*ady;
	tr[rt].sumx+=(r*1.0-l*1.0+1.0)*1.0*adx;
	tr[rt].sumy+=(r*1.0-l*1.0+1.0)*1.0*ady;
}void rebuild(int rt,int l,int r){
	tr[rt].cov=true;
	tr[rt].addx=tr[rt].addy=0;
	tr[rt].sumxy=r*1.0*(r+1.0)*(2.0*r+1.0)/6.0-l*(l-1.0)*(2.0*l-1.0)/6.0;
	tr[rt].sumxx=r*1.0*(r+1.0)*(2.0*r+1.0)/6.0-l*(l-1.0)*(2.0*l-1.0)/6.0;
	tr[rt].sumx=(l*1.0+r*1.0)*1.0*(r*1.0-l*1.0+1.0)/2.0;
	tr[rt].sumy=(l*1.0+r*1.0)*1.0*(r*1.0-l*1.0+1.0)/2.0;
}
void pushdown(int rt,int l,int r){
	int mid=(l+r)>>1;
	if(tr[rt].cov){
		rebuild(lson,l,mid);
		rebuild(rson,mid+1,r);
		tr[rt].cov=false;
	}
	upd(lson,l,mid,tr[rt].addx,tr[rt].addy);
	upd(rson,mid+1,r,tr[rt].addx,tr[rt].addy);
	tr[rt].addx=tr[rt].addy=0.0;
}
void build(int rt,int l,int r){
	tr[rt].addx=tr[rt].addy=0.0;
	tr[rt].cov=false;
	if(l==r){
		tr[rt].sumx=x[l]*1.0;
		tr[rt].sumy=y[l]*1.0;
		tr[rt].sumxx=x[l]*1.0*x[l];
		tr[rt].sumxy=x[l]*1.0*y[l];
		return;
	}int mid=(l+r)>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(rt);
}void update(int rt,int l,int r,int x,int y,ll s,ll t,int op){
	if(l>y||r<x){return;}
	if(x<=l&&r<=y){
		if(op==2) upd(rt,l,r,s,t);
		else{
			rebuild(rt,l,r);
			upd(rt,l,r,s,t);
		}
		return;
	}int mid=(l+r)>>1;
	pushdown(rt,l,r);
	update(lson,l,mid,x,y,s,t,op);
	update(rson,mid+1,r,x,y,s,t,op);
	pushup(rt);
}node query(int rt,int l,int r,int x,int y){
	if(x<=l&&r<=y){return tr[rt];}
	int mid=(l+r)>>1;
	pushdown(rt,l,r);
	if(y<=mid){return query(lson,l,mid,x,y);}
	if(x>mid){return query(rson,mid+1,r,x,y);}
	return query(lson,l,mid,x,y)+query(rson,mid+1,r,x,y);
}
int main(){
	freopen("relative444.in","r",stdin);
	freopen("relative444.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)scanf("%lf",&x[i]);
	for(int i=1; i<=n; i++)scanf("%lf",&y[i]);
	build(1,1,n);
	while(m--){
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1){
			node a=query(1,1,n,l,r);
//			printf("sumx=%.0lf  sumy=%.0lf sumxx=%.0lf sumxy=%.0lf\n",a.sumx,a.sumy,a.sumxx,a.sumxy);
			printf("%.10lf\n",(a.sumxy*1.0-a.sumx*1.0*a.sumy/(r-l+1.0))*1.0/(a.sumxx*1.0-a.sumx*1.0*a.sumx/(r-l+1.0)));
		}else{
			ll s,t;
			scanf("%lf%lf",&s,&t);
			update(1,1,n,l,r,s,t,op);
		}
	} 
	return 0;
}/*
*/ 
