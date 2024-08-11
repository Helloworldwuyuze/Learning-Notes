#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=19260817;
int n,m;
int a[N];
int b[N];
int tra[N],trb[N];
int lans;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int opt,l,r,v;
		int ans=0;
		scanf("%d%d%d",&opt,&l,&r);
		l^=lans,r^=lans;
		if(opt==3||opt==2) scanf("%d",&v),v^=lans;
	//	cout<<lans<<" "<<l<<" "<<r<<" "<<v<<endl;
		if(opt==1)
		{
			for(int j=l;j<=r;++j) 
			{
				ans+=a[j];
				if(ans>mod) ans%=mod; 
			}
			printf("%d\n",ans);
			lans=ans;
		}else if(opt==2)
		{
			for(int j=l;j<=r;++j)
			{
				a[j]+=v;
				if(a[j]>mod) a[j]%=mod;
			} 
	    } 
		else if(opt==3) 
		{
			for(int j=l;j<=r;++j)
			{
				b[j]+=v;
				if(b[j]>mod) b[j]%=mod;
			} 
		}
		else if(opt==4)
		{
			for(int j=l;j<=r;++j){
				a[j]+=b[j];
			} 
		} 
	/*	cout<<"A:"<<endl;
		for(int j=1;j<=n;j++) cout<<a[j]<<" ";
		cout<<endl;
		cout<<"B:"<<endl;
		for(int j=1;j<=n;j++) cout<<b[j]<<" ";
		cout<<endl;*/ 
	}
	return 0;
}
