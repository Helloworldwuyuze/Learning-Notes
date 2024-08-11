#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
const int INF=0x3f3f3f3f;
int n,m;
int fa[N][20],d[N];
struct node
{
	int u,v,nxt;
	int qd=INF;
}e[N<<1];
int h[N],tot;
int ans[N];
void add(int x,int y)
{
	e[++tot].v=y;
	e[tot].u=x;
	e[tot].nxt=h[x];
	h[x]=tot;
}
void dfs(int u,int u_fa)
{
	d[u]=d[u_fa]+1;
	fa[u][0]=u_fa;
	for(int i=h[u];~i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==u_fa) continue;
		dfs(v,u);
	}
}
void fa_fa()
{
	for(int i=1;i<=19;i++)
	{
		for(int j=1;j<=n;j++)
		{
			fa[i][j]=fa[fa[i][j-1]][j-1];	
		}	
	}	
}
int lca(int x,int y)
{
	if(d[x]<d[y]) swap(x,y);
//	cout<<x<<" "<<y<<endl;
	for(int i=19;i>=0;i--)
	{
		if(d[fa[x][i]]>=d[y])
		{
			x=fa[x][i];
			//cout<<x<<endl;
		}
	}
//	cout<<x<<" "<<y<<endl;
	if(x==y) return x;
	for(int i=19;i>0;i--)
	{
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		//	cout<<x<<" "<<y<<endl;
		}
	}
	return fa[x][0];
}
void xg(int v1,int v2,int v3,int k)
{
	int v;
	if(v1!=v3)
	{
		v=v1;
		while(v!=v3)
		{
		//	cout<<v<<endl;
			if(v==v3) break;
		//	cout<<v<<" "<<fa[v][0]<<endl;
		//	e[h[v]].qd=min(e[h[v]].qd,k);
			ans[v]=min(ans[v],k);
			v=fa[v][0];
		//	e[h[v]].qd=min(e[h[v]].qd,k);
		}
	}
	if(v2!=v3)
	{
		v=v2;
		while(v!=v3)
		{
			if(v==v3) break;
		//	cout<<v<<" "<<fa[v][0]<<endl;
		//	mp[v][fa[v][0]]=min(mp[v][fa[v][0]],k);
			ans[v]=min(ans[v],k);
			v=fa[v][0];
		}
	}
}

int main()
{
	freopen("disruption.in","r",stdin);
	freopen("disruption.out","w",stdout);
	memset(h,-1,sizeof h);
	scanf("%d%d",&n,&m);
	memset(ans,0x3f,sizeof ans);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);	
	//	cout<<tot<<endl;
		//mp[u][v]=mp[v][u]=INF;
	}
	dfs(1,0);
	fa_fa();
	int lc;
	for(int i=1;i<=m;i++)
	{
		int v1,v2,r;
		scanf("%d%d%d",&v1,&v2,&r);
		lc=lca(v1,v2);
	//	cout<<lc<<endl;
		xg(v1,v2,lc,r);
	}
	for(int i=1;i<n;i++)
	{
		int u1=e[i*2].u,u2=e[i*2].v;
		int t;
		if(d[u1]<d[u2]) t=ans[u2];
		else t=ans[u1];
		if(t==INF) t=-1;
		printf("%d\n",t);
	}
	return 0;
}

