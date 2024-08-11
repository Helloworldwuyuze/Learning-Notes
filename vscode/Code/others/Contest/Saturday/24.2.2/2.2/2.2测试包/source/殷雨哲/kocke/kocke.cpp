#include<cstdio>
#include<algorithm>
#include<iostream>
#define mod (int)(1e9+7)
using namespace std;
long long r[2][5004],n,k;
int main()
{
	freopen("kocke.in","r",stdin);
	freopen("kocke.out","w",stdout);
	cin>>n>>k;
	for(int i=2;i<=k;i++)
	{
		r[1][i]=(i-1)*2; 
	}
	for(int j=3;j<=n;j++)
	{
		for(int i=2;i<=k;i++)
		{
			r[2][i]=(r[1][i-1]+r[1][i])%mod;
		}
		for(int i=2;i<=k;i++)
		{
			r[1][i]=r[2][i];
		}
	}
	cout<<r[1][k];
	return 0;
}
