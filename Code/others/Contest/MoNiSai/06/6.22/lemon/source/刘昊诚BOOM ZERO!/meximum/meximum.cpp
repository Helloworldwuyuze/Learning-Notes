#include<iostream>
#include<cstdio>
using namespace std;
inline int rd()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
const int N=300005;
int n,a[N],vis[N],m,ans;
int main()
{
	freopen("meximum.in","r",stdin);
	freopen("meximum.out","w",stdout);
	n=rd();
	for(int i=1;i<=n;i++)a[i]=rd(),m=max(m,a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)vis[i]=0;
		for(int j=1;j<=n-i+1;j++)
		{
			int l=i,r=i+j-1,tmp=0;
			vis[a[r]]=1;
			for(int k=1;k<=m+1;k++)if(!vis[k]){tmp=k;break;}
			ans+=tmp;
//			printf("(%d, %d): %d\n",l,r,tmp);
		}
	}
	printf("%d\n",ans);
	return 0;
}
