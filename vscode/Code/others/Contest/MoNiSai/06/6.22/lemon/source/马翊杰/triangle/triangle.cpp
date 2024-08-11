#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
ll n,m;
ll cnt=0,cb=0;
bool bk[2003][2003];
int main()
{
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cnt=n*(n-1)*(n-2)/6;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		bk[x][y]=1;
		bk[y][x]=1;
		for(int j=1;j<=n;j++)
		{
			if(j==x||j==y) continue;
			if(bk[x][j]!=bk[y][j]) continue;
			if(bk[x][j]==1) cb++;
			if(bk[x][j]==0) cnt--;
 		}
	}
	printf("%lld\n",cb+cnt);
	return 0;
}
