#include<bits/stdc++.h>
using namespace std;
const int wat=10005;
int t,n,m;
int a[105][105],flo[105][105];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n+1;++i)flo[i][0]=0;
		for(int i=0;i<=m+1;++i)flo[0][i]=0;	
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)scanf("%d",&a[i][j]);
		for(int i=2;i<=n;++i){
			flo[i][1]=0;
			for(int j=2;j<=m;++j)flo[i][j]=wat;
			for(int j=2;j<=m;++j) flo[i][j]=max(min(a[i-1][j]+flo[i-1][j],a[i][j-1]+flo[i][j-1])-a[i][j],0);
		}
		for(int i=1;i<=n;++i)flo[i][m]=flo[i][1]=0;
		for(int i=1;i<=m;++i)flo[n][i]=flo[1][i]=0;
		for(int x=1;x<=3000;++x)for(int i=2;i<=n-1;++i)for(int j=2;j<=m-1;++j)flo[i][j]=max(min(a[i-1][j]+flo[i-1][j],min(min(a[i][j-1]+flo[i][j-1],a[i][j+1]+flo[i][j+1]),a[i+1][j]+flo[i+1][j]))-a[i][j],0);
		for(int i=1;i<=n;++i)flo[i][m]=flo[i][1]=0;
		for(int i=1;i<=m;++i)flo[n][i]=flo[1][i]=0;
		long long ans=0;
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)ans+=flo[i][j];
		printf("%lld\n",ans);
	}
	return 0;
}
