#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define ll long long
#define il inline
#define N 300005
#define lc(x) (x<<1)
#define rc(x) (x<<1)|1
il ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') {f=-1;} c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
set<ll> s;
ll n,a[N],mex[N],lst[N],nxt[N],ans;
struct seg {
	ll l,r;
	ll maxn,sum,tag;
};
seg tr[N<<2];
il void push_up(ll now) {
	tr[now].sum=tr[lc(now)].sum+tr[rc(now)].sum;
	tr[now].maxn=max(tr[lc(now)].maxn,tr[rc(now)].maxn);
}
il void build(ll now,ll l,ll r) {
	tr[now].l=l,tr[now].r=r,tr[now].tag=-1;
	if(l==r) {
		tr[now].sum=tr[now].maxn=mex[l];
		return;
	}
	ll mid=(l+r)>>1;
	build(lc(now),l,mid);
	build(rc(now),mid+1,r);
	push_up(now);
}
il void push_down(ll now) {
	if(tr[now].tag!=-1) {
		tr[lc(now)].sum=(tr[lc(now)].r-tr[lc(now)].l+1)*tr[now].tag;
		tr[lc(now)].maxn=tr[lc(now)].tag=tr[now].tag;
		tr[rc(now)].sum=(tr[rc(now)].r-tr[rc(now)].l+1)*tr[now].tag;
		tr[rc(now)].maxn=tr[rc(now)].tag=tr[now].tag;
		tr[now].tag=-1;
	}
}
il void modify(ll nl,ll nr,ll l,ll r,ll now,ll k) {
	if(nl>nr) return;
	if(nr>n) return;
	if(nl<=l&&r<=nr) {
		tr[now].maxn=tr[now].tag=k;
		tr[now].sum=(r-l+1)*k;
		return;
	}
	push_down(now);
	ll mid=(l+r)>>1;
	if(nl<=mid) modify(nl,nr,l,mid,lc(now),k);
	if(mid<nr) modify(nl,nr,mid+1,r,rc(now),k);
	push_up(now);
}
il ll query_idx(ll l,ll r,ll now,ll q) {
	if(l==r) {
		if(tr[now].maxn>=q) return l;
		else return n+1;
	}
	push_down(now);
	ll mid=(l+r)>>1,lmax=tr[lc(now)].maxn;
	if(lmax>=q) return query_idx(l,mid,lc(now),q);
	else return query_idx(mid+1,r,rc(now),q);
}
int main() {
	freopen("meximum.in","r",stdin);
	freopen("meximum.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=0;i<=300000;i++) s.insert(i);
	for(int i=1;i<=n;i++) {
		auto it=s.find(a[i]);
		if(it!=s.end()) s.erase(it);
		mex[i]=*(s.lower_bound(0));
		ans+=mex[i];
	}
	for(int i=1;i<=n;i++) nxt[i]=n+1;
	for(int i=1;i<=n;i++) {
		nxt[lst[a[i]]]=i;
		lst[a[i]]=i;
	}
	build(1,1,n);
	for(int i=2;i<=n;i++) {
		modify(i-1,i-1,1,n,1,0);
		int p=query_idx(1,n,1,a[i-1]+1);
		if(p<=nxt[i-1]-1) modify(p,nxt[i-1]-1,1,n,1,a[i-1]);
		ans+=tr[1].sum;
	}
	printf("%lld\n",ans);
	return 0;
}

