#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
int l,r,x;
int a[N];
int mi=0x3f3f3f3f,mii;
int main()
{
	freopen("zatopljenje.in","r",stdin);
	freopen("zatopljenje.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<mi)
		{
			mi=a[i],mii=i;
		}
	} 
//	cout<<mi<<" "<<mii<<endl;
	int fl=0;
	for(int i=1;i<n;i++)
	{
		if((a[i]>a[i+1]&&i>mii)||(a[i]<a[i+1]&&i<mii)) 
		{
		//	cout<<a[i]<<" "<<a[i+1]<<" "<<i<<endl;
			fl=1;
			break;
		}
	}
	if(!fl)
	{
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d%d",&l,&r,&x);
			if(l<=mii&&r<=mii)
			{
				if(a[l]-x>0) printf("1\n");
				else printf("0\n");
			}else if(l<=mii&&r>=mii)
			{
				int cnt=0;
				if(a[l]-x>0) cnt++;
				if(a[r]-x>0) cnt++;
				printf("%d\n",cnt);
			}else
			{
				if(a[r]-x>0) printf("1\n");
				else printf("0\n");
			}
		}
	}else
	{
		for(int i=1;i<=q;++i)
		{
			scanf("%d%d%d",&l,&r,&x);
			int cnt=0;
			for(int j=l;j<=r;++j)
			{
				if(a[j]-x>0&&a[j+1]-x<=0) cnt++;
				else if(j==r&&a[j]-x>0) cnt++;	
			} 
			printf("%d\n",cnt);
		}
	//	cout<<"-----"; 
	}
	return 0;
}
 

