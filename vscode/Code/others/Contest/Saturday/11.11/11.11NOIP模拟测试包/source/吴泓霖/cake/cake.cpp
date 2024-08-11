#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||'9'<c){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll N=2000+5;
ll n,a[N],f[2][N];
ll pre(ll x,ll step){return step>=x?n-step+x:x-step;}
ll nxt(ll x,ll step){return x+step>n?x+step-n:x+step;}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	n=read();
	ll op=0;
	for(ll i=1;i<=n;i++)f[op][i]=a[i]=read();
	for(ll len=2;len<=n;len++){
		op^=1;
		for(ll i=1;i<=n;i++){
			ll j=nxt(i,len-1);
			if(len&1){
				ll t1=f[op^1][nxt(i,1)]+a[i],t2=f[op^1][i]+a[j];
				f[op][i]=max(t1,t2);
			}else{
				ll t1=(a[i]>=a[nxt(j,1)]?f[op^1][nxt(i,1)]:-inf),t2=(a[j]>=a[pre(i,1)]?f[op^1][i]:-inf);
				f[op][i]=max(t1,t2);
			}
			// fprintf(stderr,"f(%lld,%lld)=%lld\n",i,j,f[op][i]);
		}
	}
	ll ans=-inf;
	for(ll i=1;i<=n;i++)ans=max(ans,f[op][i]);
	printf("%lld",ans);
	return 0;
}