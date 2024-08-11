#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define ll long long
#define il inline
#define N 1000005
#define mod 998244353
il ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') {f=-1;} c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
ll n,p,a[N],fact[N],inv[N];
vector<ll> s[N],poww[N];
il ll qpow(ll a,ll b) {
	ll ans=1;
	while(b) {
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
il ll C(ll n,ll m) {
	if(m>n) return 1;
	return fact[n]*inv[m]%mod*inv[n-m]%mod;
}
il void mian() {
	n=read(),p=read();
	ll sum=0;
	for(int i=1;i<=n;i++) {
		a[i]=read();
		sum=(sum+a[i])%mod;
	}
	for(int i=1;i<=n;i++) {
		poww[i].resize(p+1);
		poww[i][0]=1;
		for(int j=1;j<=p;j++) poww[i][j]=poww[i][j-1]*i%mod;
	}
	for(int k=0;k<=p;k++) {
		s[k].push_back(0);
		for(int i=1;i<=n;i++) s[k].push_back((s[k][i-1]+poww[i][k]*a[i]%mod)%mod);
	}
	ll base=mod-1,ans=0;
	for(int k=0;k<=p;k++) {
		base=(mod-base)%mod;
		ll tmp=0;
		for(int i=1;i<=n;i++) tmp=(tmp+poww[i][p-k]*a[i]%mod*s[k][i]%mod)%mod;
		ans=(ans+base*C(p,k)%mod*tmp%mod)%mod;
	}
	printf("%lld\n",2ll*ans%mod*qpow(sum*sum%mod,mod-2)%mod);
}
il void clean() {
	for(int i=1;i<=n;i++) a[i]=0;
	for(int i=0;i<=p;i++) s[i].clear();
	for(int i=1;i<=n;i++) poww[i].clear();
}
int main() {
	freopen("ballrandom.in","r",stdin);
	freopen("ballrandom.out","w",stdout);
	fact[0]=1;
	for(ll i=1;i<=1000000;i++) fact[i]=fact[i-1]*i%mod;
	inv[1000000]=qpow(fact[1000000],mod-2);
	for(int i=999999;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	int t=read();
	while(t--) {
		mian();
		clean();
	}
	return 0;
}
