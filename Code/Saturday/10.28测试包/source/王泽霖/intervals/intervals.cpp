#include<iostream>
#include<cstdio>
using namespace std;
struct gz{
	int l,r,w;
}a[200005];
bool s[25];int n,m;
int sum[25];
long long solve(int S){
	for(int i=1; i<=n; i++){
		s[i]=S&1;
		sum[i]=sum[i-1]+s[i];
		S>>=1;
	}long long ans=0;
	for(int i=1; i<=m; i++){
		if(sum[a[i].r]-sum[a[i].l-1]){
			ans+=a[i].w;
		}
	}return ans;
}
int main(){
	freopen("intervals.in","r",stdin);
	freopen("intervals.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++){
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].w);
	}
	if(n<=20&&m<=20){
		long long ans=0;
		for(int i=0; i<(1<<n); i++){
			ans=max(ans,solve(i));
		}cout<<ans;
	}else{
		
	}
	return 0;
}
