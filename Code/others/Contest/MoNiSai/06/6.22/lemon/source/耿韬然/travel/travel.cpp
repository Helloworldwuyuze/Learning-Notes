#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

char buf[1<<20], *p1, *p2;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?0:*p1++)

inline ll read() {
	ll x=0, f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48), ch=getchar();
	return x*f;
}

#define N 100010
#define MOD 19260817
int n, m, opt, l, r;
ll buildSource[N], v, lst;
template <typename T> struct seg {
	#define ls (p<<1)
	#define rs (p<<1|1)
	T t[N<<2], tag[N<<2];
	void push_up(ll p) {t[p]=t[ls]+t[rs];}
	void build(ll p, ll l, ll r) {
		tag[p]=0; if (l==r) return t[p]=buildSource[l], void(); ll mid=l+r>>1;
		build(ls, l, mid), build(rs, mid+1, r), push_up(p);
	}
	void f(ll p, ll l, ll r, T k) {tag[p]+=k, t[p]=t[p]+k*(r-l+1);};
	void push_down(ll p, ll l, ll r) {
		ll mid=l+r>>1; f(ls, l, mid, tag[p]), f(rs, mid+1, r, tag[p]), tag[p]=0;
	}
	void update(ll nl, ll nr, ll l, ll r, ll p, T k) {
		if (nl<=l&&r<=nr) return t[p]+=k*(r-l+1), tag[p]+=k, void();
		push_down(p, l, r); ll mid=l+r>>1;
		if (nl<=mid) update(nl, nr, l, mid, ls, k);
		if (nr>mid) update(nl, nr, mid+1, r, rs, k);
		push_up(p);
	}
	T query(ll nl, ll nr, ll l, ll r, ll p) {
		if (nl<=l&&r<=nr) return t[p];
		push_down(p, l, r); T res=0; ll mid=l+r>>1;
		if (nl<=mid) res+=query(nl, nr, l, mid, ls);
		if (nr>mid) res+=query(nl, nr, mid+1, r, rs);
		return res;
	}
};

seg<ll> a, b;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	n=read(), m=read();
	for (int i=1; i<=n; ++i) buildSource[i]=read();
	a.build(1, 1, n);
	while (m--) {
		opt=read(), l=read()^lst, r=read()^lst;
		if (opt==2||opt==3) v=read()^lst;
		if (opt==1) printf("%lld\n", lst=(a.query(l, r, 1, n, 1)+MOD)%MOD);
		if (opt==2) a.update(l, r, 1, n, 1, v);
		if (opt==3) b.update(l, r, 1, n, 1, v);
		if (opt==4) {
			for (int i=l; i<=r; ++i) {
				v=(b.query(i, i, 1, n, 1)+MOD)%MOD;
				a.update(i, i, 1, n, 1, v);
			}
		}
	}
	return 0;
}
