#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
#define file(a) freopen(#a".in","r",stdin),freopen(#a".out","w",stdout);
const int N=30;
int n,m;
ll ans;
int l[N],r[N];
ll a[N];
int num[N],tot,sum[N];
inline void chai(int x){
	tot=0;
	while(x){
		num[n-tot]=x&1;
		x>>=1;
		tot++;
	}
}

int main(){
	file(intervals);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d%lld",&l[i],&r[i],&a[i]);
	for(int s=0;s<(1<<n);++s){
		memset(sum,0,sizeof(sum));
		memset(num,0,sizeof(num));
		ll res=0;
		chai(s);
		for(int i=1;i<=n;++i) sum[i]=sum[i-1]+num[i];
		for(int i=1;i<=m;++i){
			if(sum[r[i]]-sum[l[i]-1]>=1) res=res+a[i];
		}
		ans=max(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}
