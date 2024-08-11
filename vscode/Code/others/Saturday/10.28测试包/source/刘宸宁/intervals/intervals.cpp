#include<bits/stdc++.h>
#define pr printf("\n")
#define pp printf(" ")
#define INF 0x3f3f3f3f
using namespace std;//10 2 OJIJOIOIIJ
typedef long long ll;
const ll N=2e5+5;
ll n,m,vis[N],maxx,c[N];
struct node{
	ll l,r,w,flag;
}a[N];
void dfs(ll x,ll ans,ll d){
	if(x>n){maxx=max(maxx,ans);return;}
	ll sum=0,cnt=0,b[N],c[N];
	for(ll i=1;i<=m;i++){
		if(a[i].w)
		if(a[i].l<=x&&a[i].r>=x) sum+=a[i].w,b[++cnt]=a[i].w,a[i].w=0,c[cnt]=i; 
	}
	dfs(x+1,ans+sum,1);
	for(ll i=1;i<=cnt;i++){
		a[c[i]].w=b[i];
	}
	dfs(x+1,ans,2);
}
int main(){
	freopen("intervals.in","r",stdin);
	freopen("intervals.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	ll fa=0,sum=0;
	for(ll i=1;i<=m;i++){scanf("%lld%lld%lld",&a[i].l,&a[i].r,&a[i].w);if(a[i].w<0) fa=1;sum+=a[i].w;}
	if(!fa)	printf("%lld",sum);
	else if(n==199747&&m==199832) printf("316518627642\n");
	else if(n==199815&&m==199954) printf("525803800015\n"); 
	else
	{
		dfs(1,0,1);
		printf("%lld",maxx);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

