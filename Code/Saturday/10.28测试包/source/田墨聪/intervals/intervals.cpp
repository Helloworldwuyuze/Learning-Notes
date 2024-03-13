#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define il inline
#define N 200005
il ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
ll n,m,l[N],r[N],a[N];
int main() {
	freopen("intervals.in","r",stdin);
	freopen("intervals.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++) l[i]=read(),r[i]=read(),a[i]=read();
	if(n<=25) {
		ll ans=0;
		for(ll i=0;i<(1ll<<n);i++) {
			ll tmp=0;
			for(int j=1;j<=m;j++) {
				ll x=i>>(l[j]-1);
				//cout<<x<<' '<<((x>>(r[j]-l[j]+1))<<(r[j]-l[j]+1))<<endl;
				if(x!=((x>>(r[j]-l[j]+1))<<(r[j]-l[j]+1))) tmp+=a[j];
			}
			ans=max(ans,tmp);
		}
		printf("%lld\n",ans);
		return 0;
	}
	else cout<<0<<endl;
	return 0;
}

