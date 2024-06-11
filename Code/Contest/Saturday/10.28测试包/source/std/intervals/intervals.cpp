#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#define ls(p) (p<<1)
#define rs(p) (p<<1)+1
#define ll long long
using namespace std;
const int N=200005;
int n,m;
struct node{
	int l,r;
	ll a;
}q[N];
bool cmp(node x,node y){
	return x.r<y.r;
}
struct nd{
	ll mx,lz;
}tree[N*4];
void pushup(int p){
	tree[p].mx=max(tree[ls(p)].mx,tree[rs(p)].mx);
}
void pushdown(int p){
	ll tag=tree[p].lz;
	if(tag!=0){
		tree[ls(p)].lz+=tag;
		tree[rs(p)].lz+=tag;
		tree[ls(p)].mx+=tag;
		tree[rs(p)].mx+=tag;
		tree[p].lz=0;
	}
}
void build(int p,int l,int r){
	tree[p].lz=0;
	if(l==r){
		tree[p].mx=0ll;
		return;
	}
	int mid=(l+r)>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	pushup(p);
}
void update(int p,int pl,int pr,int l,int r,ll x){
	if(l<=pl&&pr<=r){
		tree[p].mx+=x;
		tree[p].lz+=x;
		return;
	}
	pushdown(p);
	int mid=(pl+pr)>>1;
	if(l<=mid)update(ls(p),pl,mid,l,r,x);
	if(r>mid)update(rs(p),mid+1,pr,l,r,x);
	pushup(p);
}
int main(){
	freopen("intervals.in","r",stdin);
	freopen("intervals.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%lld",&q[i].l,&q[i].r,&q[i].a);
	sort(q+1,q+m+1,cmp);
	build(1,1,n);
	int j=1;
	for(int i=1;i<=n;i++){
		update(1,1,n,i,i,max(0ll,tree[1].mx));
		while(q[j].r==i&&j<=m){
			update(1,1,n,q[j].l,q[j].r,q[j].a);
			j++;
		}
	}
	printf("%lld\n",max(0ll,tree[1].mx));
	return 0;
}
