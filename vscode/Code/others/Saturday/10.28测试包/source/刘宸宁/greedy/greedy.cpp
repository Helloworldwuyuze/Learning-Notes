#include<bits/stdc++.h>
#define pr printf("\n")
#define pp printf(" ")
#define INF 0x3f3f3f3f
using namespace std;//10 2 OJIJOIOIIJ
typedef long long ll;
const ll N=2e5+5;
ll n,m;
struct cow{
	ll wi,li,ri,len;
}a[N];
bool cmp(cow x,cow y){
	if(x.len==y.len) return x.wi>y.wi;
	return x.len<y.len;
}
ll vis[N];
int main(){
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].wi,&a[i].li,&a[i].ri);
		a[i].len=a[i].ri-a[i].li;
	}
	sort(a+1,a+1+m,cmp);
	ll sum=0;
	for(ll i=1;i<=m;i++){
		ll flag=0;
		for(ll j=a[i].li;j<=a[i].ri;j++){
			if(!vis[j]) flag=1;
			vis[j]=1;
		}
		if(flag) sum+=a[i].wi;
	}
	printf("%lld",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 2 
100 1 2 
100 1 1
*/
