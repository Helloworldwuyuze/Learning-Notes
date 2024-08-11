#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
const int N=20+5,M=2e5+5;
int n,m,k,a[N],b[N],c[N],no[N],s[N];
ll ans;
void dfs(int x){
	if(x!=n+1){
		no[x]=1;
		dfs(x+1);
		no[x]=0;
		dfs(x+1);
		return ;
	} 
	ll ant=0;
	
	for(int i=1;i<=n;i++)s[i]=s[i-1]+no[i];
	for(int i=1;i<=m;i++){
		if(s[a[i]-1]-s[b[i]])ant+=c[i];
	}
	//if(no[1]==1&&no[5]==1)printf("%lld\n",ant);
	ans=max(ant,ans);
}
int main(){
	freopen("intervals.in","r",stdin);
	freopen("intervals.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	ans=-1;
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
/*
6 8 
5 5 3 
1 1 10 
1 6 -8 
3 6 5 
3 4 9 
5 5 -2
1 3 -6 
4 6 -7

*/
