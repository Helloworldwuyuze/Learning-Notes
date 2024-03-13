#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q;
int a[N]; 
int hmi[N],hii[N],an[N];
int qq[N];
int ans[N],cnt=0;
int main()
{
	freopen("dizalo.in","r",stdin);
	freopen("dizalo.out","w",stdout);
	scanf("%d%d",&n,&q);
	cnt=1;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	int mi=0x3f3f3f3f;
	int mii=0;
	hii[0]=0;
	for(int i=n;i>=1;--i)
	{
		hmi[i]=mi,hii[i]=mii;
		if(a[i]<mi) mi=a[i],mii=i;
	}
	long long anss=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]>hmi[i]) ans[i]++;
		else
		{
			for(int j=1;j<=i;++j) if(a[j]>a[i]) ans[i]++,qq[j]++;
			ans[i]++;
		}
		anss+=ans[i];
	//	cout<<i<<" "<<a[i]<<" "<<ans[i]<<endl;
	}
/*	for(int i=1;i<=n;i++) cout<<qq[i]+1<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";*/
	printf("%lld ",anss);
	long long ans2=anss,ans3=anss;
	for(int i=1;i<=q;i++) 
	{
		int x;
		scanf("%d",&x);
		anss=anss-ans[x]-(hmi[x]<a[x]);
		ans3=ans2-ans[x];
		ans2=ans2-qq[x]-1;
		printf("%lld ",max((long long)0,min(min(ans2,ans3),anss)));	
	} 
	return 0;
}
 

