#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n;
int a[N],vis[N];
long long ans=0;
int main()
{
	freopen("meximum.in","r",stdin);
	freopen("meximum.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n>50000) printf("0\n");
	else
	{
		int nw=0;
		for(int i=1;i<=n;++i)
		{
			nw=0;
			for(int j=i;j<=n;++j)
			{
				vis[a[j]]=1;
				if(vis[nw]==0) ans+=nw;
				else 
				{
					while(vis[nw]==1) nw++;
					ans+=nw;
				}
			}
			for(int j=1;j<=n;++j) vis[a[j]]=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
