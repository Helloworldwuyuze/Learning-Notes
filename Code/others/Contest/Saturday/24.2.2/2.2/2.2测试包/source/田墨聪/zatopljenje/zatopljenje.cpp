#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
#define il inline
#define N 200005
il ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') {f=-1;} c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
ll n,q,h[N];
int main() {
	freopen("zatopljenje.in","r",stdin);
	freopen("zatopljenje.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++) h[i]=read();
	if(n<=2000&&q<=2000) {
		while(q--) {
			ll l=read(),r=read(),x=read();
			ll ans=0;
			for(int i=l+1;i<=r;i++) {
				if(h[i-1]>x&&h[i]>x) continue;
				if(h[i-1]>x&&h[i]<=x) ans++;
			}
			if(h[r]>x) ans++;
			printf("%lld\n",ans);
		}
	}
	else {
		ll p=1;
		for(int i=2;i<=n;i++) if(h[i]<=h[p]) p=i;
		while(q--) {
			ll l=read(),r=read(),x=read();
			if(l<p&&p<r) {
				if(max(h[l],h[r])<=x) printf("0\n");
				else {
					if(min(h[l],h[r])>x) {
						if(h[p]>x) printf("1\n");
						else printf("2\n");
					}
					else printf("1\n");
				}
			}
			else {
				if(max(h[l],h[r])>x) printf("1\n");
				else printf("0\n");
			}
		}
	}
	return 0;
}

