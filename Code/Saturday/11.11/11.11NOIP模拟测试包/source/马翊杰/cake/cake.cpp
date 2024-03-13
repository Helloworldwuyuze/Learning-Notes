#include<bits/stdc++.h>
using namespace std;
const int N=4005;
long long n;
long long a[N*2];
long long f[N][N];
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		a[i+n]=a[i];
	}
//	for(int i=1;i<=n*2;i++) f[i][i]=a[i];
	a[0]=a[n];
	a[n*2+1]=a[0];
//	f[n*2][n*2+1]=a[n*2];
	for(int l=2;l<=n;l+=2)
	{
		for(int i=1;i<=n;i++)
		{
			int j=i+l-1;
	
			long long t1,t2,t3;
			t1=t2=t3=0;
			if(a[j+1]<=a[i]) 
				t1=f[i+2][j]+a[i+1];
			if(a[j+1]<=a[i])
			 	t2=f[i+1][j-1]+a[j];
			if(a[i-1]<=a[j]) 
				t2=max(t2,f[i+1][j-1]+a[i]);
			if(a[i-1]<=a[j])
				t3=f[i][j-2]+a[j-1];
			f[i][j]=max(t1,max(t2,t3));
			if(j+n<=2*n) f[i+n][j+n]=f[i][j];
		//	cout<<i<<" "<<j<<" "<<f[i][j]<<" "<<t1<<" "<<t2<<" "<<t3<<endl;
		}
	}
	long long ans=0;
	if(n%2==0)
	{
		for(long long i=1;i<=n;i++)
		{
			ans=max(ans,f[i][i+n-1]);
		}
	}
	if(n%2==1)
	{
		for(long long i=1;i<=n;i++)
		{
			ans=max(ans,f[i][i+n-2]+a[i+n-1]);
		}
	}
	printf("%lld",ans);
	return 0;
}
	 
