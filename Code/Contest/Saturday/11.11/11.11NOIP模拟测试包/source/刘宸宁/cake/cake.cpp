/*
5 
2 8 1 10 9
*/
#include<bits/stdc++.h>
#define pr printf("\n")
#define pp printf(" ")
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll N=2e3+5;
ll n,a[N],maxx=-INF,flag;
void dfs(ll x,ll lef,ll rig,ll sum,ll cnt){
	if(cnt<=1){
		maxx=max(maxx,sum);
		return;
	}
	if(a[lef]>a[rig]){
		dfs((lef-1+n)%n,(lef-2+n)%n,rig,sum+a[(lef-1+n)%n],cnt-2);
		dfs(rig,(lef-1+n)%n,(rig+1)%n,sum+a[rig],cnt-2);
	}
	else{
		dfs(lef,(lef-1+n)%n,(rig+1)%n,sum+a[lef],cnt-2);
		dfs((rig+1)%n,lef,(rig+2)%n,sum+a[(rig+1)%n],cnt-2);
	}
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=0;i<n;i++) scanf("%lld",&a[i]);
	for(ll i=0;i<n;i++)
	{
		if(i==6) flag=1;
		dfs(i,(i-1+n)%n,(i+1)%n,a[i],n-1);
		if(i==6) flag=0;
	}
	printf("%lld\n",maxx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
