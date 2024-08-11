#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define ll long long
#define il inline
#define N 100005
il ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') {f=-1;} c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
il ll lowbit(ll x) {
	return x&(-x);
}
ll n,q,a[N],b[N],id[N],sum[N],sum2[N],vis[N],c[N],dp[N];
ll ans=0;
ll tr[N],tr2[N];
il void modify(ll p,ll x) {
	for(ll i=p;i<=n;i+=lowbit(i)) tr[i]+=x;
}
il ll query(ll p) {
	ll res=0;
	for(ll i=p;i>=1;i-=lowbit(i)) res+=tr[i];
	return res;
}
il void modify2(ll p,ll x) {
	for(ll i=p;i<=n;i+=lowbit(i)) tr2[i]+=x;
}
il ll query2(ll p) {
	ll res=0;
	for(ll i=p;i>=1;i-=lowbit(i)) res+=tr2[i];
	return res;
}
int main() {
	freopen("dizalo.in","r",stdin);
	freopen("dizalo.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++) a[i]=read();
	if(n<=1000&&q<=1000) {
		b[0]=1e9;
		for(int i=1;i<=n;i++) b[i]=a[i],id[b[i]]=i;
		for(int i=1;i<=n;i++) {
			ll p=i;
			while(a[p]!=i) p++;
			ans+=p-i+1;
			for(int j=p;j>i;j--) swap(a[j],a[j-1]);
			a[i]=0;
			sort(a+i+1,a+p+1);
		}
		printf("%lld ",ans);
		while(q--) {
			ll x=read();
			bool ok=0;
			ll minn=0;
			for(int i=x+1;i<=n;i++) {
				if(b[i]<b[x]) {
					ok=1;
					if(b[i]<b[minn]) minn=i;
				}
			}
			if(!ok) {
				for(int i=1;i<x;i++) if(!vis[i]) ans--;
			}
			else {
				ll now=minn;
				ans--;
				for(int i=b[minn]+1;i<=b[x];i++) {
					if(id[i]>now) {
						ans--;
						now=id[i];
					}
				}
			}
			vis[x]=1;
			ans--;
			printf("%lld ",ans);
		}
		return 0;
	}
	for(int i=1;i<=n;i++) {
		sum[a[i]]+=query(n)-query(a[i]);
		modify(a[i],1);
	}
	for(int i=n;i>=1;i--) {
		sum2[a[i]]+=query2(a[i]);
		modify2(a[i],1);
	}
	memset(tr2,0,sizeof(tr2));
	ll cnt=n;
	for(int i=1;i<=n;i++) if(sum2[a[i]]==0) ans+=sum[a[i]];
	printf("%lld ",ans+cnt);
	while(q--) {
		ll x=read();
		ans-=sum2[a[x]];
		if(sum2[a[x]]==0) ans-=sum[a[x]];
		ans+=query2(n);
		cnt--;
		printf("%lld ",ans+cnt);
		modify2(a[x],1);
	}
	putchar('\n');
	return 0;
}

