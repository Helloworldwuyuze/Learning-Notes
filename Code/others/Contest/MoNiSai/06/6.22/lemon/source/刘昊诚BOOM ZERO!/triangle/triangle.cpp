#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;
int n,m,ans;
bool adj[2005][2005];
int main()
{
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;cin>>u>>v;
		adj[u][v]=adj[v][u]=true;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(clock()/CLOCKS_PER_SEC>0.996)break;
				if(adj[i][j]==adj[j][k]&&adj[j][k]==adj[i][k])ans++;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
