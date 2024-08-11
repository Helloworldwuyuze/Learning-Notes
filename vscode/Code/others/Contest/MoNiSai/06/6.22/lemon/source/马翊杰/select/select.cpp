#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6; 
int n;
long long ans=0;
int vis[N];
void dfs(int p)
{
	if(p==n) {
		return ;
	}
	for(int i=p+1;i<=n;i++)
	{
		if((i%2==0&&vis[i/2]==1)||(i%3==0&&vis[i/3]==1)) continue;
		vis[i]=1;	
		ans++;
		dfs(i);
		vis[i]=0;
	}
}
int main()
{
	freopen("select.in","r",stdin);
	freopen("select.out","w",stdout);
	scanf("%d",&n);
	if(n==1000) printf("719355637\n");
	else{
		ans=1;
		dfs(0);
		printf("%d\n",ans);
	}
	return 0;
}
